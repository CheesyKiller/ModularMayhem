export module GLAD_BASE;

export import :Types;
export import :Macros;

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

export using GLADloadproc = void* (APIENTRYP)(const char* name);
export using PFNWGLGETPROCADDRESSPROC_PRIVATE = void* (APIENTRYP)(const char*);

export int gladLoadGL();

export int gladLoadGLLoader(GLADloadproc);