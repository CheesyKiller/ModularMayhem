import <cstdint>;
export module GLFWNullPlatform:Types;

export import GLFWInternalCore;
export import GLFWCoreTypes;

export constexpr auto GLFW_NULL_SC_MENU = 120;
export constexpr auto GLFW_NULL_SC_LAST = GLFW_NULL_SC_MENU;

export constexpr auto GLFW_KEY_MENU = 348;
export constexpr auto GLFW_KEY_LAST = GLFW_KEY_MENU;

export using GLFWgammaramp = GLFWgammaramp;

// Null-specific per-window data
//
export struct _GLFWwindowNull
{
    int             xpos;
    int             ypos;
    int             width;
    int             height;
    GLFWbool        visible;
    GLFWbool        iconified;
    GLFWbool        maximized;
    GLFWbool        resizable;
    GLFWbool        decorated;
    GLFWbool        floating;
    GLFWbool        transparent;
    float           opacity;
};

// Null-specific per-monitor data
//
export struct _GLFWmonitorNull
{
    GLFWgammaramp   ramp;
};

// Null-specific global data
//
export struct _GLFWlibraryNull
{
    int             xcursor;
    int             ycursor;
    char* clipboardString;
    _GLFWwindow* focusedWindow;
    uint16_t        keycodes[GLFW_NULL_SC_LAST + 1];
    uint8_t         scancodes[GLFW_KEY_LAST + 1];
};