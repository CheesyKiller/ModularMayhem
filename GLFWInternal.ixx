export module GLFWInternal;

//========================================================================
// GLFW 3.4 - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2006-2019 Camilla Löwy <elmindreda@glfw.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

export import GLFWInternalCore;
export import GLFWInternalEGL;
export import GLFWInternalOSMesa;

export import GLAD;

#include "platform.h"

#define GLFW_NATIVE_INCLUDE_NONE
#include "../include/GLFW/glfw3native.h"

// Checks for whether the library has been initialized
#define _GLFW_REQUIRE_INIT()                         \
    if (!_glfw.initialized)                          \
    {                                                \
        _glfwInputError(GLFW_NOT_INITIALIZED, NULL); \
        return;                                      \
    }
#define _GLFW_REQUIRE_INIT_OR_RETURN(x)              \
    if (!_glfw.initialized)                          \
    {                                                \
        _glfwInputError(GLFW_NOT_INITIALIZED, NULL); \
        return x;                                    \
    }

// Swaps the provided pointers
#define _GLFW_SWAP(type, x, y) \
    {                          \
        type t;                \
        t = x;                 \
        x = y;                 \
        y = t;                 \
    }

// Per-thread error structure
//
struct _GLFWerror
{
    _GLFWerror*     next;
    int             code;
    char            description[_GLFW_MESSAGE_SIZE];
};

// Initialization configuration
//
// Parameters relating to the initialization of the library
//
struct _GLFWinitconfig
{
    GLFWbool      hatButtons;
    int           angleType;
    int           platformID;
    PFN_vkGetInstanceProcAddr vulkanLoader;
    struct {
        GLFWbool  menubar;
        GLFWbool  chdir;
    } ns;
    struct {
        GLFWbool  xcbVulkanSurface;
    } x11;
    struct {
        int       libdecorMode;
    } wl;
};

// Window configuration
//
// Parameters relating to the creation of the window but not directly related
// to the framebuffer.  This is used to pass window creation parameters from
// shared code to the platform API.
//
struct _GLFWwndconfig
{
    int           xpos;
    int           ypos;
    int           width;
    int           height;
    const char*   title;
    GLFWbool      resizable;
    GLFWbool      visible;
    GLFWbool      decorated;
    GLFWbool      focused;
    GLFWbool      autoIconify;
    GLFWbool      floating;
    GLFWbool      maximized;
    GLFWbool      centerCursor;
    GLFWbool      focusOnShow;
    GLFWbool      mousePassthrough;
    GLFWbool      scaleToMonitor;
    GLFWbool      scaleFramebuffer;
    struct {
        char      frameName[256];
    } ns;
    struct {
        char      className[256];
        char      instanceName[256];
    } x11;
    struct {
        GLFWbool  keymenu;
        GLFWbool  showDefault;
    } win32;
    struct {
        char      appId[256];
    } wl;
};

// Context configuration
//
// Parameters relating to the creation of the context but not directly related
// to the framebuffer.  This is used to pass context creation parameters from
// shared code to the platform API.
//
struct _GLFWctxconfig
{
    int           client;
    int           source;
    int           major;
    int           minor;
    GLFWbool      forward;
    GLFWbool      debug;
    GLFWbool      noerror;
    int           profile;
    int           robustness;
    int           release;
    _GLFWwindow*  share;
    struct {
        GLFWbool  offline;
    } nsgl;
};

// Framebuffer configuration
//
// This describes buffers and their sizes.  It also contains
// a platform-specific ID used to map back to the backend API object.
//
// It is used to pass framebuffer parameters from shared code to the platform
// API and also to enumerate and select available framebuffer configs.
//
struct _GLFWfbconfig
{
    int         redBits;
    int         greenBits;
    int         blueBits;
    int         alphaBits;
    int         depthBits;
    int         stencilBits;
    int         accumRedBits;
    int         accumGreenBits;
    int         accumBlueBits;
    int         accumAlphaBits;
    int         auxBuffers;
    GLFWbool    stereo;
    int         samples;
    GLFWbool    sRGB;
    GLFWbool    doublebuffer;
    GLFWbool    transparent;
    uintptr_t   handle;
};

