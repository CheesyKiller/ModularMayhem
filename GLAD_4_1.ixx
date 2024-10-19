export module GLAD_4_1;

export import GLAD_4_0;

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
export using PFNGLRELEASESHADERCOMPILERPROC = void(*)();
export using PFNGLSHADERBINARYPROC = void(*)(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length);
export using PFNGLGETSHADERPRECISIONFORMATPROC = void(*)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
export using PFNGLDEPTHRANGEFPROC = void(*)(GLfloat n, GLfloat f);
export using PFNGLCLEARDEPTHFPROC = void(*)(GLfloat d);
export using PFNGLGETPROGRAMBINARYPROC = void(*)(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);
export using PFNGLPROGRAMBINARYPROC = void(*)(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length);
export using PFNGLPROGRAMPARAMETERIPROC = void(*)(GLuint program, GLenum pname, GLint value);
export using PFNGLUSEPROGRAMSTAGESPROC = void(*)(GLuint pipeline, GLbitfield stages, GLuint program);
export using PFNGLACTIVESHADERPROGRAMPROC = void(*)(GLuint pipeline, GLuint program);
export using PFNGLCREATESHADERPROGRAMVPROC = GLuint(*)(GLenum type, GLsizei count, const GLchar* const* strings);
export using PFNGLBINDPROGRAMPIPELINEPROC = void(*)(GLuint pipeline);
export using PFNGLDELETEPROGRAMPIPELINESPROC = void(*)(GLsizei n, const GLuint* pipelines);
export using PFNGLGENPROGRAMPIPELINESPROC = void(*)(GLsizei n, GLuint* pipelines);
export using PFNGLISPROGRAMPIPELINEPROC = GLboolean(*)(GLuint pipeline);
export using PFNGLGETPROGRAMPIPELINEIVPROC = void(*)(GLuint pipeline, GLenum pname, GLint* params);
export using PFNGLPROGRAMUNIFORM1IPROC = void(*)(GLuint program, GLint location, GLint v0);
export using PFNGLPROGRAMUNIFORM1IVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLint* value);
export using PFNGLPROGRAMUNIFORM1FPROC = void(*)(GLuint program, GLint location, GLfloat v0);
export using PFNGLPROGRAMUNIFORM1FVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
export using PFNGLPROGRAMUNIFORM1DPROC = void(*)(GLuint program, GLint location, GLdouble v0);
export using PFNGLPROGRAMUNIFORM1DVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
export using PFNGLPROGRAMUNIFORM1UIPROC = void(*)(GLuint program, GLint location, GLuint v0);
export using PFNGLPROGRAMUNIFORM1UIVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLuint* value);
export using PFNGLPROGRAMUNIFORM2IPROC = void(*)(GLuint program, GLint location, GLint v0, GLint v1);
export using PFNGLPROGRAMUNIFORM2IVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLint* value);
export using PFNGLPROGRAMUNIFORM2FPROC = void(*)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
export using PFNGLPROGRAMUNIFORM2FVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
export using PFNGLPROGRAMUNIFORM2DPROC = void(*)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
export using PFNGLPROGRAMUNIFORM2DVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
export using PFNGLPROGRAMUNIFORM2UIPROC = void(*)(GLuint program, GLint location, GLuint v0, GLuint v1);
export using PFNGLPROGRAMUNIFORM2UIVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLuint* value);
export using PFNGLPROGRAMUNIFORM3IPROC = void(*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
export using PFNGLPROGRAMUNIFORM3IVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLint* value);
export using PFNGLPROGRAMUNIFORM3FPROC = void(*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
export using PFNGLPROGRAMUNIFORM3FVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
export using PFNGLPROGRAMUNIFORM3DPROC = void(*)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
export using PFNGLPROGRAMUNIFORM3DVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
export using PFNGLPROGRAMUNIFORM3UIPROC = void(*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
export using PFNGLPROGRAMUNIFORM3UIVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLuint* value);
export using PFNGLPROGRAMUNIFORM4IPROC = void(*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
export using PFNGLPROGRAMUNIFORM4IVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLint* value);
export using PFNGLPROGRAMUNIFORM4FPROC = void(*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
export using PFNGLPROGRAMUNIFORM4FVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
export using PFNGLPROGRAMUNIFORM4DPROC = void(*)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
export using PFNGLPROGRAMUNIFORM4DVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
export using PFNGLPROGRAMUNIFORM4UIPROC = void(*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
export using PFNGLPROGRAMUNIFORM4UIVPROC = void(*)(GLuint program, GLint location, GLsizei count, const GLuint* value);
export using PFNGLPROGRAMUNIFORMMATRIX2FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX3FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX4FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX2DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX3DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX4DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC = void(*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export using PFNGLVALIDATEPROGRAMPIPELINEPROC = void(*)(GLuint pipeline);
export using PFNGLGETPROGRAMPIPELINEINFOLOGPROC = void(*)(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
export using PFNGLVERTEXATTRIBL1DPROC = void(*)(GLuint index, GLdouble x);
export using PFNGLVERTEXATTRIBL2DPROC = void(*)(GLuint index, GLdouble x, GLdouble y);
export using PFNGLVERTEXATTRIBL3DPROC = void(*)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
export using PFNGLVERTEXATTRIBL4DPROC = void(*)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
export using PFNGLVERTEXATTRIBL1DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIBL2DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIBL3DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIBL4DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIBLPOINTERPROC = void(*)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
export using PFNGLGETVERTEXATTRIBLDVPROC = void(*)(GLuint index, GLenum pname, GLdouble* params);
export using PFNGLVIEWPORTARRAYVPROC = void(*)(GLuint first, GLsizei count, const GLfloat* v);
export using PFNGLVIEWPORTINDEXEDFPROC = void(*)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
export using PFNGLVIEWPORTINDEXEDFVPROC = void(*)(GLuint index, const GLfloat* v);
export using PFNGLSCISSORARRAYVPROC = void(*)(GLuint first, GLsizei count, const GLint* v);
export using PFNGLSCISSORINDEXEDPROC = void(*)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
export using PFNGLSCISSORINDEXEDVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLDEPTHRANGEARRAYVPROC = void(*)(GLuint first, GLsizei count, const GLdouble* v);
export using PFNGLDEPTHRANGEINDEXEDPROC = void(*)(GLuint index, GLdouble n, GLdouble f);
export using PFNGLGETFLOATI_VPROC = void(*)(GLenum target, GLuint index, GLfloat* data);
export using PFNGLGETDOUBLEI_VPROC = void(*)(GLenum target, GLuint index, GLdouble* data);

// Export the function pointers
export extern PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
export extern PFNGLSHADERBINARYPROC glShaderBinary;
export extern PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
export extern PFNGLDEPTHRANGEFPROC glDepthRangef;
export extern PFNGLCLEARDEPTHFPROC glClearDepthf;
export extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
export extern PFNGLPROGRAMBINARYPROC glProgramBinary;
export extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
export extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
export extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
export extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
export extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
export extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
export extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
export extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
export extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
export extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
export extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
export extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
export extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
export extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
export extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
export extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
export extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
export extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
export extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
export extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
export extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
export extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
export extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
export extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
export extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
export extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
export extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
export extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
export extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
export extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
export extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
export extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
export extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
export extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
export extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
export extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
export extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
export extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
export extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
export extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
export extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
export extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
export extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
export extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
export extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
export extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
export extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
export extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
export extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
export extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
export extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
export extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
export extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
export extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
export extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
export extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
export extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
export extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
export extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
export extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
export extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
export extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
export extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
export extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
export extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
export extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
export extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
export extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
export extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
export extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
export extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
export extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
export extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
export extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
export extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
export extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
export extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
export extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
export extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
export extern PFNGLGETFLOATI_VPROC glGetFloati_v;
export extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

export namespace GLAD_4_1 {
	void load_GL_RECURSIVE(GLADloadproc);
}