export module GLAD_2_1;

export import GLAD_2_0;

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
export using PFNGLUNIFORMMATRIX2X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX3X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX2X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX4X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX3X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX4X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

// Declare function pointers as extern variables
export extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
export extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
export extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
export extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
export extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
export extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

export namespace GLAD_2_1 {
	void load_GL_RECURSIVE(GLADloadproc);
}