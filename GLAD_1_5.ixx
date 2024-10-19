export module GLAD_1_5;

export import GLAD_1_4;

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
export using PFNGLGENQUERIESPROC = void(*)(GLsizei n, GLuint* ids);
export using PFNGLDELETEQUERIESPROC = void(*)(GLsizei n, const GLuint* ids);
export using PFNGLISQUERYPROC = GLboolean(*)(GLuint id);
export using PFNGLBEGINQUERYPROC = void(*)(GLenum target, GLuint id);
export using PFNGLENDQUERYPROC = void(*)(GLenum target);
export using PFNGLGETQUERYIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETQUERYOBJECTIVPROC = void(*)(GLuint id, GLenum pname, GLint* params);
export using PFNGLGETQUERYOBJECTUIVPROC = void(*)(GLuint id, GLenum pname, GLuint* params);
export using PFNGLBINDBUFFERPROC = void(*)(GLenum target, GLuint buffer);
export using PFNGLDELETEBUFFERSPROC = void(*)(GLsizei n, const GLuint* buffers);
export using PFNGLGENBUFFERSPROC = void(*)(GLsizei n, GLuint* buffers);
export using PFNGLISBUFFERPROC = GLboolean(*)(GLuint buffer);
export using PFNGLBUFFERDATAPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
export using PFNGLBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
export using PFNGLGETBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
export using PFNGLMAPBUFFERPROC = void* (*)(GLenum target, GLenum access);
export using PFNGLUNMAPBUFFERPROC = GLboolean(*)(GLenum target);
export using PFNGLGETBUFFERPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETBUFFERPOINTERVPROC = void(*)(GLenum target, GLenum pname, void** params);

// Declare function pointers as extern variables
export extern PFNGLGENQUERIESPROC glGenQueries;
export extern PFNGLDELETEQUERIESPROC glDeleteQueries;
export extern PFNGLISQUERYPROC glIsQuery;
export extern PFNGLBEGINQUERYPROC glBeginQuery;
export extern PFNGLENDQUERYPROC glEndQuery;
export extern PFNGLGETQUERYIVPROC glGetQueryiv;
export extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
export extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
export extern PFNGLBINDBUFFERPROC glBindBuffer;
export extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
export extern PFNGLGENBUFFERSPROC glGenBuffers;
export extern PFNGLISBUFFERPROC glIsBuffer;
export extern PFNGLBUFFERDATAPROC glBufferData;
export extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
export extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
export extern PFNGLMAPBUFFERPROC glMapBuffer;
export extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;
export extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
export extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

export namespace GLAD_1_5 {
	void load_GL_RECURSIVE(GLADloadproc);
}