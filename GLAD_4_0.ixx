export module GLAD_4_0;

export import GLAD_3_3;

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
export using PFNGLMINSAMPLESHADINGPROC = void(*)(GLfloat value);
export using PFNGLBLENDEQUATIONIPROC = void(*)(GLuint buf, GLenum mode);
export using PFNGLBLENDEQUATIONSEPARATEIPROC = void(*)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
export using PFNGLBLENDFUNCIPROC = void(*)(GLuint buf, GLenum src, GLenum dst);
export using PFNGLBLENDFUNCSEPARATEIPROC = void(*)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
export using PFNGLDRAWARRAYSINDIRECTPROC = void(*)(GLenum mode, const void* indirect);
export using PFNGLDRAWELEMENTSINDIRECTPROC = void(*)(GLenum mode, GLenum type, const void* indirect);
export using PFNGLUNIFORM1DPROC = void(*)(GLint location, GLdouble x);
export using PFNGLUNIFORM2DPROC = void(*)(GLint location, GLdouble x, GLdouble y);
export using PFNGLUNIFORM3DPROC = void(*)(GLint location, GLdouble x, GLdouble y, GLdouble z);
export using PFNGLUNIFORM4DPROC = void(*)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
export using PFNGLUNIFORM1DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
export using PFNGLUNIFORM2DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
export using PFNGLUNIFORM3DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
export using PFNGLUNIFORM4DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
export using PFNGLUNIFORMMATRIX2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX2X3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX2X4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX3X2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX3X4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX4X2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLUNIFORMMATRIX4X3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLGETUNIFORMDVPROC = void(*)(GLuint program, GLint location, GLdouble* params);
export using PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC = GLint(*)(GLuint program, GLenum shadertype, const GLchar* name);
export using PFNGLGETSUBROUTINEINDEXPROC = GLuint(*)(GLuint program, GLenum shadertype, const GLchar* name);
export using PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
export using PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
export using PFNGLGETACTIVESUBROUTINENAMEPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
export using PFNGLUNIFORMSUBROUTINESUIVPROC = void(*)(GLenum shadertype, GLsizei count, const GLuint* indices);
export using PFNGLGETUNIFORMSUBROUTINEUIVPROC = void(*)(GLenum shadertype, GLint location, GLuint* params);
export using PFNGLGETPROGRAMSTAGEIVPROC = void(*)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
export using PFNGLPATCHPARAMETERIPROC = void(*)(GLenum pname, GLint value);
export using PFNGLPATCHPARAMETERFVPROC = void(*)(GLenum pname, const GLfloat* values);
export using PFNGLBINDTRANSFORMFEEDBACKPROC = void(*)(GLenum target, GLuint id);
export using PFNGLDELETETRANSFORMFEEDBACKSPROC = void(*)(GLsizei n, const GLuint* ids);
export using PFNGLGENTRANSFORMFEEDBACKSPROC = void(*)(GLsizei n, GLuint* ids);
export using PFNGLISTRANSFORMFEEDBACKPROC = GLboolean(*)(GLuint id);
export using PFNGLPAUSETRANSFORMFEEDBACKPROC = void(*)();
export using PFNGLRESUMETRANSFORMFEEDBACKPROC = void(*)();
export using PFNGLDRAWTRANSFORMFEEDBACKPROC = void(*)(GLenum mode, GLuint id);
export using PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC = void(*)(GLenum mode, GLuint id, GLuint stream);
export using PFNGLBEGINQUERYINDEXEDPROC = void(*)(GLenum target, GLuint index, GLuint id);
export using PFNGLENDQUERYINDEXEDPROC = void(*)(GLenum target, GLuint index);
export using PFNGLGETQUERYINDEXEDIVPROC = void(*)(GLenum target, GLuint index, GLenum pname, GLint* params);

// Declare function pointers as extern variables
export extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
export extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
export extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
export extern PFNGLBLENDFUNCIPROC glBlendFunci;
export extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
export extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
export extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
export extern PFNGLUNIFORM1DPROC glUniform1d;
export extern PFNGLUNIFORM2DPROC glUniform2d;
export extern PFNGLUNIFORM3DPROC glUniform3d;
export extern PFNGLUNIFORM4DPROC glUniform4d;
export extern PFNGLUNIFORM1DVPROC glUniform1dv;
export extern PFNGLUNIFORM2DVPROC glUniform2dv;
export extern PFNGLUNIFORM3DVPROC glUniform3dv;
export extern PFNGLUNIFORM4DVPROC glUniform4dv;
export extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
export extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
export extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
export extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
export extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
export extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
export extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
export extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
export extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
export extern PFNGLGETUNIFORMDVPROC glGetUniformdv;
export extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
export extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
export extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
export extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
export extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
export extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
export extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
export extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
export extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;
export extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
export extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
export extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
export extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
export extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
export extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
export extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
export extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
export extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
export extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
export extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
export extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;

export namespace GLAD_4_0 {
	void load_GL_RECURSIVE(GLADloadproc);
}