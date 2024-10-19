export module GLAD_1_2;

export import GLAD_1_1;

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
export using PFNGLDRAWRANGEELEMENTSPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
export using PFNGLTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
export using PFNGLTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
export using PFNGLCOPYTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

// Declare function pointers as extern variables
export extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
export extern PFNGLTEXIMAGE3DPROC glTexImage3D;
export extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
export extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

export namespace GLAD_1_2 {
	void load_GL_RECURSIVE(GLADloadproc);
}