// Context structure
//
struct _GLFWcontext
{
    int                 client;
    int                 source;
    int                 major, minor, revision;
    GLFWbool            forward, debug, noerror;
    int                 profile;
    int                 robustness;
    int                 release;

    PFNGLGETSTRINGIPROC  GetStringi;
    PFNGLGETINTEGERVPROC GetIntegerv;
    PFNGLGETSTRINGPROC   GetString;

    void (*makeCurrent)(_GLFWwindow*);
    void (*swapBuffers)(_GLFWwindow*);
    void (*swapInterval)(int);
    int (*extensionSupported)(const char*);
    GLFWglproc (*getProcAddress)(const char*);
    void (*destroy)(_GLFWwindow*);

    struct {
        EGLConfig       config;
        EGLContext      handle;
        EGLSurface      surface;
        void*           client;
    } egl;

    struct {
        OSMesaContext   handle;
        int             width;
        int             height;
        void*           buffer;
    } osmesa;

    // This is defined in platform.h
    GLFW_PLATFORM_CONTEXT_STATE
};

// Window and context structure
//
struct _GLFWwindow
{
    struct _GLFWwindow* next;

    // Window settings and state
    GLFWbool            resizable;
    GLFWbool            decorated;
    GLFWbool            autoIconify;
    GLFWbool            floating;
    GLFWbool            focusOnShow;
    GLFWbool            mousePassthrough;
    GLFWbool            shouldClose;
    void*               userPointer;
    GLFWbool            doublebuffer;
    GLFWvidmode         videoMode;
    _GLFWmonitor*       monitor;
    _GLFWcursor*        cursor;
    char*               title;

    int                 minwidth, minheight;
    int                 maxwidth, maxheight;
    int                 numer, denom;

    GLFWbool            stickyKeys;
    GLFWbool            stickyMouseButtons;
    GLFWbool            lockKeyMods;
    int                 cursorMode;
    char                mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1];
    char                keys[GLFW_KEY_LAST + 1];
    // Virtual cursor position when cursor is disabled
    double              virtualCursorPosX, virtualCursorPosY;
    GLFWbool            rawMouseMotion;

    _GLFWcontext        context;

    struct {
        GLFWwindowposfun          pos;
        GLFWwindowsizefun         size;
        GLFWwindowclosefun        close;
        GLFWwindowrefreshfun      refresh;
        GLFWwindowfocusfun        focus;
        GLFWwindowiconifyfun      iconify;
        GLFWwindowmaximizefun     maximize;
        GLFWframebuffersizefun    fbsize;
        GLFWwindowcontentscalefun scale;
        GLFWmousebuttonfun        mouseButton;
        GLFWcursorposfun          cursorPos;
        GLFWcursorenterfun        cursorEnter;
        GLFWscrollfun             scroll;
        GLFWkeyfun                key;
        GLFWcharfun               character;
        GLFWcharmodsfun           charmods;
        GLFWdropfun               drop;
    } callbacks;

    // This is defined in platform.h
    GLFW_PLATFORM_WINDOW_STATE
};

// Monitor structure
//
struct _GLFWmonitor
{
    char            name[128];
    void*           userPointer;

    // Physical dimensions in millimeters.
    int             widthMM, heightMM;

    // The window whose video mode is current on this monitor
    _GLFWwindow*    window;

    GLFWvidmode*    modes;
    int             modeCount;
    GLFWvidmode     currentMode;

    GLFWgammaramp   originalRamp;
    GLFWgammaramp   currentRamp;

    // This is defined in platform.h
    GLFW_PLATFORM_MONITOR_STATE
};

// Cursor structure
//
struct _GLFWcursor
{
    _GLFWcursor*    next;
    // This is defined in platform.h
    GLFW_PLATFORM_CURSOR_STATE
};

// Gamepad mapping element structure
//
struct _GLFWmapelement
{
    uint8_t         type;
    uint8_t         index;
    int8_t          axisScale;
    int8_t          axisOffset;
};

// Gamepad mapping structure
//
struct _GLFWmapping
{
    char            name[128];
    char            guid[33];
    _GLFWmapelement buttons[15];
    _GLFWmapelement axes[6];
};

