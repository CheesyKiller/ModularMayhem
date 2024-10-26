export module GLFWInternalEGL:Functions;

export import :Types;
export import GLFWInternalCore;

export using PFN_eglGetConfigAttrib = EGLBoolean(*)(EGLDisplay, EGLConfig, EGLint, EGLint*);
export using PFN_eglGetConfigs = EGLBoolean(*)(EGLDisplay, EGLConfig*, EGLint, EGLint*);
export using PFN_eglGetDisplay = EGLDisplay(*)(EGLNativeDisplayType);
export using PFN_eglGetError = EGLint(*)(void);
export using PFN_eglInitialize = EGLBoolean(*)(EGLDisplay, EGLint*, EGLint*);
export using PFN_eglTerminate = EGLBoolean(*)(EGLDisplay);
export using PFN_eglBindAPI = EGLBoolean(*)(EGLenum);
export using PFN_eglCreateContext = EGLContext(*)(EGLDisplay, EGLConfig, EGLContext, const EGLint*);
export using PFN_eglDestroySurface = EGLBoolean(*)(EGLDisplay, EGLSurface);
export using PFN_eglDestroyContext = EGLBoolean(*)(EGLDisplay, EGLContext);
export using PFN_eglCreateWindowSurface = EGLSurface(*)(EGLDisplay, EGLConfig, EGLNativeWindowType, const EGLint*);
export using PFN_eglMakeCurrent = EGLBoolean(*)(EGLDisplay, EGLSurface, EGLSurface, EGLContext);
export using PFN_eglSwapBuffers = EGLBoolean(*)(EGLDisplay, EGLSurface);
export using PFN_eglSwapInterval = EGLBoolean(*)(EGLDisplay, EGLint);
export using PFN_eglQueryString = const char* (*)(EGLDisplay, EGLint);
export using PFN_eglGetProcAddress = GLFWglproc(*)(const char*);

export using PFNEGLGETPLATFORMDISPLAYEXTPROC = EGLDisplay(*)(EGLenum, void*, const EGLint*);
export using PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC = EGLSurface(*)(EGLDisplay, EGLConfig, void*, const EGLint*);