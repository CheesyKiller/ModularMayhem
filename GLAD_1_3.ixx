export module GLAD_1_3;

export import GLAD_1_2;

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
export using PFNGLACTIVETEXTUREPROC = void(*)(GLenum texture);
export using PFNGLSAMPLECOVERAGEPROC = void(*)(GLfloat value, GLboolean invert);
export using PFNGLCOMPRESSEDTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLGETCOMPRESSEDTEXIMAGEPROC = void(*)(GLenum target, GLint level, void* img);

// Declare function pointers as extern variables
export extern PFNGLACTIVETEXTUREPROC glActiveTexture;
export extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
export extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
export extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
export extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
export extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
export extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
export extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
export extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;

export namespace GLAD_1_3 {
	void load_GL_RECURSIVE(GLADloadproc);
}