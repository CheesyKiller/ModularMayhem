import <cstddef>;

import GLAD_1_2;

PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glad_glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = NULL;

static void GLAD_1_2::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)load("glDrawRangeElements");
	glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC)load("glTexImage3D");
	glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)load("glTexSubImage3D");
	glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)load("glCopyTexSubImage3D");

	GLAD_1_1::load_GL_RECURSIVE(load);
}