// Joystick structure
//
struct _GLFWjoystick
{
    GLFWbool        allocated;
    GLFWbool        connected;
    float*          axes;
    int             axisCount;
    unsigned char*  buttons;
    int             buttonCount;
    unsigned char*  hats;
    int             hatCount;
    char            name[128];
    void*           userPointer;
    char            guid[33];
    _GLFWmapping*   mapping;

    // This is defined in platform.h
    GLFW_PLATFORM_JOYSTICK_STATE
};

// Thread local storage structure
//
struct _GLFWtls
{
    // This is defined in platform.h
    GLFW_PLATFORM_TLS_STATE
};

// Mutex structure
//
struct _GLFWmutex
{
    // This is defined in platform.h
    GLFW_PLATFORM_MUTEX_STATE
};

// Platform API structure
//
struct _GLFWplatform
{
    int platformID;
    // init
    GLFWbool (*init)(void);
    void (*terminate)(void);
    // input
    void (*getCursorPos)(_GLFWwindow*,double*,double*);
    void (*setCursorPos)(_GLFWwindow*,double,double);
    void (*setCursorMode)(_GLFWwindow*,int);
    void (*setRawMouseMotion)(_GLFWwindow*,GLFWbool);
    GLFWbool (*rawMouseMotionSupported)(void);
    GLFWbool (*createCursor)(_GLFWcursor*,const GLFWimage*,int,int);
    GLFWbool (*createStandardCursor)(_GLFWcursor*,int);
    void (*destroyCursor)(_GLFWcursor*);
    void (*setCursor)(_GLFWwindow*,_GLFWcursor*);
    const char* (*getScancodeName)(int);
    int (*getKeyScancode)(int);
    void (*setClipboardString)(const char*);
    const char* (*getClipboardString)(void);
    GLFWbool (*initJoysticks)(void);
    void (*terminateJoysticks)(void);
    GLFWbool (*pollJoystick)(_GLFWjoystick*,int);
    const char* (*getMappingName)(void);
    void (*updateGamepadGUID)(char*);
    // monitor
    void (*freeMonitor)(_GLFWmonitor*);
    void (*getMonitorPos)(_GLFWmonitor*,int*,int*);
    void (*getMonitorContentScale)(_GLFWmonitor*,float*,float*);
    void (*getMonitorWorkarea)(_GLFWmonitor*,int*,int*,int*,int*);
    GLFWvidmode* (*getVideoModes)(_GLFWmonitor*,int*);
    GLFWbool (*getVideoMode)(_GLFWmonitor*,GLFWvidmode*);
    GLFWbool (*getGammaRamp)(_GLFWmonitor*,GLFWgammaramp*);
    void (*setGammaRamp)(_GLFWmonitor*,const GLFWgammaramp*);
    // window
    GLFWbool (*createWindow)(_GLFWwindow*,const _GLFWwndconfig*,const _GLFWctxconfig*,const _GLFWfbconfig*);
    void (*destroyWindow)(_GLFWwindow*);
    void (*setWindowTitle)(_GLFWwindow*,const char*);
    void (*setWindowIcon)(_GLFWwindow*,int,const GLFWimage*);
    void (*getWindowPos)(_GLFWwindow*,int*,int*);
    void (*setWindowPos)(_GLFWwindow*,int,int);
    void (*getWindowSize)(_GLFWwindow*,int*,int*);
    void (*setWindowSize)(_GLFWwindow*,int,int);
    void (*setWindowSizeLimits)(_GLFWwindow*,int,int,int,int);
    void (*setWindowAspectRatio)(_GLFWwindow*,int,int);
    void (*getFramebufferSize)(_GLFWwindow*,int*,int*);
    void (*getWindowFrameSize)(_GLFWwindow*,int*,int*,int*,int*);
    void (*getWindowContentScale)(_GLFWwindow*,float*,float*);
    void (*iconifyWindow)(_GLFWwindow*);
    void (*restoreWindow)(_GLFWwindow*);
    void (*maximizeWindow)(_GLFWwindow*);
    void (*showWindow)(_GLFWwindow*);
    void (*hideWindow)(_GLFWwindow*);
    void (*requestWindowAttention)(_GLFWwindow*);
    void (*focusWindow)(_GLFWwindow*);
    void (*setWindowMonitor)(_GLFWwindow*,_GLFWmonitor*,int,int,int,int,int);
    GLFWbool (*windowFocused)(_GLFWwindow*);
    GLFWbool (*windowIconified)(_GLFWwindow*);
    GLFWbool (*windowVisible)(_GLFWwindow*);
    GLFWbool (*windowMaximized)(_GLFWwindow*);
    GLFWbool (*windowHovered)(_GLFWwindow*);
    GLFWbool (*framebufferTransparent)(_GLFWwindow*);
    float (*getWindowOpacity)(_GLFWwindow*);
    void (*setWindowResizable)(_GLFWwindow*,GLFWbool);
    void (*setWindowDecorated)(_GLFWwindow*,GLFWbool);
    void (*setWindowFloating)(_GLFWwindow*,GLFWbool);
    void (*setWindowOpacity)(_GLFWwindow*,float);
    void (*setWindowMousePassthrough)(_GLFWwindow*,GLFWbool);
    void (*pollEvents)(void);
    void (*waitEvents)(void);
    void (*waitEventsTimeout)(double);
    void (*postEmptyEvent)(void);
    // EGL
    EGLenum (*getEGLPlatform)(EGLint**);
    EGLNativeDisplayType (*getEGLNativeDisplay)(void);
    EGLNativeWindowType (*getEGLNativeWindow)(_GLFWwindow*);
    // vulkan
    void (*getRequiredInstanceExtensions)(char**);
    GLFWbool (*getPhysicalDevicePresentationSupport)(VkInstance,VkPhysicalDevice,uint32_t);
    VkResult (*createWindowSurface)(VkInstance,_GLFWwindow*,const VkAllocationCallbacks*,VkSurfaceKHR*);
};

