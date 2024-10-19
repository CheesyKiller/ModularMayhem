export module GLAD_3_0;

export import GLAD_2_1;

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
export using PFNGLCOLORMASKIPROC = void(*)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
export using PFNGLGETBOOLEANI_VPROC = void(*)(GLenum target, GLuint index, GLboolean* data);
export using PFNGLGETINTEGERI_VPROC = void(*)(GLenum target, GLuint index, GLint* data);
export using PFNGLENABLEIPROC = void(*)(GLenum target, GLuint index);
export using PFNGLDISABLEIPROC = void(*)(GLenum target, GLuint index);
export using PFNGLISENABLEDIPROC = GLboolean(*)(GLenum target, GLuint index);
export using PFNGLBEGINTRANSFORMFEEDBACKPROC = void(*)(GLenum primitiveMode);
export using PFNGLENDTRANSFORMFEEDBACKPROC = void(*)(void);
export using PFNGLBINDBUFFERRANGEPROC = void(*)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
export using PFNGLBINDBUFFERBASEPROC = void(*)(GLenum target, GLuint index, GLuint buffer);
export using PFNGLTRANSFORMFEEDBACKVARYINGSPROC = void(*)(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
export using PFNGLGETTRANSFORMFEEDBACKVARYINGPROC = void(*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
export using PFNGLCLAMPCOLORPROC = void(*)(GLenum target, GLenum clamp);
export using PFNGLBEGINCONDITIONALRENDERPROC = void(*)(GLuint id, GLenum mode);
export using PFNGLENDCONDITIONALRENDERPROC = void(*)(void);
export using PFNGLVERTEXATTRIBIPOINTERPROC = void(*)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
export using PFNGLGETVERTEXATTRIBIIVPROC = void(*)(GLuint index, GLenum pname, GLint* params);
export using PFNGLGETVERTEXATTRIBIUIVPROC = void(*)(GLuint index, GLenum pname, GLuint* params);
export using PFNGLVERTEXATTRIBI1IPROC = void(*)(GLuint index, GLint x);
export using PFNGLVERTEXATTRIBI2IPROC = void(*)(GLuint index, GLint x, GLint y);
export using PFNGLVERTEXATTRIBI3IPROC = void(*)(GLuint index, GLint x, GLint y, GLint z);
export using PFNGLVERTEXATTRIBI4IPROC = void(*)(GLuint index, GLint x, GLint y, GLint z, GLint w);
export using PFNGLVERTEXATTRIBI1UIPROC = void(*)(GLuint index, GLuint x);
export using PFNGLVERTEXATTRIBI2UIPROC = void(*)(GLuint index, GLuint x, GLuint y);
export using PFNGLVERTEXATTRIBI3UIPROC = void(*)(GLuint index, GLuint x, GLuint y, GLuint z);
export using PFNGLVERTEXATTRIBI4UIPROC = void(*)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
export using PFNGLVERTEXATTRIBI1IVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIBI2IVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIBI3IVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIBI4IVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIBI1UIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIBI2UIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIBI3UIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIBI4UIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIBI4BVPROC = void(*)(GLuint index, const GLbyte* v);
export using PFNGLVERTEXATTRIBI4SVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIBI4UBVPROC = void(*)(GLuint index, const GLubyte* v);
export using PFNGLVERTEXATTRIBI4USVPROC = void(*)(GLuint index, const GLushort* v);
export using PFNGLGETUNIFORMUIVPROC = void(*)(GLuint program, GLint location, GLuint* params);
export using PFNGLBINDFRAGDATALOCATIONPROC = void(*)(GLuint program, GLuint color, const GLchar* name);
export using PFNGLGETFRAGDATALOCATIONPROC = GLint(*)(GLuint program, const GLchar* name);
export using PFNGLUNIFORM1UIPROC = void(*)(GLint location, GLuint v0);
export using PFNGLUNIFORM2UIPROC = void(*)(GLint location, GLuint v0, GLuint v1);
export using PFNGLUNIFORM3UIPROC = void(*)(GLint location, GLuint v0, GLuint v1, GLuint v2);
export using PFNGLUNIFORM4UIPROC = void(*)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
export using PFNGLUNIFORM1UIVPROC = void(*)(GLint location, GLsizei count, const GLuint* value);
export using PFNGLUNIFORM2UIVPROC = void(*)(GLint location, GLsizei count, const GLuint* value);
export using PFNGLUNIFORM3UIVPROC = void(*)(GLint location, GLsizei count, const GLuint* value);
export using PFNGLUNIFORM4UIVPROC = void(*)(GLint location, GLsizei count, const GLuint* value);
export using PFNGLTEXPARAMETERIIVPROC = void(*)(GLenum target, GLenum pname, const GLint* params);
export using PFNGLTEXPARAMETERIUIVPROC = void(*)(GLenum target, GLenum pname, const GLuint* params);
export using PFNGLGETTEXPARAMETERIIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETTEXPARAMETERIUIVPROC = void(*)(GLenum target, GLenum pname, GLuint* params);
export using PFNGLCLEARBUFFERIVPROC = void(*)(GLenum buffer, GLint drawbuffer, const GLint* value);
export using PFNGLCLEARBUFFERUIVPROC = void(*)(GLenum buffer, GLint drawbuffer, const GLuint* value);
export using PFNGLCLEARBUFFERFVPROC = void(*)(GLenum buffer, GLint drawbuffer, const GLfloat* value);
export using PFNGLCLEARBUFFERFIPROC = void(*)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
export using PFNGLGETSTRINGIPROC = const GLubyte* (*)(GLenum name, GLuint index);
export using PFNGLISRENDERBUFFERPROC = GLboolean(*)(GLuint renderbuffer);
export using PFNGLBINDRENDERBUFFERPROC = void(*)(GLenum target, GLuint renderbuffer);
export using PFNGLDELETERENDERBUFFERSPROC = void(*)(GLsizei n, const GLuint* renderbuffers);
export using PFNGLGENRENDERBUFFERSPROC = void(*)(GLsizei n, GLuint* renderbuffers);
export using PFNGLRENDERBUFFERSTORAGEPROC = void(*)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
export using PFNGLGETRENDERBUFFERPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLISFRAMEBUFFERPROC = GLboolean(*)(GLuint framebuffer);
export using PFNGLBINDFRAMEBUFFERPROC = void(*)(GLenum target, GLuint framebuffer);
export using PFNGLDELETEFRAMEBUFFERSPROC = void(*)(GLsizei n, const GLuint* framebuffers);
export using PFNGLGENFRAMEBUFFERSPROC = void(*)(GLsizei n, GLuint* framebuffers);
export using PFNGLCHECKFRAMEBUFFERSTATUSPROC = GLenum(*)(GLenum target);
export using PFNGLFRAMEBUFFERTEXTURE1DPROC = void(*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
export using PFNGLFRAMEBUFFERTEXTURE2DPROC = void(*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
export using PFNGLFRAMEBUFFERTEXTURE3DPROC = void(*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
export using PFNGLFRAMEBUFFERRENDERBUFFERPROC = void(*)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
export using PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC = void(*)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
export using PFNGLGENERATEMIPMAPPROC = void(*)(GLenum target);
export using PFNGLBLITFRAMEBUFFERPROC = void(*)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
export using PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
export using PFNGLFRAMEBUFFERTEXTURELAYERPROC = void(*)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
export using PFNGLMAPBUFFERRANGEPROC = void* (*)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
export using PFNGLFLUSHMAPPEDBUFFERRANGEPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr length);
export using PFNGLBINDVERTEXARRAYPROC = void(*)(GLuint array);
export using PFNGLDELETEVERTEXARRAYSPROC = void(*)(GLsizei n, const GLuint* arrays);
export using PFNGLGENVERTEXARRAYSPROC = void(*)(GLsizei n, GLuint* arrays);
export using PFNGLISVERTEXARRAYPROC = GLboolean(*)(GLuint array);

// Declare function pointers as extern variables
export extern PFNGLCOLORMASKIPROC glColorMaski;
export extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
export extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
export extern PFNGLENABLEIPROC glEnablei;
export extern PFNGLDISABLEIPROC glDisablei;
export extern PFNGLISENABLEDIPROC glIsEnabledi;
export extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
export extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
export extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
export extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
export extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
export extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
export extern PFNGLCLAMPCOLORPROC glClampColor;
export extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
export extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
export extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
export extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
export extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
export extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
export extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
export extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
export extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
export extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
export extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
export extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
export extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
export extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
export extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
export extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
export extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
export extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
export extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
export extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
export extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
export extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
export extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
export extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
export extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
export extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
export extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
export extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
export extern PFNGLUNIFORM1UIPROC glUniform1ui;
export extern PFNGLUNIFORM2UIPROC glUniform2ui;
export extern PFNGLUNIFORM3UIPROC glUniform3ui;
export extern PFNGLUNIFORM4UIPROC glUniform4ui;
export extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
export extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
export extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
export extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
export extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
export extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
export extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
export extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
export extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
export extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
export extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
export extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
export extern PFNGLGETSTRINGIPROC glGetStringi;
export extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
export extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
export extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
export extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
export extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
export extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
export extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
export extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
export extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
export extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
export extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
export extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
export extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
export extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
export extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
export extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
export extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
export extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
export extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
export extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
export extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
export extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
export extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
export extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
export extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
export extern PFNGLISVERTEXARRAYPROC glIsVertexArray;

export namespace GLAD_3_0 {
	void load_GL_RECURSIVE(GLADloadproc);
}