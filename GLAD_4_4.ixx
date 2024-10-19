export module GLAD_4_4;

export import GLAD_4_3;

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

export using PFNGLBUFFERSTORAGEPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
export using PFNGLCLEARTEXIMAGEPROC = void(*)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
export using PFNGLCLEARTEXSUBIMAGEPROC = void(*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
export using PFNGLBINDBUFFERSBASEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
export using PFNGLBINDBUFFERSRANGEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
export using PFNGLBINDTEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
export using PFNGLBINDSAMPLERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* samplers);
export using PFNGLBINDIMAGETEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
export using PFNGLBINDVERTEXBUFFERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

// Export the function pointers
export extern PFNGLBUFFERSTORAGEPROC glBufferStorage;
export extern PFNGLCLEARTEXIMAGEPROC glClearTexImage;
export extern PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
export extern PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
export extern PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
export extern PFNGLBINDTEXTURESPROC glBindTextures;
export extern PFNGLBINDSAMPLERSPROC glBindSamplers;
export extern PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
export extern PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

export namespace GLAD_4_4 {
	void load_GL_RECURSIVE(GLADloadproc);
}