import <cstddef>;

import GLAD_2_1;

PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = NULL;

static void GLAD_2_1::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)load("glUniformMatrix2x3fv");
	glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)load("glUniformMatrix3x2fv");
	glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)load("glUniformMatrix2x4fv");
	glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)load("glUniformMatrix4x2fv");
	glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)load("glUniformMatrix3x4fv");
	glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)load("glUniformMatrix4x3fv");
	GLAD_2_0::load_GL_RECURSIVE(load);
}