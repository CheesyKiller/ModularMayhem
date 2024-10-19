export module GLAD_3_2;

export import GLAD_3_1;

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
export using PFNGLDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export using PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
export using PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
export using PFNGLPROVOKINGVERTEXPROC = void(*)(GLenum mode);
export using PFNGLFENCESYNCPROC = GLsync(*)(GLenum condition, GLbitfield flags);
export using PFNGLISSYNCPROC = GLboolean(*)(GLsync sync);
export using PFNGLDELETESYNCPROC = void(*)(GLsync sync);
export using PFNGLCLIENTWAITSYNCPROC = GLenum(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export using PFNGLWAITSYNCPROC = void(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export using PFNGLGETINTEGER64VPROC = void(*)(GLenum pname, GLint64* data);
export using PFNGLGETSYNCIVPROC = void(*)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
export using PFNGLGETINTEGER64I_VPROC = void(*)(GLenum target, GLuint index, GLint64* data);
export using PFNGLGETBUFFERPARAMETERI64VPROC = void(*)(GLenum target, GLenum pname, GLint64* params);
export using PFNGLFRAMEBUFFERTEXTUREPROC = void(*)(GLenum target, GLenum attachment, GLuint texture, GLint level);
export using PFNGLTEXIMAGE2DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
export using PFNGLTEXIMAGE3DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
export using PFNGLGETMULTISAMPLEFVPROC = void(*)(GLenum pname, GLuint index, GLfloat* val);
export using PFNGLSAMPLEMASKIPROC = void(*)(GLuint maskNumber, GLbitfield mask);

// Declare function pointers as extern variables
export extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
export extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
export extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
export extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
export extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
export extern PFNGLFENCESYNCPROC glFenceSync;
export extern PFNGLISSYNCPROC glIsSync;
export extern PFNGLDELETESYNCPROC glDeleteSync;
export extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
export extern PFNGLWAITSYNCPROC glWaitSync;
export extern PFNGLGETINTEGER64VPROC glGetInteger64v;
export extern PFNGLGETSYNCIVPROC glGetSynciv;
export extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
export extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
export extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
export extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
export extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
export extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
export extern PFNGLSAMPLEMASKIPROC glSampleMaski;

export namespace GLAD_3_2 {
	void load_GL_RECURSIVE(GLADloadproc);
}