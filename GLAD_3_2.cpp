import <cstddef>;

import GLAD_3_2;

PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex = NULL;
PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex = NULL;
PFNGLFENCESYNCPROC glad_glFenceSync = NULL;
PFNGLISSYNCPROC glad_glIsSync = NULL;
PFNGLDELETESYNCPROC glad_glDeleteSync = NULL;
PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync = NULL;
PFNGLWAITSYNCPROC glad_glWaitSync = NULL;
PFNGLGETINTEGER64VPROC glad_glGetInteger64v = NULL;
PFNGLGETSYNCIVPROC glad_glGetSynciv = NULL;
PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture = NULL;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample = NULL;
PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv = NULL;
PFNGLSAMPLEMASKIPROC glad_glSampleMaski = NULL;

static void GLAD_3_2::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)load("glDrawElementsBaseVertex");
	glad_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)load("glDrawRangeElementsBaseVertex");
	glad_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)load("glDrawElementsInstancedBaseVertex");
	glad_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)load("glMultiDrawElementsBaseVertex");
	glad_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)load("glProvokingVertex");
	glad_glFenceSync = (PFNGLFENCESYNCPROC)load("glFenceSync");
	glad_glIsSync = (PFNGLISSYNCPROC)load("glIsSync");
	glad_glDeleteSync = (PFNGLDELETESYNCPROC)load("glDeleteSync");
	glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)load("glClientWaitSync");
	glad_glWaitSync = (PFNGLWAITSYNCPROC)load("glWaitSync");
	glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC)load("glGetInteger64v");
	glad_glGetSynciv = (PFNGLGETSYNCIVPROC)load("glGetSynciv");
	glad_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)load("glGetInteger64i_v");
	glad_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)load("glGetBufferParameteri64v");
	glad_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)load("glFramebufferTexture");
	glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)load("glTexImage2DMultisample");
	glad_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)load("glTexImage3DMultisample");
	glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)load("glGetMultisamplefv");
	glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC)load("glSampleMaski");

	GLAD_3_1::load_GL_RECURSIVE(load);
}