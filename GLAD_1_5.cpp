import <cstddef>;

import GLAD_1_5;

PFNGLGENQUERIESPROC glad_glGenQueries = NULL;
PFNGLDELETEQUERIESPROC glad_glDeleteQueries = NULL;
PFNGLISQUERYPROC glad_glIsQuery = NULL;
PFNGLBEGINQUERYPROC glad_glBeginQuery = NULL;
PFNGLENDQUERYPROC glad_glEndQuery = NULL;
PFNGLGETQUERYIVPROC glad_glGetQueryiv = NULL;
PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = NULL;
PFNGLBINDBUFFERPROC glad_glBindBuffer = NULL;
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC glad_glGenBuffers = NULL;
PFNGLISBUFFERPROC glad_glIsBuffer = NULL;
PFNGLBUFFERDATAPROC glad_glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = NULL;
PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData = NULL;
PFNGLMAPBUFFERPROC glad_glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = NULL;

static void GLAD_1_5::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glGenQueries = (PFNGLGENQUERIESPROC)load("glGenQueries");
	glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC)load("glDeleteQueries");
	glad_glIsQuery = (PFNGLISQUERYPROC)load("glIsQuery");
	glad_glBeginQuery = (PFNGLBEGINQUERYPROC)load("glBeginQuery");
	glad_glEndQuery = (PFNGLENDQUERYPROC)load("glEndQuery");
	glad_glGetQueryiv = (PFNGLGETQUERYIVPROC)load("glGetQueryiv");
	glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)load("glGetQueryObjectiv");
	glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)load("glGetQueryObjectuiv");
	glad_glBindBuffer = (PFNGLBINDBUFFERPROC)load("glBindBuffer");
	glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)load("glDeleteBuffers");
	glad_glGenBuffers = (PFNGLGENBUFFERSPROC)load("glGenBuffers");
	glad_glIsBuffer = (PFNGLISBUFFERPROC)load("glIsBuffer");
	glad_glBufferData = (PFNGLBUFFERDATAPROC)load("glBufferData");
	glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)load("glBufferSubData");
	glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)load("glGetBufferSubData");
	glad_glMapBuffer = (PFNGLMAPBUFFERPROC)load("glMapBuffer");
	glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)load("glUnmapBuffer");
	glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)load("glGetBufferParameteriv");
	glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)load("glGetBufferPointerv");

	GLAD_1_4::load_GL_RECURSIVE(load);
}