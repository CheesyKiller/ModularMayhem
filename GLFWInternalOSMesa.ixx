export module GLFWInternalOSMesa;

export import :Tokens;
export import :Types;
export import :Functions;

#define OSMesaCreateContextExt _glfw.osmesa.CreateContextExt
#define OSMesaCreateContextAttribs _glfw.osmesa.CreateContextAttribs
#define OSMesaDestroyContext _glfw.osmesa.DestroyContext
#define OSMesaMakeCurrent _glfw.osmesa.MakeCurrent
#define OSMesaGetColorBuffer _glfw.osmesa.GetColorBuffer
#define OSMesaGetDepthBuffer _glfw.osmesa.GetDepthBuffer
#define OSMesaGetProcAddress _glfw.osmesa.GetProcAddress