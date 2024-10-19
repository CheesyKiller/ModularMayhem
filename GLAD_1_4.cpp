import <cstddef>;

import GLAD_1_4;

PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glad_glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC glad_glPointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv = NULL;
PFNGLBLENDCOLORPROC glad_glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glad_glBlendEquation = NULL;

static void GLAD_1_4::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)load("glBlendFuncSeparate");
	glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)load("glMultiDrawArrays");
	glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)load("glMultiDrawElements");
	glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)load("glPointParameterf");
	glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)load("glPointParameterfv");
	glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC)load("glPointParameteri");
	glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)load("glPointParameteriv");
	glad_glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");

	GLAD_1_3::load_GL_RECURSIVE(load);
}