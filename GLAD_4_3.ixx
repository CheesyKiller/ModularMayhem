export module GLAD_4_3;

export import GLAD_4_2;

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

export using PFNGLCLEARBUFFERDATAPROC = void(*)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
export using PFNGLCLEARBUFFERSUBDATAPROC = void(*)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
export using PFNGLDISPATCHCOMPUTEPROC = void(*)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
export using PFNGLDISPATCHCOMPUTEINDIRECTPROC = void(*)(GLintptr indirect);
export using PFNGLCOPYIMAGESUBDATAPROC = void(*)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
export using PFNGLFRAMEBUFFERPARAMETERIPROC = void(*)(GLenum target, GLenum pname, GLint param);
export using PFNGLGETFRAMEBUFFERPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETINTERNALFORMATI64VPROC = void(*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params);
export using PFNGLINVALIDATETEXSUBIMAGEPROC = void(*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
export using PFNGLINVALIDATETEXIMAGEPROC = void(*)(GLuint texture, GLint level);
export using PFNGLINVALIDATEBUFFERSUBDATAPROC = void(*)(GLuint buffer, GLintptr offset, GLsizeiptr length);
export using PFNGLINVALIDATEBUFFERDATAPROC = void(*)(GLuint buffer);
export using PFNGLINVALIDATEFRAMEBUFFERPROC = void(*)(GLenum target, GLsizei numAttachments, const GLenum* attachments);
export using PFNGLINVALIDATESUBFRAMEBUFFERPROC = void(*)(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
export using PFNGLMULTIDRAWARRAYSINDIRECTPROC = void(*)(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
export using PFNGLMULTIDRAWELEMENTSINDIRECTPROC = void(*)(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
export using PFNGLGETPROGRAMINTERFACEIVPROC = void(*)(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
export using PFNGLGETPROGRAMRESOURCEINDEXPROC = GLuint(*)(GLuint program, GLenum programInterface, const GLchar* name);
export using PFNGLGETPROGRAMRESOURCENAMEPROC = void(*)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
export using PFNGLGETPROGRAMRESOURCEIVPROC = void(*)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params);
export using PFNGLGETPROGRAMRESOURCELOCATIONPROC = GLint(*)(GLuint program, GLenum programInterface, const GLchar* name);
export using PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC = GLint(*)(GLuint program, GLenum programInterface, const GLchar* name);
export using PFNGLSHADERSTORAGEBLOCKBINDINGPROC = void(*)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
export using PFNGLTEXBUFFERRANGEPROC = void(*)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
export using PFNGLTEXSTORAGE2DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
export using PFNGLTEXSTORAGE3DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
export using PFNGLTEXTUREVIEWPROC = void(*)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
export using PFNGLBINDVERTEXBUFFERPROC = void(*)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
export using PFNGLVERTEXATTRIBFORMATPROC = void(*)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
export using PFNGLVERTEXATTRIBIFORMATPROC = void(*)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
export using PFNGLVERTEXATTRIBLFORMATPROC = void(*)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
export using PFNGLVERTEXATTRIBBINDINGPROC = void(*)(GLuint attribindex, GLuint bindingindex);
export using PFNGLVERTEXBINDINGDIVISORPROC = void(*)(GLuint bindingindex, GLuint divisor);
export using PFNGLDEBUGMESSAGECONTROLPROC = void(*)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
export using PFNGLDEBUGMESSAGEINSERTPROC = void(*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
export using PFNGLDEBUGMESSAGECALLBACKPROC = void(*)(GLDEBUGPROC callback, const void* userParam);
export using PFNGLGETDEBUGMESSAGELOGPROC = GLuint(*)(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
export using PFNGLPUSHDEBUGGROUPPROC = void(*)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
export using PFNGLPOPDEBUGGROUPPROC = void(*)(void);
export using PFNGLOBJECTLABELPROC = void(*)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
export using PFNGLGETOBJECTLABELPROC = void(*)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
export using PFNGLOBJECTPTRLABELPROC = void(*)(const void* ptr, GLsizei length, const GLchar* label);
export using PFNGLGETOBJECTPTRLABELPROC = void(*)(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
export using PFNGLGETPOINTERVPROC = void(*)(GLenum pname, void** params);

// Export the function pointers
export extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
export extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
export extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
export extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
export extern PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
export extern PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
export extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
export extern PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
export extern PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
export extern PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
export extern PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
export extern PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
export extern PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
export extern PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
export extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
export extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
export extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
export extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
export extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
export extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
export extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
export extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
export extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
export extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
export extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
export extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
export extern PFNGLTEXTUREVIEWPROC glTextureView;
export extern PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
export extern PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
export extern PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
export extern PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
export extern PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
export extern PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
export extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
export extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
export extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
export extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
export extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
export extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
export extern PFNGLOBJECTLABELPROC glObjectLabel;
export extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
export extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
export extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
export extern PFNGLGETPOINTERVPROC glGetPointerv;

export namespace GLAD_4_3 {
	void load_GL_RECURSIVE(GLADloadproc);
}