export module GLFW:Types;

export using GLFWglproc = void(*)(void);
export using GLFWvkproc = void(*)(void);

export struct GLFWmonitor;
export struct GLFWwindow;
export struct GLFWcursor;

export using GLFWallocatefun = void* (*)(size_t size, void* user);
export using GLFWreallocatefun = void* (*)(void* block, size_t size, void* user);
export using GLFWdeallocatefun = void (*)(void* block, void* user);
export using GLFWerrorfun = void (*)(int error_code, const char* description);
export using GLFWwindowposfun = void (*)(GLFWwindow* window, int xpos, int ypos);
export using GLFWwindowsizefun = void (*)(GLFWwindow* window, int width, int height);
export using GLFWwindowclosefun = void (*)(GLFWwindow* window);
export using GLFWwindowrefreshfun = void (*)(GLFWwindow* window);
export using GLFWwindowfocusfun = void (*)(GLFWwindow* window, int focused);
export using GLFWwindowiconifyfun = void (*)(GLFWwindow* window, int iconified);
export using GLFWwindowmaximizefun = void (*)(GLFWwindow* window, int maximized);
export using GLFWframebuffersizefun = void (*)(GLFWwindow* window, int width, int height);
export using GLFWwindowcontentscalefun = void (*)(GLFWwindow* window, float xscale, float yscale);
export using GLFWmousebuttonfun = void (*)(GLFWwindow* window, int button, int action, int mods);
export using GLFWcursorposfun = void (*)(GLFWwindow* window, double xpos, double ypos);
export using GLFWcursorenterfun = void (*)(GLFWwindow* window, int entered);
export using GLFWscrollfun = void (*)(GLFWwindow* window, double xoffset, double yoffset);
export using GLFWkeyfun = void (*)(GLFWwindow* window, int key, int scancode, int action, int mods);
export using GLFWcharfun = void (*)(GLFWwindow* window, unsigned int codepoint);
export using GLFWcharmodsfun = void (*)(GLFWwindow* window, unsigned int codepoint, int mods);
export using GLFWdropfun = void (*)(GLFWwindow* window, int path_count, const char* paths[]);
export using GLFWmonitorfun = void (*)(GLFWmonitor* monitor, int event);
export using GLFWjoystickfun = void (*)(int jid, int event);

export struct GLFWvidmode
{
    int width;
    int height;
    int redBits;
    int greenBits;
    int blueBits;
    int refreshRate;
};

export struct GLFWgammaramp
{
    unsigned short* red;
    unsigned short* green;
    unsigned short* blue;
    unsigned int size;
};

export struct GLFWimage
{
    int width;
    int height;
    unsigned char* pixels;
};

export struct GLFWgamepadstate
{
    unsigned char buttons[15];
    float axes[6];
};

export struct GLFWallocator
{
    GLFWallocatefun allocate;
    GLFWreallocatefun reallocate;
    GLFWdeallocatefun deallocate;
    void* user;
};