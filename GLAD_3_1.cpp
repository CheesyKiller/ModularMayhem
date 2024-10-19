import <cstddef>;

import GLAD_3_1;

PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced = NULL;
PFNGLTEXBUFFERPROC glad_glTexBuffer = NULL;
PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex = NULL;
PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData = NULL;
PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv = NULL;
PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding = NULL;

static void GLAD_3_1::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)load("glDrawArraysInstanced");
	glad_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)load("glDrawElementsInstanced");
	glad_glTexBuffer = (PFNGLTEXBUFFERPROC)load("glTexBuffer");
	glad_glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)load("glPrimitiveRestartIndex");
	glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)load("glCopyBufferSubData");
	glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)load("glGetUniformIndices");
	glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)load("glGetActiveUniformsiv");
	glad_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)load("glGetActiveUniformName");
	glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)load("glGetUniformBlockIndex");
	glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)load("glGetActiveUniformBlockiv");
	glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)load("glGetActiveUniformBlockName");
	glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)load("glUniformBlockBinding");

	GLAD_3_0::load_GL_RECURSIVE(load);
}