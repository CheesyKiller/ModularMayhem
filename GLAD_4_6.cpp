import <cstddef>;

import GLAD_4_6;

PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glad_glMultiDrawArraysIndirectCount = NULL;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glad_glMultiDrawElementsIndirectCount = NULL;
PFNGLPOLYGONOFFSETCLAMPPROC glad_glPolygonOffsetClamp = NULL;
PFNGLSPECIALIZESHADERPROC glad_glSpecializeShader = NULL;

static void GLAD_4_6::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)load("glSpecializeShader");
	glad_glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)load("glMultiDrawArraysIndirectCount");
	glad_glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)load("glMultiDrawElementsIndirectCount");
	glad_glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)load("glPolygonOffsetClamp");
	GLAD_4_5::load_GL_RECURSIVE(load);
}