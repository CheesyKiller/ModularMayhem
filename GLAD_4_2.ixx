export module GLAD_4_2;

export import GLAD_4_1;

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

export using PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
export using PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
export using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
export using PFNGLGETINTERNALFORMATIVPROC = void(*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
export using PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC = void(*)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
export using PFNGLBINDIMAGETEXTUREPROC = void(*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
export using PFNGLMEMORYBARRIERPROC = void(*)(GLbitfield barriers);
export using PFNGLTEXSTORAGE1DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
export using PFNGLTEXSTORAGE2DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
export using PFNGLTEXSTORAGE3DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
export using PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLsizei instancecount);
export using PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

// Export the function pointers
export extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
export extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
export extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
export extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
export extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
export extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
export extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;
export extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
export extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
export extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;
export extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
export extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

export namespace GLAD_4_2 {
	void load_GL_RECURSIVE(GLADloadproc);
}