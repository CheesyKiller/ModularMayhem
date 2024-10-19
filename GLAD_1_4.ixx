export module GLAD_1_4;

export import GLAD_1_3;

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

// Alias for function pointer types
export using PFNGLBLENDFUNCSEPARATEPROC = void(*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
export using PFNGLMULTIDRAWARRAYSPROC = void(*)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
export using PFNGLMULTIDRAWELEMENTSPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
export using PFNGLPOINTPARAMETERFPROC = void(*)(GLenum pname, GLfloat param);
export using PFNGLPOINTPARAMETERFVPROC = void(*)(GLenum pname, const GLfloat* params);
export using PFNGLPOINTPARAMETERIPROC = void(*)(GLenum pname, GLint param);
export using PFNGLPOINTPARAMETERIVPROC = void(*)(GLenum pname, const GLint* params);
export using PFNGLBLENDCOLORPROC = void(*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
export using PFNGLBLENDEQUATIONPROC = void(*)(GLenum mode);

// Declare function pointers as extern variables
export extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
export extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
export extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
export extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
export extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
export extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
export extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
export extern PFNGLBLENDCOLORPROC glBlendColor;
export extern PFNGLBLENDEQUATIONPROC glBlendEquation;

export namespace GLAD_1_4 {
	void load_GL_RECURSIVE(GLADloadproc);
}