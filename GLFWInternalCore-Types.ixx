export module GLFWInternalCore:Types;

export using GLFWbool = int;

export struct _GLFWerror
{
	int         code;
	const char* description;
};

export struct _GLFWinitconfig
{
	GLFWbool hinting;
	GLFWbool resizable;
	GLFWbool visible;
	GLFWbool decorated;
	GLFWbool focused;
	GLFWbool autoIconify;
	GLFWbool floating;
	GLFWbool maximized;
	GLFWbool centerCursor;
	GLFWbool transparentFramebuffer;
	GLFWbool focusOnShow;
	GLFWbool scaleToMonitor;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWwndconfig
{
	const char* title;
	GLFWbool visible;
	GLFWbool maximized;
	GLFWbool centerCursor;
	GLFWbool transparentFramebuffer;
	GLFWbool focusOnShow;
	GLFWbool scaleToMonitor;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWctxconfig
{
	int client;
	int source;
	int major;
	int minor;
	GLFWbool forward;
	GLFWbool debug;
	GLFWbool noerror;
	GLFWbool robustness;
	GLFWbool profile;
	GLFWbool release;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWfbconfig
{
	int redBits;
	int greenBits;
	int blueBits;
	int alphaBits;
	int depthBits;
	int stencilBits;
	int accumRedBits;
	int accumGreenBits;
	int accumBlueBits;
	int accumAlphaBits;
	int auxBuffers;
	int samples;
	GLFWbool doublebuffer;
	GLFWbool stereo;
	GLFWbool sRGB;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWcontext
{
	void* client;
	int source;
	int major;
	int minor;
	GLFWbool forward;
	GLFWbool debug;
	GLFWbool noerror;
	GLFWbool robustness;
	GLFWbool profile;
	GLFWbool release;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWwindow
{
	void* client;
	const char* title;
	GLFWbool visible;
	GLFWbool maximized;
	GLFWbool centerCursor;
	GLFWbool transparentFramebuffer;
	GLFWbool focusOnShow;
	GLFWbool scaleToMonitor;
	GLFWbool cocoaRetinaFramebuffer;
	GLFWbool cocoaGraphicsSwitching;
	GLFWbool x11Primary;
	GLFWbool x11Hovered;
	GLFWbool x11Focused;
	GLFWbool x11Decorated;
	GLFWbool x11AutoIconify;
	GLFWbool x11Floating;
	GLFWbool win32ConsoleFullScreen;
	GLFWbool win32TransparentFramebuffer;
	GLFWbool win32Layered;
	GLFWbool win32Resizable;
	GLFWbool win32Visible;
	GLFWbool win32Maximized;
	GLFWbool win32CenterCursor;
	GLFWbool win32ScaleToMonitor;
	GLFWbool win32Acrylic;
	GLFWbool win32Webview;
	GLFWbool win32FocusOnShow;
	GLFWbool win32ScaleToMonitorMonitor;
	GLFWbool win32CocoaRetinaFramebuffer;
	GLFWbool win32CocoaGraphicsSwitching;
	GLFWbool win32X11Primary;
	GLFWbool win32X11Hovered;
	GLFWbool win32X11Focused;
	GLFWbool win32X11Decorated;
	GLFWbool win32X11AutoIconify;
	GLFWbool win32X11Floating;
};

export struct _GLFWplatform
{
	void* client;
};

export struct _GLFWlibrary
{
	void* client;
};

export struct _GLFWmonitor
{
	void* client;
};

export struct _GLFWcursor
{
	void* client;
};

export struct _GLFWmapelement
{
	int input;
	int type;
	int flags;
	int code;
	int state;
};

export struct _GLFWmapping
{
	int count;
	_GLFWmapelement* elements;
};

export struct _GLFWjoystick
{
	void* client;
};

export struct _GLFWtls
{
	void* client;
};

export struct _GLFWmutex
{
	void* client;
};

export using GLint = int;
export using GLuint = unsigned int;
export using GLenum = unsigned int;
export using GLbitfield = unsigned int;
export using GLubyte = unsigned char;

using PFNGLCLEARPROC = void (*)(GLbitfield);
using PFNGLGETSTRINGPROC = const GLubyte* (*)(GLenum);
using PFNGLGETINTEGERVPROC = void (*)(GLenum, GLint*);
using PFNGLGETSTRINGIPROC = const GLubyte* (*)(GLenum, GLuint);