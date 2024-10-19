import <cstddef>;

import GLAD_4_4;

PFNGLBINDBUFFERSBASEPROC glad_glBindBuffersBase = NULL;
PFNGLBINDBUFFERSRANGEPROC glad_glBindBuffersRange = NULL;
PFNGLBINDIMAGETEXTURESPROC glad_glBindImageTextures = NULL;
PFNGLBINDSAMPLERSPROC glad_glBindSamplers = NULL;
PFNGLBINDTEXTURESPROC glad_glBindTextures = NULL;
PFNGLBINDVERTEXBUFFERSPROC glad_glBindVertexBuffers = NULL;
PFNGLBUFFERSTORAGEPROC glad_glBufferStorage = NULL;
PFNGLCLEARTEXIMAGEPROC glad_glClearTexImage = NULL;
PFNGLCLEARTEXSUBIMAGEPROC glad_glClearTexSubImage = NULL;

static void GLAD_4_4::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glBufferStorage = (PFNGLBUFFERSTORAGEPROC)load("glBufferStorage");
	glad_glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)load("glClearTexImage");
	glad_glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)load("glClearTexSubImage");
	glad_glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)load("glBindBuffersBase");
	glad_glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)load("glBindBuffersRange");
	glad_glBindTextures = (PFNGLBINDTEXTURESPROC)load("glBindTextures");
	glad_glBindSamplers = (PFNGLBINDSAMPLERSPROC)load("glBindSamplers");
	glad_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)load("glBindImageTextures");
	glad_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)load("glBindVertexBuffers");

	GLAD_4_3::load_GL_RECURSIVE(load);
}