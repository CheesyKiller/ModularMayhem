export module GLAD_1_0;

export import GLAD_BASE;

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

// Alias for function pointer types
export using PFNGLCULLFACEPROC = void(*)(GLenum mode);
export using PFNGLFRONTFACEPROC = void(*)(GLenum mode);
export using PFNGLHINTPROC = void(*)(GLenum target, GLenum mode);
export using PFNGLLINEWIDTHPROC = void(*)(GLfloat width);
export using PFNGLPOINTSIZEPROC = void(*)(GLfloat size);
export using PFNGLPOLYGONMODEPROC = void(*)(GLenum face, GLenum mode);
export using PFNGLSCISSORPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height);
export using PFNGLTEXPARAMETERFPROC = void(*)(GLenum target, GLenum pname, GLfloat param);
export using PFNGLTEXPARAMETERFVPROC = void(*)(GLenum target, GLenum pname, const GLfloat* params);
export using PFNGLTEXPARAMETERIPROC = void(*)(GLenum target, GLenum pname, GLint param);
export using PFNGLTEXPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, const GLint* params);
export using PFNGLTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
export using PFNGLTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
export using PFNGLDRAWBUFFERPROC = void(*)(GLenum buf);
export using PFNGLCLEARPROC = void(*)(GLbitfield mask);
export using PFNGLCLEARCOLORPROC = void(*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
export using PFNGLCLEARSTENCILPROC = void(*)(GLint s);
export using PFNGLCLEARDEPTHPROC = void(*)(GLdouble depth);
export using PFNGLSTENCILMASKPROC = void(*)(GLuint mask);
export using PFNGLCOLORMASKPROC = void(*)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
export using PFNGLDEPTHMASKPROC = void(*)(GLboolean flag);
export using PFNGLDISABLEPROC = void(*)(GLenum cap);
export using PFNGLENABLEPROC = void(*)(GLenum cap);
export using PFNGLFINISHPROC = void(*)(void);
export using PFNGLFLUSHPROC = void(*)(void);
export using PFNGLBLENDFUNCPROC = void(*)(GLenum sfactor, GLenum dfactor);
export using PFNGLLOGICOPPROC = void(*)(GLenum opcode);
export using PFNGLSTENCILFUNCPROC = void(*)(GLenum func, GLint ref, GLuint mask);
export using PFNGLSTENCILOPPROC = void(*)(GLenum fail, GLenum zfail, GLenum zpass);
export using PFNGLDEPTHFUNCPROC = void(*)(GLenum func);
export using PFNGLPIXELSTOREFPROC = void(*)(GLenum pname, GLfloat param);
export using PFNGLPIXELSTOREIPROC = void(*)(GLenum pname, GLint param);
export using PFNGLREADBUFFERPROC = void(*)(GLenum src);
export using PFNGLREADPIXELSPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
export using PFNGLGETBOOLEANVPROC = void(*)(GLenum pname, GLboolean* data);
export using PFNGLGETDOUBLEVPROC = void(*)(GLenum pname, GLdouble* data);
export using PFNGLGETERRORPROC = GLenum(*)(void);
export using PFNGLGETFLOATVPROC = void(*)(GLenum pname, GLfloat* data);
export using PFNGLGETINTEGERVPROC = void(*)(GLenum pname, GLint* data);
export using PFNGLGETSTRINGPROC = const GLubyte* (*)(GLenum name);
export using PFNGLGETTEXIMAGEPROC = void(*)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
export using PFNGLGETTEXPARAMETERFVPROC = void(*)(GLenum target, GLenum pname, GLfloat* params);
export using PFNGLGETTEXPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETTEXLEVELPARAMETERFVPROC = void(*)(GLenum target, GLint level, GLenum pname, GLfloat* params);
export using PFNGLGETTEXLEVELPARAMETERIVPROC = void(*)(GLenum target, GLint level, GLenum pname, GLint* params);
export using PFNGLISENABLEDPROC = GLboolean(*)(GLenum cap);
export using PFNGLDEPTHRANGEPROC = void(*)(GLdouble n, GLdouble f);
export using PFNGLVIEWPORTPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height);

// Declare function pointers as extern variables
export extern PFNGLCULLFACEPROC glCullFace;
export extern PFNGLFRONTFACEPROC glFrontFace;
export extern PFNGLHINTPROC glHint;
export extern PFNGLLINEWIDTHPROC glLineWidth;
export extern PFNGLPOINTSIZEPROC glPointSize;
export extern PFNGLPOLYGONMODEPROC glPolygonMode;
export extern PFNGLSCISSORPROC glScissor;
export extern PFNGLTEXPARAMETERFPROC glTexParameterf;
export extern PFNGLTEXPARAMETERFVPROC glTexParameterfv;
export extern PFNGLTEXPARAMETERIPROC glTexParameteri;
export extern PFNGLTEXPARAMETERIVPROC glTexParameteriv;
export extern PFNGLTEXIMAGE1DPROC glTexImage1D;
export extern PFNGLTEXIMAGE2DPROC glTexImage2D;
export extern PFNGLDRAWBUFFERPROC glDrawBuffer;
export extern PFNGLCLEARPROC glClear;
export extern PFNGLCLEARCOLORPROC glClearColor;
export extern PFNGLCLEARSTENCILPROC glClearStencil;
export extern PFNGLCLEARDEPTHPROC glClearDepth;
export extern PFNGLSTENCILMASKPROC glStencilMask;
export extern PFNGLCOLORMASKPROC glColorMask;
export extern PFNGLDEPTHMASKPROC glDepthMask;
export extern PFNGLDISABLEPROC glDisable;
export extern PFNGLENABLEPROC glEnable;
export extern PFNGLFINISHPROC glFinish;
export extern PFNGLFLUSHPROC glFlush;
export extern PFNGLBLENDFUNCPROC glBlendFunc;
export extern PFNGLLOGICOPPROC glLogicOp;
export extern PFNGLSTENCILFUNCPROC glStencilFunc;
export extern PFNGLSTENCILOPPROC glStencilOp;
export extern PFNGLDEPTHFUNCPROC glDepthFunc;
export extern PFNGLPIXELSTOREFPROC glPixelStoref;
export extern PFNGLPIXELSTOREIPROC glPixelStorei;
export extern PFNGLREADBUFFERPROC glReadBuffer;
export extern PFNGLREADPIXELSPROC glReadPixels;
export extern PFNGLGETBOOLEANVPROC glGetBooleanv;
export extern PFNGLGETDOUBLEVPROC glGetDoublev;
export extern PFNGLGETERRORPROC glGetError;
export extern PFNGLGETFLOATVPROC glGetFloatv;
export extern PFNGLGETINTEGERVPROC glGetIntegerv;
export extern PFNGLGETSTRINGPROC glGetString;
export extern PFNGLGETTEXIMAGEPROC glGetTexImage;
export extern PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
export extern PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
export extern PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
export extern PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
export extern PFNGLISENABLEDPROC glIsEnabled;
export extern PFNGLDEPTHRANGEPROC glDepthRange;
export extern PFNGLVIEWPORTPROC glViewport;

export namespace GLAD_1_0 {
	void load_GL_RECURSIVE(GLADloadproc);
}