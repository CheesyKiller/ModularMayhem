export module GLAD_3_3;

export import GLAD_3_2;

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
export using PFNGLBINDFRAGDATALOCATIONINDEXEDPROC = void(*)(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
export using PFNGLGETFRAGDATAINDEXPROC = GLint(*)(GLuint program, const GLchar* name);
export using PFNGLGENSAMPLERSPROC = void(*)(GLsizei count, GLuint* samplers);
export using PFNGLDELETESAMPLERSPROC = void(*)(GLsizei count, const GLuint* samplers);
export using PFNGLISSAMPLERPROC = GLboolean(*)(GLuint sampler);
export using PFNGLBINDSAMPLERPROC = void(*)(GLuint unit, GLuint sampler);
export using PFNGLSAMPLERPARAMETERIPROC = void(*)(GLuint sampler, GLenum pname, GLint param);
export using PFNGLSAMPLERPARAMETERIVPROC = void(*)(GLuint sampler, GLenum pname, const GLint* param);
export using PFNGLSAMPLERPARAMETERFPROC = void(*)(GLuint sampler, GLenum pname, GLfloat param);
export using PFNGLSAMPLERPARAMETERFVPROC = void(*)(GLuint sampler, GLenum pname, const GLfloat* param);
export using PFNGLSAMPLERPARAMETERIIVPROC = void(*)(GLuint sampler, GLenum pname, const GLint* param);
export using PFNGLSAMPLERPARAMETERIUIVPROC = void(*)(GLuint sampler, GLenum pname, const GLuint* param);
export using PFNGLGETSAMPLERPARAMETERIVPROC = void(*)(GLuint sampler, GLenum pname, GLint* params);
export using PFNGLGETSAMPLERPARAMETERIIVPROC = void(*)(GLuint sampler, GLenum pname, GLint* params);
export using PFNGLGETSAMPLERPARAMETERFVPROC = void(*)(GLuint sampler, GLenum pname, GLfloat* params);
export using PFNGLGETSAMPLERPARAMETERIUIVPROC = void(*)(GLuint sampler, GLenum pname, GLuint* params);
export using PFNGLQUERYCOUNTERPROC = void(*)(GLuint id, GLenum target);
export using PFNGLGETQUERYOBJECTI64VPROC = void(*)(GLuint id, GLenum pname, GLint64* params);
export using PFNGLGETQUERYOBJECTUI64VPROC = void(*)(GLuint id, GLenum pname, GLuint64* params);
export using PFNGLVERTEXATTRIBDIVISORPROC = void(*)(GLuint index, GLuint divisor);
export using PFNGLVERTEXATTRIBP1UIPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export using PFNGLVERTEXATTRIBP1UIVPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export using PFNGLVERTEXATTRIBP2UIPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export using PFNGLVERTEXATTRIBP2UIVPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export using PFNGLVERTEXATTRIBP3UIPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export using PFNGLVERTEXATTRIBP3UIVPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export using PFNGLVERTEXATTRIBP4UIPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export using PFNGLVERTEXATTRIBP4UIVPROC = void(*)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export using PFNGLVERTEXP2UIPROC = void(*)(GLenum type, GLuint value);
export using PFNGLVERTEXP2UIVPROC = void(*)(GLenum type, const GLuint* value);
export using PFNGLVERTEXP3UIPROC = void(*)(GLenum type, GLuint value);
export using PFNGLVERTEXP3UIVPROC = void(*)(GLenum type, const GLuint* value);
export using PFNGLVERTEXP4UIPROC = void(*)(GLenum type, GLuint value);
export using PFNGLVERTEXP4UIVPROC = void(*)(GLenum type, const GLuint* value);
export using PFNGLTEXCOORDP1UIPROC = void(*)(GLenum type, GLuint coords);
export using PFNGLTEXCOORDP1UIVPROC = void(*)(GLenum type, const GLuint* coords);
export using PFNGLTEXCOORDP2UIPROC = void(*)(GLenum type, GLuint coords);
export using PFNGLTEXCOORDP2UIVPROC = void(*)(GLenum type, const GLuint* coords);
export using PFNGLTEXCOORDP3UIPROC = void(*)(GLenum type, GLuint coords);
export using PFNGLTEXCOORDP3UIVPROC = void(*)(GLenum type, const GLuint* coords);
export using PFNGLTEXCOORDP4UIPROC = void(*)(GLenum type, GLuint coords);
export using PFNGLTEXCOORDP4UIVPROC = void(*)(GLenum type, const GLuint* coords);
export using PFNGLMULTITEXCOORDP1UIPROC = void(*)(GLenum texture, GLenum type, GLuint coords);
export using PFNGLMULTITEXCOORDP1UIVPROC = void(*)(GLenum texture, GLenum type, const GLuint* coords);
export using PFNGLMULTITEXCOORDP2UIPROC = void(*)(GLenum texture, GLenum type, GLuint coords);
export using PFNGLMULTITEXCOORDP2UIVPROC = void(*)(GLenum texture, GLenum type, const GLuint* coords);
export using PFNGLMULTITEXCOORDP3UIPROC = void(*)(GLenum texture, GLenum type, GLuint coords);
export using PFNGLMULTITEXCOORDP3UIVPROC = void(*)(GLenum texture, GLenum type, const GLuint* coords);
export using PFNGLMULTITEXCOORDP4UIPROC = void(*)(GLenum texture, GLenum type, GLuint coords);
export using PFNGLMULTITEXCOORDP4UIVPROC = void(*)(GLenum texture, GLenum type, const GLuint* coords);
export using PFNGLNORMALP3UIPROC = void(*)(GLenum type, GLuint coords);
export using PFNGLNORMALP3UIVPROC = void(*)(GLenum type, const GLuint* coords);
export using PFNGLCOLORP3UIPROC = void(*)(GLenum type, GLuint color);
export using PFNGLCOLORP3UIVPROC = void(*)(GLenum type, const GLuint* color);
export using PFNGLCOLORP4UIPROC = void(*)(GLenum type, GLuint color);
export using PFNGLCOLORP4UIVPROC = void(*)(GLenum type, const GLuint* color);
export using PFNGLSECONDARYCOLORP3UIPROC = void(*)(GLenum type, GLuint color);
export using PFNGLSECONDARYCOLORP3UIVPROC = void(*)(GLenum type, const GLuint* color);

// Declare function pointers as extern variables
export extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
export extern PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
export extern PFNGLGENSAMPLERSPROC glGenSamplers;
export extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
export extern PFNGLISSAMPLERPROC glIsSampler;
export extern PFNGLBINDSAMPLERPROC glBindSampler;
export extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
export extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
export extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
export extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
export extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
export extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
export extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
export extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
export extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
export extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
export extern PFNGLQUERYCOUNTERPROC glQueryCounter;
export extern PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
export extern PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
export extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
export extern PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
export extern PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
export extern PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
export extern PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
export extern PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
export extern PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
export extern PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
export extern PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
export extern PFNGLVERTEXP2UIPROC glVertexP2ui;
export extern PFNGLVERTEXP2UIVPROC glVertexP2uiv;
export extern PFNGLVERTEXP3UIPROC glVertexP3ui;
export extern PFNGLVERTEXP3UIVPROC glVertexP3uiv;
export extern PFNGLVERTEXP4UIPROC glVertexP4ui;
export extern PFNGLVERTEXP4UIVPROC glVertexP4uiv;
export extern PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
export extern PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
export extern PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
export extern PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
export extern PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
export extern PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
export extern PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
export extern PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
export extern PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
export extern PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
export extern PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
export extern PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
export extern PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
export extern PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
export extern PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
export extern PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
export extern PFNGLNORMALP3UIPROC glNormalP3ui;
export extern PFNGLNORMALP3UIVPROC glNormalP3uiv;
export extern PFNGLCOLORP3UIPROC glColorP3ui;
export extern PFNGLCOLORP3UIVPROC glColorP3uiv;
export extern PFNGLCOLORP4UIPROC glColorP4ui;
export extern PFNGLCOLORP4UIVPROC glColorP4uiv;
export extern PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
export extern PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;

export namespace GLAD_3_3 {
	void load_GL_RECURSIVE(GLADloadproc);
}