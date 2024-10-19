#include <gl/GL.h>

import <cstddef>;

import GLAD;

static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;

static void* get_proc(const char* namez);

#if defined(_WIN32) || defined(__CYGWIN__)
#ifndef _WINDOWS_
#undef APIENTRY
#endif
#include <windows.h>
static HMODULE libGL;

#ifdef _MSC_VER
#ifdef __has_include
#if __has_include(<winapifamily.h>)
#define HAVE_WINAPIFAMILY 1
#endif
#elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#define HAVE_WINAPIFAMILY 1
#endif
#endif

#ifdef HAVE_WINAPIFAMILY
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define IS_UWP 1
#endif
#endif

static int open_gl(void) {
#ifndef IS_UWP
    libGL = LoadLibraryW(L"opengl32.dll");
    if (libGL != NULL) {
        void (*tmp)(void);
        tmp = (void(*)(void)) GetProcAddress(libGL, "wglGetProcAddress");
        gladGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return gladGetProcAddressPtr != NULL;
    }
#endif

    return 0;
}

static
void close_gl(void) {
    if (libGL != NULL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#include <dlfcn.h>
static void* libGL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
typedef void* (APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
#endif

static
int open_gl(void) {
#ifdef __APPLE__
    static const char* NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#else
    static const char* NAMES[] = { "libGL.so.1", "libGL.so" };
#endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL);

        if (libGL != NULL) {
#if defined(__APPLE__) || defined(__HAIKU__)
            return 1;
#else
            gladGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL,
                "glXGetProcAddressARB");
            return gladGetProcAddressPtr != NULL;
#endif
        }
    }

    return 0;
}

static
void close_gl(void) {
    if (libGL != NULL) {
        dlclose(libGL);
        libGL = NULL;
    }
}
#endif

static
void* get_proc(const char* namez) {
    void* result = NULL;
    if (libGL == NULL) return NULL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
    if (gladGetProcAddressPtr != NULL) {
        result = gladGetProcAddressPtr(namez);
    }
#endif
    if (result == NULL) {
#if defined(_WIN32) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}

int gladLoadGL(void) {
    int status = 0;

    if (open_gl()) {
        status = gladLoadGLLoader(&get_proc);
        close_gl();
    }

    return status;
}

int gladLoadGLLoader(GLADloadproc load) {
	gladLoadGL();
	GLAD_4_6::load_GL_RECURSIVE(load);
}