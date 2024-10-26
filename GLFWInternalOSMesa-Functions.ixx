export module GLFWInternalOSMesa:Functions;

export import :Types;
export import GLFWInternalCore;

export using PFN_OSMesaCreateContextExt = OSMesaContext(*)(GLenum, GLint, GLint, GLint, OSMesaContext);
export using PFN_OSMesaCreateContextAttribs = OSMesaContext(*)(const int*, OSMesaContext);
export using PFN_OSMesaDestroyContext = void(*)(OSMesaContext);
export using PFN_OSMesaMakeCurrent = int(*)(OSMesaContext, void*, int, int, int);
export using PFN_OSMesaGetColorBuffer = int(*)(OSMesaContext, int*, int*, int*, void**);
export using PFN_OSMesaGetDepthBuffer = int(*)(OSMesaContext, int*, int*, int*, void**);
export using PFN_OSMesaGetProcAddress = GLFWglproc(*)(const char*);