// Library global data
//
struct _GLFWlibrary
{
    GLFWbool            initialized;
    GLFWallocator       allocator;

    _GLFWplatform       platform;

    struct {
        _GLFWinitconfig init;
        _GLFWfbconfig   framebuffer;
        _GLFWwndconfig  window;
        _GLFWctxconfig  context;
        int             refreshRate;
    } hints;

    _GLFWerror*         errorListHead;
    _GLFWcursor*        cursorListHead;
    _GLFWwindow*        windowListHead;

    _GLFWmonitor**      monitors;
    int                 monitorCount;

    GLFWbool            joysticksInitialized;
    _GLFWjoystick       joysticks[GLFW_JOYSTICK_LAST + 1];
    _GLFWmapping*       mappings;
    int                 mappingCount;

    _GLFWtls            errorSlot;
    _GLFWtls            contextSlot;
    _GLFWmutex          errorLock;

    struct {
        uint64_t        offset;
        // This is defined in platform.h
        GLFW_PLATFORM_LIBRARY_TIMER_STATE
    } timer;

    struct {
        EGLenum         platform;
        EGLDisplay      display;
        EGLint          major, minor;
        GLFWbool        prefix;

        GLFWbool        KHR_create_context;
        GLFWbool        KHR_create_context_no_error;
        GLFWbool        KHR_gl_colorspace;
        GLFWbool        KHR_get_all_proc_addresses;
        GLFWbool        KHR_context_flush_control;
        GLFWbool        EXT_client_extensions;
        GLFWbool        EXT_platform_base;
        GLFWbool        EXT_platform_x11;
        GLFWbool        EXT_platform_wayland;
        GLFWbool        EXT_present_opaque;
        GLFWbool        ANGLE_platform_angle;
        GLFWbool        ANGLE_platform_angle_opengl;
        GLFWbool        ANGLE_platform_angle_d3d;
        GLFWbool        ANGLE_platform_angle_vulkan;
        GLFWbool        ANGLE_platform_angle_metal;

        void*           handle;

        PFN_eglGetConfigAttrib      GetConfigAttrib;
        PFN_eglGetConfigs           GetConfigs;
        PFN_eglGetDisplay           GetDisplay;
        PFN_eglGetError             GetError;
        PFN_eglInitialize           Initialize;
        PFN_eglTerminate            Terminate;
        PFN_eglBindAPI              BindAPI;
        PFN_eglCreateContext        CreateContext;
        PFN_eglDestroySurface       DestroySurface;
        PFN_eglDestroyContext       DestroyContext;
        PFN_eglCreateWindowSurface  CreateWindowSurface;
        PFN_eglMakeCurrent          MakeCurrent;
        PFN_eglSwapBuffers          SwapBuffers;
        PFN_eglSwapInterval         SwapInterval;
        PFN_eglQueryString          QueryString;
        PFN_eglGetProcAddress       GetProcAddress;

