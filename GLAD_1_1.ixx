export module GLAD_1_1;

export import GLAD_1_0;

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
export using PFNGLDRAWARRAYSPROC = void(*)(GLenum mode, GLint first, GLsizei count);
export using PFNGLDRAWELEMENTSPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices);
export using PFNGLPOLYGONOFFSETPROC = void(*)(GLfloat factor, GLfloat units);
export using PFNGLCOPYTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
export using PFNGLCOPYTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
export using PFNGLCOPYTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
export using PFNGLCOPYTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
export using PFNGLTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
export using PFNGLTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
export using PFNGLBINDTEXTUREPROC = void(*)(GLenum target, GLuint texture);
export using PFNGLDELETETEXTURESPROC = void(*)(GLsizei n, const GLuint* textures);
export using PFNGLGENTEXTURESPROC = void(*)(GLsizei n, GLuint* textures);
export using PFNGLISTEXTUREPROC = GLboolean(*)(GLuint texture);

// Declare function pointers as extern variables
export extern PFNGLDRAWARRAYSPROC glDrawArrays;
export extern PFNGLDRAWELEMENTSPROC glDrawElements;
export extern PFNGLPOLYGONOFFSETPROC glPolygonOffset;
export extern PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
export extern PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
export extern PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
export extern PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
export extern PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
export extern PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
export extern PFNGLBINDTEXTUREPROC glBindTexture;
export extern PFNGLDELETETEXTURESPROC glDeleteTextures;
export extern PFNGLGENTEXTURESPROC glGenTextures;
export extern PFNGLISTEXTUREPROC glIsTexture;

export namespace GLAD_1_1 {
	void load_GL_RECURSIVE(GLADloadproc);
}