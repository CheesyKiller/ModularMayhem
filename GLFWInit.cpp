import GLFWInit;

#include <cstdlib>  // For malloc, free, realloc
#include <cstdio>   // For printf
#include <cstdarg>  // For va_list, va_start, va_end
#include <cstring>  // For memset, strcpy
#include <memory>   // For smart pointers (shared_ptr, unique_ptr)
import GLFWInternal;  // Internal GLFW structures and types

// Global variables
std::shared_ptr<_GLFWlibrary> _glfw = std::make_shared<_GLFWlibrary>();
static _GLFWerror _glfwMainThreadError;
static std::shared_ptr<GLFWerrorfun> _glfwErrorCallback;
static GLFWallocator _glfwInitAllocator;
static _GLFWinitconfig _glfwInitHints =
{
    .hatButtons = GLFW_TRUE,
    .angleType = GLFW_ANGLE_PLATFORM_TYPE_NONE,
    .platformID = GLFW_ANY_PLATFORM,
    .vulkanLoader = nullptr,
    .ns =
    {
        .menubar = GLFW_TRUE,
        .chdir = GLFW_TRUE
    },
    .x11 =
    {
        .xcbVulkanSurface = GLFW_TRUE,
    },
    .wl =
    {
        .libdecorMode = GLFW_WAYLAND_PREFER_LIBDECOR
    },
};

// Default allocation functions (if no custom allocator is set)
static std::shared_ptr<void> defaultAllocate(size_t size, void* user)
{
    return std::shared_ptr<void>(std::malloc(size), std::free);
}

static void defaultDeallocate(void* block, void* user)
{
    std::free(block);
}

static void* defaultReallocate(void* block, size_t size, void* user)
{
    return std::realloc(block, size);
}

// Internal function to terminate GLFW
static void terminate()
{
    memset(&_glfw->callbacks, 0, sizeof(_glfw->callbacks));

    while (_glfw->windowListHead)
        glfwDestroyWindow(static_cast<GLFWwindow*>(_glfw->windowListHead.get()));

    while (_glfw->cursorListHead)
        glfwDestroyCursor(static_cast<GLFWcursor*>(_glfw->cursorListHead.get()));

    for (int i = 0; i < _glfw->monitorCount; ++i)
    {
        auto monitor = _glfw->monitors[i];
        if (monitor->originalRamp.size)
            _glfw->platform.setGammaRamp(monitor.get(), &monitor->originalRamp);
        _glfwFreeMonitor(monitor);
    }

    _glfw_free(_glfw->monitors);
    _glfw->monitors = nullptr;
    _glfw->monitorCount = 0;

    _glfw_free(_glfw->mappings);
    _glfw->mappings = nullptr;
    _glfw->mappingCount = 0;

    _glfwTerminateVulkan();
    _glfw->platform.terminateJoysticks();
    _glfw->platform.terminate();

    _glfw->initialized = GLFW_FALSE;

    while (_glfw->errorListHead)
    {
        auto error = _glfw->errorListHead;
        _glfw->errorListHead = error->next;
        _glfw_free(error);
    }

    _glfwPlatformDestroyTls(&_glfw->contextSlot);
    _glfwPlatformDestroyTls(&_glfw->errorSlot);
    _glfwPlatformDestroyMutex(&_glfw->errorLock);

    memset(_glfw.get(), 0, sizeof(_glfw));
}

//////////////////////////////////////////////////////////////////////////
//////                        GLFW public API                       //////
//////////////////////////////////////////////////////////////////////////

int glfwInit(void)
{
    if (_glfw->initialized)
        return GLFW_TRUE;

    memset(_glfw.get(), 0, sizeof(_glfw));
    _glfw->hints.init = _glfwInitHints;

    _glfw->allocator = _glfwInitAllocator;
    if (!_glfw->allocator.allocate)
    {
        _glfw->allocator.allocate = defaultAllocate;
        _glfw->allocator.reallocate = defaultReallocate;
        _glfw->allocator.deallocate = defaultDeallocate;
    }

    if (!_glfwSelectPlatform(_glfw->hints.init.platformID, &_glfw->platform))
        return GLFW_FALSE;

    if (!_glfw->platform.init())
    {
        terminate();
        return GLFW_FALSE;
    }

    if (!_glfwPlatformCreateMutex(&_glfw->errorLock) ||
        !_glfwPlatformCreateTls(&_glfw->errorSlot) ||
        !_glfwPlatformCreateTls(&_glfw->contextSlot))
    {
        terminate();
        return GLFW_FALSE;
    }

    _glfwPlatformSetTls(&_glfw->errorSlot, &_glfwMainThreadError);
    _glfwInitGamepadMappings();
    _glfwPlatformInitTimer();
    _glfw->timer.offset = _glfwPlatformGetTimerValue();

    _glfw->initialized = GLFW_TRUE;

    glfwDefaultWindowHints();
    return GLFW_TRUE;
}

void glfwTerminate(void)
{
    if (!_glfw->initialized)
        return;

    terminate();
}

void glfwInitHint(int hint, int value)
{
    switch (hint)
    {
    case GLFW_JOYSTICK_HAT_BUTTONS:
        _glfwInitHints.hatButtons = value;
        return;
    case GLFW_ANGLE_PLATFORM_TYPE:
        _glfwInitHints.angleType = value;
        return;
    case GLFW_PLATFORM:
        _glfwInitHints.platformID = value;
        return;
    case GLFW_COCOA_CHDIR_RESOURCES:
        _glfwInitHints.ns.chdir = value;
        return;
    case GLFW_COCOA_MENUBAR:
        _glfwInitHints.ns.menubar = value;
        return;
    case GLFW_X11_XCB_VULKAN_SURFACE:
        _glfwInitHints.x11.xcbVulkanSurface = value;
        return;
    case GLFW_WAYLAND_LIBDECOR:
        _glfwInitHints.wl.libdecorMode = value;
        return;
    }

    _glfwInputError(GLFW_INVALID_ENUM,
        "Invalid init hint 0x%08X", hint);
}

void glfwInitAllocator(const GLFWallocator* allocator)
{
    if (allocator)
    {
        if (allocator->allocate && allocator->reallocate && allocator->deallocate)
            _glfwInitAllocator = *allocator;
        else
            _glfwInputError(GLFW_INVALID_VALUE, "Missing function in allocator");
    }
    else
        memset(&_glfwInitAllocator, 0, sizeof(GLFWallocator));
}

void glfwGetVersion(int* major, int* minor, int* rev)
{
    if (major != nullptr)
        *major = GLFW_VERSION_MAJOR;
    if (minor != nullptr)
        *minor = GLFW_VERSION_MINOR;
    if (rev != nullptr)
        *rev = GLFW_VERSION_REVISION;
}

int glfwGetError(const char** description)
{
    _GLFWerror* error;
    int code = GLFW_NO_ERROR;

    if (description)
        *description = nullptr;

    if (_glfw->initialized)
        error = _glfwPlatformGetTls(&_glfw->errorSlot);
    else
        error = &_glfwMainThreadError;

    if (error)
    {
        code = error->code;
        error->code = GLFW_NO_ERROR;
        if (description && code)
            *description = error->description;
    }

    return code;
}

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun cbfun)
{
    _GLFW_SWAP(GLFWerrorfun, *_glfwErrorCallback, cbfun);
    return cbfun;
}

#if defined(VK_VERSION_1_0)
void glfwInitVulkanLoader(PFN_vkGetInstanceProcAddr loader)
{
    _glfwInitHints.vulkanLoader = loader;
}
#endif /* VK_VERSION_1_0 */