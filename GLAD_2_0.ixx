export module GLAD_2_0;

export import GLAD_1_5;

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
export using PFNGLBLENDEQUATIONSEPARATEPROC = void(*)(GLenum modeRGB, GLenum modeAlpha);
export using PFNGLDRAWBUFFERSPROC = void(*)(GLsizei n, const GLenum* bufs);
export using PFNGLSTENCILOPSEPARATEPROC = void(*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
export using PFNGLSTENCILFUNCSEPARATEPROC = void(*)(GLenum face, GLenum func, GLint ref, GLuint mask);
export using PFNGLSTENCILMASKSEPARATEPROC = void(*)(GLenum face, GLuint mask);
export using PFNGLATTACHSHADERPROC = void(*)(GLuint program, GLuint shader);
export using PFNGLBINDATTRIBLOCATIONPROC = void(*)(GLuint program, GLuint index, const GLchar* name);
export using PFNGLCOMPILESHADERPROC = void(*)(GLuint shader);
export using PFNGLCREATEPROGRAMPROC = GLuint(*)(void);
export using PFNGLCREATESHADERPROC = GLuint(*)(GLenum type);
export using PFNGLDELETEPROGRAMPROC = void(*)(GLuint program);
export using PFNGLDELETESHADERPROC = void(*)(GLuint shader);
export using PFNGLDETACHSHADERPROC = void(*)(GLuint program, GLuint shader);
export using PFNGLDISABLEVERTEXATTRIBARRAYPROC = void(*)(GLuint index);
export using PFNGLENABLEVERTEXATTRIBARRAYPROC = void(*)(GLuint index);
export using PFNGLGETACTIVEATTRIBPROC = void(*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
export using PFNGLGETACTIVEUNIFORMPROC = void(*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
export using PFNGLGETATTACHEDSHADERSPROC = void(*)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
export using PFNGLGETATTRIBLOCATIONPROC = GLint(*)(GLuint program, const GLchar* name);
export using PFNGLGETPROGRAMIVPROC = void(*)(GLuint program, GLenum pname, GLint* params);
export using PFNGLGETPROGRAMINFOLOGPROC = void(*)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
export using PFNGLGETSHADERIVPROC = void(*)(GLuint shader, GLenum pname, GLint* params);
export using PFNGLGETSHADERINFOLOGPROC = void(*)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
export using PFNGLGETSHADERSOURCEPROC = void(*)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
export using PFNGLGETUNIFORMLOCATIONPROC = GLint(*)(GLuint program, const GLchar* name);
export using PFNGLGETUNIFORMFVPROC = void(*)(GLuint program, GLint location, GLfloat* params);
export using PFNGLGETUNIFORMIVPROC = void(*)(GLuint program, GLint location, GLint* params);
export using PFNGLGETVERTEXATTRIBDVPROC = void(*)(GLuint index, GLenum pname, GLdouble* params);
export using PFNGLGETVERTEXATTRIBFVPROC = void(*)(GLuint index, GLenum pname, GLfloat* params);
export using PFNGLGETVERTEXATTRIBIVPROC = void(*)(GLuint index, GLenum pname, GLint* params);
export using PFNGLGETVERTEXATTRIBPOINTERVPROC = void(*)(GLuint index, GLenum pname, void** pointer);
export using PFNGLISPROGRAMPROC = GLboolean(*)(GLuint program);
export using PFNGLISSHADERPROC = GLboolean(*)(GLuint shader);
export using PFNGLLINKPROGRAMPROC = void(*)(GLuint program);
export using PFNGLSHADERSOURCEPROC = void(*)(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
export using PFNGLUSEPROGRAMPROC = void(*)(GLuint program);
export using PFNGLUNIFORM1FPROC = void(*)(GLint location, GLfloat v0);
export using PFNGLUNIFORM2FPROC = void(*)(GLint location, GLfloat v0, GLfloat v1);
export using PFNGLUNIFORM3FPROC = void(*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
export using PFNGLUNIFORM4FPROC = void(*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
export using PFNGLUNIFORM1IPROC = void(*)(GLint location, GLint v0);
export using PFNGLUNIFORM2IPROC = void(*)(GLint location, GLint v0, GLint v1);
export using PFNGLUNIFORM3IPROC = void(*)(GLint location, GLint v0, GLint v1, GLint v2);
export using PFNGLUNIFORM4IPROC = void(*)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
export using PFNGLUNIFORM1FVPROC = void(*)(GLint location, GLsizei count, const GLfloat* value);
export using PFNGLUNIFORM2FVPROC = void(*)(GLint location, GLsizei count, const GLfloat* value);
export using PFNGLUNIFORM3FVPROC = void(*)(GLint location, GLsizei count, const GLfloat* value);
export using PFNGLUNIFORM4FVPROC = void(*)(GLint location, GLsizei count, const GLfloat* value);
export using PFNGLUNIFORM1IVPROC = void(*)(GLint location, GLsizei count, const GLint* value);
export using PFNGLUNIFORM2IVPROC = void(*)(GLint location, GLsizei count, const GLint* value);
export using PFNGLUNIFORM3IVPROC = void(*)(GLint location, GLsizei count, const GLint* value);
export using PFNGLUNIFORM4IVPROC = void(*)(GLint location, GLsizei count, const GLint* value);
export using PFNGLUNIFORMMATRIX2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLVALIDATEPROGRAMPROC = void(*)(GLuint program);
export using PFNGLVERTEXATTRIB1DPROC = void(*)(GLuint index, GLdouble x);
export using PFNGLVERTEXATTRIB1DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIB1FPROC = void(*)(GLuint index, GLfloat x);
export using PFNGLVERTEXATTRIB1FVPROC = void(*)(GLuint index, const GLfloat* v);
export using PFNGLVERTEXATTRIB1SPROC = void(*)(GLuint index, GLshort x);
export using PFNGLVERTEXATTRIB1SVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIB2DPROC = void(*)(GLuint index, GLdouble x, GLdouble y);
export using PFNGLVERTEXATTRIB2DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIB2FPROC = void(*)(GLuint index, GLfloat x, GLfloat y);
export using PFNGLVERTEXATTRIB2FVPROC = void(*)(GLuint index, const GLfloat* v);
export using PFNGLVERTEXATTRIB2SPROC = void(*)(GLuint index, GLshort x, GLshort y);
export using PFNGLVERTEXATTRIB2SVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIB3DPROC = void(*)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
export using PFNGLVERTEXATTRIB3DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIB3FPROC = void(*)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
export using PFNGLVERTEXATTRIB3FVPROC = void(*)(GLuint index, const GLfloat* v);
export using PFNGLVERTEXATTRIB3SPROC = void(*)(GLuint index, GLshort x, GLshort y, GLshort z);
export using PFNGLVERTEXATTRIB3SVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIB4NBVPROC = void(*)(GLuint index, const GLbyte* v);
export using PFNGLVERTEXATTRIB4NIVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIB4NSVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIB4NUBPROC = void(*)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
export using PFNGLVERTEXATTRIB4NUBVPROC = void(*)(GLuint index, const GLubyte* v);
export using PFNGLVERTEXATTRIB4NUIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIB4NUSVPROC = void(*)(GLuint index, const GLushort* v);
export using PFNGLVERTEXATTRIB4BVPROC = void(*)(GLuint index, const GLbyte* v);
export using PFNGLVERTEXATTRIB4DPROC = void(*)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
export using PFNGLVERTEXATTRIB4DVPROC = void(*)(GLuint index, const GLdouble* v);
export using PFNGLVERTEXATTRIB4FPROC = void(*)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
export using PFNGLVERTEXATTRIB4FVPROC = void(*)(GLuint index, const GLfloat* v);
export using PFNGLVERTEXATTRIB4IVPROC = void(*)(GLuint index, const GLint* v);
export using PFNGLVERTEXATTRIB4SPROC = void(*)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
export using PFNGLVERTEXATTRIB4SVPROC = void(*)(GLuint index, const GLshort* v);
export using PFNGLVERTEXATTRIB4UBVPROC = void(*)(GLuint index, const GLubyte* v);
export using PFNGLVERTEXATTRIB4UIVPROC = void(*)(GLuint index, const GLuint* v);
export using PFNGLVERTEXATTRIB4USVPROC = void(*)(GLuint index, const GLushort* v);
export using PFNGLVERTEXATTRIBPOINTERPROC = void(*)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

// Declare function pointers as extern variables
export extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
export extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
export extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
export extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
export extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
export extern PFNGLATTACHSHADERPROC glAttachShader;
export extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
export extern PFNGLCOMPILESHADERPROC glCompileShader;
export extern PFNGLCREATEPROGRAMPROC glCreateProgram;
export extern PFNGLCREATESHADERPROC glCreateShader;
export extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
export extern PFNGLDELETESHADERPROC glDeleteShader;
export extern PFNGLDETACHSHADERPROC glDetachShader;
export extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
export extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
export extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
export extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
export extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
export extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
export extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
export extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
export extern PFNGLGETSHADERIVPROC glGetShaderiv;
export extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
export extern PFNGLGETSHADERSOURCEPROC glGetShaderSource;
export extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
export extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
export extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
export extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
export extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
export extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
export extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
export extern PFNGLISPROGRAMPROC glIsProgram;
export extern PFNGLISSHADERPROC glIsShader;
export extern PFNGLLINKPROGRAMPROC glLinkProgram;
export extern PFNGLSHADERSOURCEPROC glShaderSource;
export extern PFNGLUSEPROGRAMPROC glUseProgram;
export extern PFNGLUNIFORM1FPROC glUniform1f;
export extern PFNGLUNIFORM2FPROC glUniform2f;
export extern PFNGLUNIFORM3FPROC glUniform3f;
export extern PFNGLUNIFORM4FPROC glUniform4f;
export extern PFNGLUNIFORM1IPROC glUniform1i;
export extern PFNGLUNIFORM2IPROC glUniform2i;
export extern PFNGLUNIFORM3IPROC glUniform3i;
export extern PFNGLUNIFORM4IPROC glUniform4i;
export extern PFNGLUNIFORM1FVPROC glUniform1fv;
export extern PFNGLUNIFORM2FVPROC glUniform2fv;
export extern PFNGLUNIFORM3FVPROC glUniform3fv;
export extern PFNGLUNIFORM4FVPROC glUniform4fv;
export extern PFNGLUNIFORM1IVPROC glUniform1iv;
export extern PFNGLUNIFORM2IVPROC glUniform2iv;
export extern PFNGLUNIFORM3IVPROC glUniform3iv;
export extern PFNGLUNIFORM4IVPROC glUniform4iv;
export extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
export extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
export extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
export extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
export extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
export extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
export extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
export extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
export extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
export extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
export extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
export extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
export extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
export extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
export extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
export extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
export extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
export extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
export extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
export extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
export extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
export extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
export extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
export extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
export extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
export extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
export extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
export extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
export extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
export extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
export extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
export extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
export extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
export extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
export extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
export extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
export extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
export extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
export extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
export extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
export extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

export namespace GLAD_2_0 {
	void load_GL_RECURSIVE(GLADloadproc);
}