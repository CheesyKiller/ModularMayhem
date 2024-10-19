import <cstddef>;

import GLAD_1_3;

PFNGLACTIVETEXTUREPROC glad_glActiveTexture = NULL;
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage = NULL;

static void GLAD_1_3::load_GL_RECURSIVE(GLADloadproc load) {
	glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)load("glActiveTexture");
	glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)load("glSampleCoverage");
	glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)load("glCompressedTexImage3D");
	glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)load("glCompressedTexImage2D");
	glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)load("glCompressedTexImage1D");
	glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)load("glCompressedTexSubImage3D");
	glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)load("glCompressedTexSubImage2D");
	glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)load("glCompressedTexSubImage1D");
	glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)load("glGetCompressedTexImage");

	GLAD_1_2::load_GL_RECURSIVE(load);
}