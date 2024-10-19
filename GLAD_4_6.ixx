export module GLAD_4_6;

export import GLAD_4_5;

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

	export using PFNGLSPECIALIZESHADERPROC = void (APIENTRYP)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
	export using PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC = void (APIENTRYP)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	export using PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC = void (APIENTRYP)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	export using PFNGLPOLYGONOFFSETCLAMPPROC = void (APIENTRYP)(GLfloat factor, GLfloat units, GLfloat clamp);

	export extern PFNGLSPECIALIZESHADERPROC glSpecializeShader;
	export extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
	export extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
	export extern PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

export namespace GLAD_4_6 {
	void load_GL_RECURSIVE(GLADloadproc);
}