        PFNEGLGETPLATFORMDISPLAYEXTPROC GetPlatformDisplayEXT;
        PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC CreatePlatformWindowSurfaceEXT;
    } egl;

    struct {
        void*           handle;

        PFN_OSMesaCreateContextExt      CreateContextExt;
        PFN_OSMesaCreateContextAttribs  CreateContextAttribs;
        PFN_OSMesaDestroyContext        DestroyContext;
        PFN_OSMesaMakeCurrent           MakeCurrent;
        PFN_OSMesaGetColorBuffer        GetColorBuffer;
        PFN_OSMesaGetDepthBuffer        GetDepthBuffer;
        PFN_OSMesaGetProcAddress        GetProcAddress;

    } osmesa;

    struct {
        GLFWbool        available;
        void*           handle;
        char*           extensions[2];
        PFN_vkGetInstanceProcAddr GetInstanceProcAddr;
        GLFWbool        KHR_surface;
        GLFWbool        KHR_win32_surface;
        GLFWbool        MVK_macos_surface;
        GLFWbool        EXT_metal_surface;
        GLFWbool        KHR_xlib_surface;
        GLFWbool        KHR_xcb_surface;
        GLFWbool        KHR_wayland_surface;
    } vk;

    struct {
        GLFWmonitorfun  monitor;
        GLFWjoystickfun joystick;
    } callbacks;

    // These are defined in platform.h
    GLFW_PLATFORM_LIBRARY_WINDOW_STATE
    GLFW_PLATFORM_LIBRARY_CONTEXT_STATE
    GLFW_PLATFORM_LIBRARY_JOYSTICK_STATE
};

// Global state shared between compilation units of GLFW
//
extern _GLFWlibrary _glfw;


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

void _glfwPlatformInitTimer(void);
uint64_t _glfwPlatformGetTimerValue(void);
uint64_t _glfwPlatformGetTimerFrequency(void);

GLFWbool _glfwPlatformCreateTls(_GLFWtls* tls);
void _glfwPlatformDestroyTls(_GLFWtls* tls);
void* _glfwPlatformGetTls(_GLFWtls* tls);
void _glfwPlatformSetTls(_GLFWtls* tls, void* value);

GLFWbool _glfwPlatformCreateMutex(_GLFWmutex* mutex);
void _glfwPlatformDestroyMutex(_GLFWmutex* mutex);
void _glfwPlatformLockMutex(_GLFWmutex* mutex);
void _glfwPlatformUnlockMutex(_GLFWmutex* mutex);

void* _glfwPlatformLoadModule(const char* path);
void _glfwPlatformFreeModule(void* module);
GLFWproc _glfwPlatformGetModuleSymbol(void* module, const char* name);


//////////////////////////////////////////////////////////////////////////
//////                         GLFW event API                       //////
//////////////////////////////////////////////////////////////////////////

void _glfwInputWindowFocus(_GLFWwindow* window, GLFWbool focused);
void _glfwInputWindowPos(_GLFWwindow* window, int xpos, int ypos);
void _glfwInputWindowSize(_GLFWwindow* window, int width, int height);
void _glfwInputFramebufferSize(_GLFWwindow* window, int width, int height);
void _glfwInputWindowContentScale(_GLFWwindow* window,
                                  float xscale, float yscale);
void _glfwInputWindowIconify(_GLFWwindow* window, GLFWbool iconified);
void _glfwInputWindowMaximize(_GLFWwindow* window, GLFWbool maximized);
void _glfwInputWindowDamage(_GLFWwindow* window);
void _glfwInputWindowCloseRequest(_GLFWwindow* window);
void _glfwInputWindowMonitor(_GLFWwindow* window, _GLFWmonitor* monitor);

void _glfwInputKey(_GLFWwindow* window,
                   int key, int scancode, int action, int mods);
void _glfwInputChar(_GLFWwindow* window,
                    uint32_t codepoint, int mods, GLFWbool plain);
