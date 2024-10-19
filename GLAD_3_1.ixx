export module GLAD_3_1;

export import GLAD_3_0;

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
export using PFNGLDRAWARRAYSINSTANCEDPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
export using PFNGLDRAWELEMENTSINSTANCEDPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
export using PFNGLTEXBUFFERPROC = void(*)(GLenum target, GLenum internalformat, GLuint buffer);
export using PFNGLPRIMITIVERESTARTINDEXPROC = void(*)(GLuint index);
export using PFNGLCOPYBUFFERSUBDATAPROC = void(*)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
export using PFNGLGETUNIFORMINDICESPROC = void(*)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
export using PFNGLGETACTIVEUNIFORMSIVPROC = void(*)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
export using PFNGLGETACTIVEUNIFORMNAMEPROC = void(*)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
export using PFNGLGETUNIFORMBLOCKINDEXPROC = GLuint(*)(GLuint program, const GLchar* uniformBlockName);
export using PFNGLGETACTIVEUNIFORMBLOCKIVPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
export using PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
export using PFNGLUNIFORMBLOCKBINDINGPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

// Declare function pointers as extern variables
export extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
export extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
export extern PFNGLTEXBUFFERPROC glTexBuffer;
export extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
export extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
export extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
export extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
export extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
export extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
export extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
export extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
export extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

export namespace GLAD_3_1 {
	void load_GL_RECURSIVE(GLADloadproc);
}