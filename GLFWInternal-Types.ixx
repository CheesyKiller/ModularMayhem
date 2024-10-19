export module GLFWInternal:Types;

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

export import GLFW:Types;

export using GLFWbool = int;
export using GLFWproc = void(*)(void);
export using GLint = int;
export using GLuint = unsigned int;
export using GLenum = unsigned int;
export using GLbitfield = unsigned int;
export using GLubyte = unsigned char;
export using EGLint = int;
export using EGLBoolean = unsigned int;
export using EGLenum = unsigned int;
export using EGLConfig = void*;
export using EGLContext = void*;
export using EGLDisplay = void*;
export using EGLSurface = void*;
export using EGLNativeDisplayType = void*;
export using EGLNativeWindowType = void*;

export struct _GLFWerror;
export struct _GLFWinitconfig;
export struct _GLFWwndconfig;
export struct _GLFWctxconfig;
export struct _GLFWfbconfig;
export struct _GLFWcontext;
export struct _GLFWwindow;
export struct _GLFWplatform;
export struct _GLFWlibrary;
export struct _GLFWmonitor;
export struct _GLFWcursor;
export struct _GLFWmapelement;
export struct _GLFWmapping;
export struct _GLFWjoystick;
export struct _GLFWtls;
export struct _GLFWmutex;

export constexpr EGLSurface EGL_NO_SURFACE = (EGLSurface)0;
export constexpr EGLDisplay EGL_NO_DISPLAY = (EGLDisplay)0;
export constexpr EGLContext EGL_NO_CONTEXT = (EGLContext)0;
export constexpr EGLNativeDisplayType EGL_DEFAULT_DISPLAY = (EGLNativeDisplayType)0;

export using PFN_eglGetConfigAttrib = EGLBoolean(APIENTRY*)(EGLDisplay, EGLConfig, EGLint, EGLint*);
export using PFN_eglGetConfigs = EGLBoolean(APIENTRY*)(EGLDisplay, EGLConfig*, EGLint, EGLint*);
export using PFN_eglGetDisplay = EGLDisplay(APIENTRY*)(EGLNativeDisplayType);
export using PFN_eglGetError = EGLint(APIENTRY*)(void);
export using PFN_eglInitialize = EGLBoolean(APIENTRY*)(EGLDisplay, EGLint*, EGLint*);
export using PFN_eglTerminate = EGLBoolean(APIENTRY*)(EGLDisplay);
export using PFN_eglBindAPI = EGLBoolean(APIENTRY*)(EGLenum);
export using PFN_eglCreateContext = EGLContext(APIENTRY*)(EGLDisplay, EGLConfig, EGLContext, const EGLint*);
export using PFN_eglDestroySurface = EGLBoolean(APIENTRY*)(EGLDisplay, EGLSurface);
export using PFN_eglDestroyContext = EGLBoolean(APIENTRY*)(EGLDisplay, EGLContext);
export using PFN_eglCreateWindowSurface = EGLSurface(APIENTRY*)(EGLDisplay, EGLConfig, EGLNativeWindowType, const EGLint*);
export using PFN_eglMakeCurrent = EGLBoolean(APIENTRY*)(EGLDisplay, EGLSurface, EGLSurface, EGLContext);
export using PFN_eglSwapBuffers = EGLBoolean(APIENTRY*)(EGLDisplay, EGLSurface);
export using PFN_eglSwapInterval = EGLBoolean(APIENTRY*)(EGLDisplay, EGLint);
export using PFN_eglQueryString = const char* (APIENTRY*)(EGLDisplay, EGLint);
export using PFN_eglGetProcAddress = GLFWglproc(APIENTRY*)(const char*);

export using PFNGLCLEARPROC = void(APIENTRY*)(GLbitfield);
export using PFNGLGETSTRINGPROC = const GLubyte* (APIENTRY*)(GLenum);
export using PFNGLGETINTEGERVPROC = void(APIENTRY*)(GLenum, GLint*);
export using PFNGLGETSTRINGIPROC = const GLubyte* (APIENTRY*)(GLenum, GLuint);

export module EGL;

export constexpr auto& eglGetConfigAttrib = _glfw.egl.GetConfigAttrib;
export constexpr auto& eglGetConfigs = _glfw.egl.GetConfigs;
export constexpr auto& eglGetDisplay = _glfw.egl.GetDisplay;
export constexpr auto& eglGetError = _glfw.egl.GetError;
export constexpr auto& eglInitialize = _glfw.egl.Initialize;
export constexpr auto& eglTerminate = _glfw.egl.Terminate;
export constexpr auto& eglBindAPI = _glfw.egl.BindAPI;
export constexpr auto& eglCreateContext = _glfw.egl.CreateContext;
export constexpr auto& eglDestroySurface = _glfw.egl.DestroySurface;
export constexpr auto& eglDestroyContext = _glfw.egl.DestroyContext;
export constexpr auto& eglCreateWindowSurface = _glfw.egl.CreateWindowSurface;
export constexpr auto& eglMakeCurrent = _glfw.egl.MakeCurrent;
export constexpr auto& eglSwapBuffers = _glfw.egl.SwapBuffers;
export constexpr auto& eglSwapInterval = _glfw.egl.SwapInterval;
export constexpr auto& eglQueryString = _glfw.egl.QueryString;
export constexpr auto& eglGetProcAddress = _glfw.egl.GetProcAddress;