import <cstddef>;

import GLAD_4_2;

PFNGLBINDIMAGETEXTUREPROC glad_glBindImageTexture = NULL;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glad_glDrawArraysInstancedBaseInstance = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glad_glDrawElementsInstancedBaseInstance = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glad_glDrawElementsInstancedBaseVertexBaseInstance = NULL;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glad_glDrawTransformFeedbackInstanced = NULL;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glad_glDrawTransformFeedbackStreamInstanced = NULL;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glad_glGetActiveAtomicCounterBufferiv = NULL;
PFNGLGETINTERNALFORMATIVPROC glad_glGetInternalformativ = NULL;
PFNGLMEMORYBARRIERPROC glad_glMemoryBarrier = NULL;
PFNGLTEXSTORAGE1DPROC glad_glTexStorage1D = NULL;
PFNGLTEXSTORAGE2DPROC glad_glTexStorage2D = NULL;
PFNGLTEXSTORAGE3DPROC glad_glTexStorage3D = NULL;

static void GLAD_4_2::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)load("glDrawArraysInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)load("glDrawElementsInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)load("glDrawElementsInstancedBaseVertexBaseInstance");
	glad_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)load("glGetInternalformativ");
	glad_glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)load("glGetActiveAtomicCounterBufferiv");
	glad_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)load("glBindImageTexture");
	glad_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)load("glMemoryBarrier");
	glad_glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)load("glTexStorage1D");
	glad_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)load("glTexStorage2D");
	glad_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)load("glTexStorage3D");
	glad_glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)load("glDrawTransformFeedbackInstanced");
	glad_glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)load("glDrawTransformFeedbackStreamInstanced");

	GLAD_4_1::load_GL_RECURSIVE(load);
}