void _glfwInputScroll(_GLFWwindow* window, double xoffset, double yoffset);
void _glfwInputMouseClick(_GLFWwindow* window, int button, int action, int mods);
void _glfwInputCursorPos(_GLFWwindow* window, double xpos, double ypos);
void _glfwInputCursorEnter(_GLFWwindow* window, GLFWbool entered);
void _glfwInputDrop(_GLFWwindow* window, int count, const char** names);
void _glfwInputJoystick(_GLFWjoystick* js, int event);
void _glfwInputJoystickAxis(_GLFWjoystick* js, int axis, float value);
void _glfwInputJoystickButton(_GLFWjoystick* js, int button, char value);
void _glfwInputJoystickHat(_GLFWjoystick* js, int hat, char value);

void _glfwInputMonitor(_GLFWmonitor* monitor, int action, int placement);
void _glfwInputMonitorWindow(_GLFWmonitor* monitor, _GLFWwindow* window);

#if defined(__GNUC__)
void _glfwInputError(int code, const char* format, ...)
    __attribute__((format(printf, 2, 3)));
#else
void _glfwInputError(int code, const char* format, ...);
#endif


//////////////////////////////////////////////////////////////////////////
//////                       GLFW internal API                      //////
//////////////////////////////////////////////////////////////////////////

GLFWbool _glfwSelectPlatform(int platformID, _GLFWplatform* platform);

GLFWbool _glfwStringInExtensionString(const char* string, const char* extensions);
const _GLFWfbconfig* _glfwChooseFBConfig(const _GLFWfbconfig* desired,
                                         const _GLFWfbconfig* alternatives,
                                         unsigned int count);
GLFWbool _glfwRefreshContextAttribs(_GLFWwindow* window,
                                    const _GLFWctxconfig* ctxconfig);
GLFWbool _glfwIsValidContextConfig(const _GLFWctxconfig* ctxconfig);

const GLFWvidmode* _glfwChooseVideoMode(_GLFWmonitor* monitor,
                                        const GLFWvidmode* desired);
int _glfwCompareVideoModes(const GLFWvidmode* first, const GLFWvidmode* second);
_GLFWmonitor* _glfwAllocMonitor(const char* name, int widthMM, int heightMM);
void _glfwFreeMonitor(_GLFWmonitor* monitor);
void _glfwAllocGammaArrays(GLFWgammaramp* ramp, unsigned int size);
void _glfwFreeGammaArrays(GLFWgammaramp* ramp);
void _glfwSplitBPP(int bpp, int* red, int* green, int* blue);

void _glfwInitGamepadMappings(void);
_GLFWjoystick* _glfwAllocJoystick(const char* name,
                                  const char* guid,
                                  int axisCount,
                                  int buttonCount,
                                  int hatCount);
void _glfwFreeJoystick(_GLFWjoystick* js);
void _glfwCenterCursorInContentArea(_GLFWwindow* window);

GLFWbool _glfwInitEGL(void);
void _glfwTerminateEGL(void);
GLFWbool _glfwCreateContextEGL(_GLFWwindow* window,
                               const _GLFWctxconfig* ctxconfig,
                               const _GLFWfbconfig* fbconfig);
#if defined(_GLFW_X11)
GLFWbool _glfwChooseVisualEGL(const _GLFWwndconfig* wndconfig,
                              const _GLFWctxconfig* ctxconfig,
                              const _GLFWfbconfig* fbconfig,
                              Visual** visual, int* depth);
#endif /*_GLFW_X11*/

GLFWbool _glfwInitOSMesa(void);
void _glfwTerminateOSMesa(void);
GLFWbool _glfwCreateContextOSMesa(_GLFWwindow* window,
                                  const _GLFWctxconfig* ctxconfig,
                                  const _GLFWfbconfig* fbconfig);

GLFWbool _glfwInitVulkan(int mode);
void _glfwTerminateVulkan(void);
const char* _glfwGetVulkanResultString(VkResult result);

size_t _glfwEncodeUTF8(char* s, uint32_t codepoint);
char** _glfwParseUriList(char* text, int* count);

char* _glfw_strdup(const char* source);
int _glfw_min(int a, int b);
int _glfw_max(int a, int b);

void* _glfw_calloc(size_t count, size_t size);
void* _glfw_realloc(void* pointer, size_t size);
void _glfw_free(void* pointer);

