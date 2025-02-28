export module GLFWCoreTypes;

/*************************************************************************
 * GLFW API types
 *************************************************************************/

 /*! @brief Client API function pointer type.
  *
  *  Generic function pointer used for returning client API function pointers
  *  without forcing a cast from a regular pointer.
  *
  *  @sa @ref context_glext
  *  @sa @ref glfwGetProcAddress
  *
  *  @since Added in version 3.0.
  *
  *  @ingroup context
  */
export using GLFWglproc = void (*)(void);

/*! @brief Vulkan API function pointer type.
 *
 *  Generic function pointer used for returning Vulkan API function pointers
 *  without forcing a cast from a regular pointer.
 *
 *  @sa @ref vulkan_proc
 *  @sa @ref glfwGetInstanceProcAddress
 *
 *  @since Added in version 3.2.
 *
 *  @ingroup vulkan
 */
export using GLFWvkproc = void (*)(void);

/*! @brief Opaque monitor object.
 *
 *  Opaque monitor object.
 *
 *  @see @ref monitor_object
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup monitor
 */
export struct GLFWmonitor;  // Forward declaration

/*! @brief Opaque window object.
 *
 *  Opaque window object.
 *
 *  @see @ref window_object
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup window
 */
export struct GLFWwindow;  // Forward declaration

/*! @brief Opaque cursor object.
 *
 *  Opaque cursor object.
 *
 *  @see @ref cursor_object
 *
 *  @since Added in version 3.1.
 *
 *  @ingroup input
 */
export struct GLFWcursor;  // Forward declaration

/*! @brief The function pointer type for memory allocation callbacks.
 *
 *  This is the function pointer type for memory allocation callbacks. A memory
 *  allocation callback function has the following signature:
 *  @code
 *  void* function_name(size_t size, void* user)
 *  @endcode
 *
 *  This function must return either a memory block at least `size` bytes long,
 *  or `NULL` if allocation failed. Note that not all parts of GLFW handle allocation
 *  failures gracefully yet.
 *
 *  This function must support being called during @ref glfwInit but before the library is
 *  flagged as initialized, as well as during @ref glfwTerminate after the library is no
 *  longer flagged as initialized.
 *
 *  Any memory allocated via this function will be deallocated via the same allocator
 *  during library termination or earlier.
 *
 *  Any memory allocated via this function must be suitably aligned for any object type.
 *  If you are using C99 or earlier, this alignment is platform-dependent but will be the
 *  same as what `malloc` provides. If you are using C11 or later, this is the value of
 *  `alignof(max_align_t)`.
 *
 *  The size will always be greater than zero. Allocations of size zero are filtered out
 *  before reaching the custom allocator.
 *
 *  If this function returns `NULL`, GLFW will emit @ref GLFW_OUT_OF_MEMORY.
 *
 *  This function must not call any GLFW function.
 *
 *  @param[in] size The minimum size, in bytes, of the memory block.
 *  @param[in] user The user-defined pointer from the allocator.
 *  @return The address of the newly allocated memory block, or `NULL` if an
 *  error occurred.
 *
 *  @pointer_lifetime The returned memory block must be valid at least until it
 *  is deallocated.
 *
 *  @reentrancy This function should not call any GLFW function.
 *
 *  @thread_safety This function must support being called from any thread that calls GLFW
 *  functions.
 *
 *  @sa @ref init_allocator
 *  @sa @ref GLFWallocator
 *
 *  @since Added in version 3.4.
 *
 *  @ingroup init
 */
export using GLFWallocatefun = void* (*)(size_t size, void* user);

/*! @brief The function pointer type for memory reallocation callbacks.
 *
 *  This is the function pointer type for memory reallocation callbacks.
 *  A memory reallocation callback function has the following signature:
 *  @code
 *  void* function_name(void* block, size_t size, void* user)
 *  @endcode
 *
 *  This function must return a memory block at least `size` bytes long, or
 *  `NULL` if allocation failed. Note that not all parts of GLFW handle allocation
 *  failures gracefully yet.
 *
 *  This function must support being called during @ref glfwInit but before the library is
 *  flagged as initialized, as well as during @ref glfwTerminate after the library is no
 *  longer flagged as initialized.
 *
 *  Any memory allocated via this function will be deallocated via the same allocator
 *  during library termination or earlier.
 *
 *  Any memory allocated via this function must be suitably aligned for any object type.
 *  If you are using C99 or earlier, this alignment is platform-dependent but will be the
 *  same as what `realloc` provides. If you are using C11 or later, this is the value of
 *  `alignof(max_align_t)`.
 *
 *  The block address will never be `NULL` and the size will always be greater than zero.
 *  Reallocations of a block to size zero are converted into deallocations before reaching
 *  the custom allocator. Reallocations of `NULL` to a non-zero size are converted into
 *  regular allocations before reaching the custom allocator.
 *
 *  If this function returns `NULL`, GLFW will emit @ref GLFW_OUT_OF_MEMORY.
 *
 *  This function must not call any GLFW function.
 *
 *  @param[in] block The address of the memory block to reallocate.
 *  @param[in] size The new minimum size, in bytes, of the memory block.
 *  @param[in] user The user-defined pointer from the allocator.
 *  @return The address of the newly allocated or resized memory block, or
 *  `NULL` if an error occurred.
 *
 *  @pointer_lifetime The returned memory block must be valid at least until it
 *  is deallocated.
 *
 *  @reentrancy This function should not call any GLFW function.
 *
 *  @thread_safety This function must support being called from any thread that calls GLFW
 *  functions.
 *
 *  @sa @ref init_allocator
 *  @sa @ref GLFWallocator
 *
 *  @since Added in version 3.4.
 *
 *  @ingroup init
 */
export using GLFWreallocatefun = void* (*)(void* block, size_t size, void* user);

/*! @brief The function pointer type for memory deallocation callbacks.
 *
 *  This is the function pointer type for memory deallocation callbacks.
 *  A memory deallocation callback function has the following signature:
 *  @code
 *  void function_name(void* block, void* user)
 *  @endcode
 *
 *  This function may deallocate the specified memory block. This memory block
 *  will have been allocated with the same allocator.
 *
 *  This function must support being called during @ref glfwInit but before the library is
 *  flagged as initialized, as well as during @ref glfwTerminate after the library is no
 *  longer flagged as initialized.
 *
 *  The block address will never be `NULL`. Deallocations of `NULL` are filtered out
 *  before reaching the custom allocator.
 *
 *  If this function returns `NULL`, GLFW will emit @ref GLFW_OUT_OF_MEMORY.
 *
 *  This function must not call any GLFW function.
 *
 *  @param[in] block The address of the memory block to deallocate.
 *  @param[in] user The user-defined pointer from the allocator.
 *
 *  @pointer_lifetime The specified memory block will not be accessed by GLFW
 *  after this function is called.
 *
 *  @reentrancy This function should not call any GLFW function.
 *
 *  @thread_safety This function must support being called from any thread that calls GLFW
 *  functions.
 *
 *  @sa @ref init_allocator
 *  @sa @ref GLFWallocator
 *
 *  @since Added in version 3.4.
 *
 *  @ingroup init
 */
export using GLFWdeallocatefun = void (*)(void* block, void* user);

/*! @brief The function pointer type for error callbacks.
 *
 *  This is the function pointer type for error callbacks. An error callback
 *  function has the following signature:
 *  @code
 *  void callback_name(int error_code, const char* description)
 *  @endcode
 *
 *  @param[in] error_code An [error code](@ref errors). Future releases may add
 *  more error codes.
 *  @param[in] description A UTF-8 encoded string describing the error.
 *
 *  @pointer_lifetime The error description string is valid until the callback
 *  function returns.
 *
 *  @sa @ref error_handling
 *  @sa @ref glfwSetErrorCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup init
 */
export using GLFWerrorfun = void (*)(int error_code, const char* description);

/*! @brief The function pointer type for window position callbacks.
 *
 *  This is the function pointer type for window position callbacks. A window
 *  position callback function has the following signature:
 *  @code
 *  void callback_name(GLFWwindow* window, int xpos, int ypos)
 *  @endcode
 *
 *  @param[in] window The window that was moved.
 *  @param[in] xpos The new x-coordinate, in screen coordinates, of the
 *  upper-left corner of the content area of the window.
 *  @param[in] ypos The new y-coordinate, in screen coordinates, of the
 *  upper-left corner of the content area of the window.
 *
 *  @sa @ref window_pos
 *  @sa @ref glfwSetWindowPosCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup window
 */
export using GLFWwindowposfun = void (*)(GLFWwindow* window, int xpos, int ypos);

/*! @brief The function pointer type for window size callbacks.
 *
 *  This is the function pointer type for window size callbacks. A window size
 *  callback function has the following signature:
 *  @code
 *  void callback_name(GLFWwindow* window, int width, int height)
 *  @endcode
 *
 *  @param[in] window The window that was resized.
 *  @param[in] width The new width, in screen coordinates, of the window.
 *  @param[in] height The new height, in screen coordinates, of the window.
 *
 *  @sa @ref window_size
 *  @sa @ref glfwSetWindowSizeCallback
 *
 *  @since Added in version 1.0.
 *  @glfw3 Added window handle parameter.
 *
 *  @ingroup window
 */
export using GLFWwindowsizefun = void (*)(GLFWwindow* window, int width, int height);

/*! @brief The function pointer type for window close callbacks.
 *
 *  This is the function pointer type for window close callbacks. A window
 *  close callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window)
 *  @endcode
 *
 *  @param[in] window The window that the user attempted to close.
 *
 *  @sa @ref window_close
 *  @sa @ref glfwSetWindowCloseCallback
 *
 *  @since Added in version 2.5.
 *  @glfw3 Added window handle parameter.
 *
 *  @ingroup window
 */
export using GLFWwindowclosefun = void (*)(GLFWwindow* window);

/*! @brief The function pointer type for window content refresh callbacks.
 *
 *  This is the function pointer type for window content refresh callbacks.
 *  A window content refresh callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window);
 *  @endcode
 *
 *  @param[in] window The window whose content needs to be refreshed.
 *
 *  @sa @ref window_refresh
 *  @sa @ref glfwSetWindowRefreshCallback
 *
 *  @since Added in version 2.5.
 *  @glfw3 Added window handle parameter.
 *
 *  @ingroup window
 */
export using GLFWwindowrefreshfun = void (*)(GLFWwindow* window);

/*! @brief The function pointer type for window focus callbacks.
 *
 *  This is the function pointer type for window focus callbacks. A window
 *  focus callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int focused)
 *  @endcode
 *
 *  @param[in] window The window that gained or lost input focus.
 *  @param[in] focused `GLFW_TRUE` if the window was given input focus, or
 *  `GLFW_FALSE` if it lost it.
 *
 *  @sa @ref window_focus
 *  @sa @ref glfwSetWindowFocusCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup window
 */
export using GLFWwindowfocusfun = void (*)(GLFWwindow* window, int focused);

/*! @brief The function pointer type for window iconify callbacks.
 *
 *  This is the function pointer type for window iconify callbacks. A window
 *  iconify callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int iconified)
 *  @endcode
 *
 *  @param[in] window The window that was iconified or restored.
 *  @param[in] iconified `GLFW_TRUE` if the window was iconified, or
 *  `GLFW_FALSE` if it was restored.
 *
 *  @sa @ref window_iconify
 *  @sa @ref glfwSetWindowIconifyCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup window
 */
export using GLFWwindowiconifyfun = void (*)(GLFWwindow* window, int iconified);

/*! @brief The function pointer type for window maximize callbacks.
 *
 *  This is the function pointer type for window maximize callbacks. A window
 *  maximize callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int maximized)
 *  @endcode
 *
 *  @param[in] window The window that was maximized or restored.
 *  @param[in] maximized `GLFW_TRUE` if the window was maximized, or
 *  `GLFW_FALSE` if it was restored.
 *
 *  @sa @ref window_maximize
 *  @sa glfwSetWindowMaximizeCallback
 *
 *  @since Added in version 3.3.
 *
 *  @ingroup window
 */
export using GLFWwindowmaximizefun = void (*)(GLFWwindow* window, int maximized);

/*! @brief The function pointer type for framebuffer size callbacks.
 *
 *  This is the function pointer type for framebuffer size callbacks.
 *  A framebuffer size callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int width, int height)
 *  @endcode
 *
 *  @param[in] window The window whose framebuffer was resized.
 *  @param[in] width The new width, in pixels, of the framebuffer.
 *  @param[in] height The new height, in pixels, of the framebuffer.
 *
 *  @sa @ref window_fbsize
 *  @sa @ref glfwSetFramebufferSizeCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup window
 */
export using GLFWframebuffersizefun = void (*)(GLFWwindow* window, int width, int height);

/*! @brief The function pointer type for window content scale callbacks.
 *
 *  This is the function pointer type for window content scale callbacks.
 *  A window content scale callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, float xscale, float yscale)
 *  @endcode
 *
 *  @param[in] window The window whose content scale changed.
 *  @param[in] xscale The new x-axis content scale of the window.
 *  @param[in] yscale The new y-axis content scale of the window.
 *
 *  @sa @ref window_scale
 *  @sa @ref glfwSetWindowContentScaleCallback
 *
 *  @since Added in version 3.3.
 *
 *  @ingroup window
 */
export using GLFWwindowcontentscalefun = void (*)(GLFWwindow* window, float xscale, float yscale);

/*! @brief The function pointer type for mouse button callbacks.
 *
 *  This is the function pointer type for mouse button callback functions.
 *  A mouse button callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int button, int action, int mods)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] button The [mouse button](@ref buttons) that was pressed or
 *  released.
 *  @param[in] action One of `GLFW_PRESS` or `GLFW_RELEASE`. Future releases
 *  may add more actions.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_mouse_button
 *  @sa @ref glfwSetMouseButtonCallback
 *
 *  @since Added in version 1.0.
 *  @glfw3 Added window handle and modifier mask parameters.
 *
 *  @ingroup input
 */
export using GLFWmousebuttonfun = void (*)(GLFWwindow* window, int button, int action, int mods);

/*! @brief The function pointer type for cursor position callbacks.
 *
 *  This is the function pointer type for cursor position callbacks. A cursor
 *  position callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, double xpos, double ypos);
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] xpos The new cursor x-coordinate, relative to the left edge of
 *  the content area.
 *  @param[in] ypos The new cursor y-coordinate, relative to the top edge of the
 *  content area.
 *
 *  @sa @ref cursor_pos
 *  @sa @ref glfwSetCursorPosCallback
 *
 *  @since Added in version 3.0. Replaces `GLFWmouseposfun`.
 *
 *  @ingroup input
 */
export using GLFWcursorposfun = void (*)(GLFWwindow* window, double xpos, double ypos);

/*! @brief The function pointer type for cursor enter/leave callbacks.
 *
 *  This is the function pointer type for cursor enter/leave callbacks.
 *  A cursor enter/leave callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int entered)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] entered `GLFW_TRUE` if the cursor entered the window's content
 *  area, or `GLFW_FALSE` if it left it.
 *
 *  @sa @ref cursor_enter
 *  @sa @ref glfwSetCursorEnterCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup input
 */
export using GLFWcursorenterfun = void (*)(GLFWwindow* window, int entered);

/*! @brief The function pointer type for scroll callbacks.
 *
 *  This is the function pointer type for scroll callbacks. A scroll callback
 *  function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, double xoffset, double yoffset)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] xoffset The scroll offset along the x-axis.
 *  @param[in] yoffset The scroll offset along the y-axis.
 *
 *  @sa @ref scrolling
 *  @sa @ref glfwSetScrollCallback
 *
 *  @since Added in version 3.0. Replaces `GLFWmousewheelfun`.
 *
 *  @ingroup input
 */
export using GLFWscrollfun = void (*)(GLFWwindow* window, double xoffset, double yoffset);

/*! @brief The function pointer type for keyboard key callbacks.
 *
 *  This is the function pointer type for keyboard key callbacks. A keyboard
 *  key callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int key, int scancode, int action, int mods)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] key The [keyboard key](@ref keys) that was pressed or released.
 *  @param[in] scancode The platform-specific scancode of the key.
 *  @param[in] action `GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`. Future
 *  releases may add more actions.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_key
 *  @sa @ref glfwSetKeyCallback
 *
 *  @since Added in version 1.0.
 *  @glfw3 Added window handle, scancode and modifier mask parameters.
 *
 *  @ingroup input
 */
export using GLFWkeyfun = void (*)(GLFWwindow* window, int key, int scancode, int action, int mods);

/*! @brief The function pointer type for Unicode character callbacks.
 *
 *  This is the function pointer type for Unicode character callbacks.
 *  A Unicode character callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, unsigned int codepoint)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] codepoint The Unicode code point of the character.
 *
 *  @sa @ref input_char
 *  @sa @ref glfwSetCharCallback
 *
 *  @since Added in version 2.4.
 *  @glfw3 Added window handle parameter.
 *
 *  @ingroup input
 */
export using GLFWcharfun = void (*)(GLFWwindow* window, unsigned int codepoint);

/*! @brief The function pointer type for Unicode character with modifiers
 *  callbacks.
 *
 *  This is the function pointer type for Unicode character with modifiers
 *  callbacks. It is called for each input character, regardless of what
 *  modifier keys are held down. A Unicode character with modifiers callback
 *  function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, unsigned int codepoint, int mods)
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] codepoint The Unicode code point of the character.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_char
 *  @sa @ref glfwSetCharModsCallback
 *
 *  @deprecated Scheduled for removal in version 4.0.
 *
 *  @since Added in version 3.1.
 *
 *  @ingroup input
 */
export using GLFWcharmodsfun = void (*)(GLFWwindow* window, unsigned int codepoint, int mods);

/*! @brief The function pointer type for path drop callbacks.
 *
 *  This is the function pointer type for path drop callbacks. A path drop
 *  callback function has the following signature:
 *  @code
 *  void function_name(GLFWwindow* window, int path_count, const char* paths[])
 *  @endcode
 *
 *  @param[in] window The window that received the event.
 *  @param[in] path_count The number of dropped paths.
 *  @param[in] paths The UTF-8 encoded file and/or directory path names.
 *
 *  @pointer_lifetime The path array and its strings are valid until the
 *  callback function returns.
 *
 *  @sa @ref path_drop
 *  @sa @ref glfwSetDropCallback
 *
 *  @since Added in version 3.1.
 *
 *  @ingroup input
 */
export using GLFWdropfun = void (*)(GLFWwindow* window, int path_count, const char* paths[]);

/*! @brief The function pointer type for monitor configuration callbacks.
 *
 *  This is the function pointer type for monitor configuration callbacks.
 *  A monitor callback function has the following signature:
 *  @code
 *  void function_name(GLFWmonitor* monitor, int event)
 *  @endcode
 *
 *  @param[in] monitor The monitor that was connected or disconnected.
 *  @param[in] event One of `GLFW_CONNECTED` or `GLFW_DISCONNECTED`. Future
 *  releases may add more events.
 *
 *  @sa @ref monitor_event
 *  @sa @ref glfwSetMonitorCallback
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup monitor
 */
export using GLFWmonitorfun = void (*)(GLFWmonitor* monitor, int event);

/*! @brief The function pointer type for joystick configuration callbacks.
 *
 *  This is the function pointer type for joystick configuration callbacks.
 *  A joystick configuration callback function has the following signature:
 *  @code
 *  void function_name(int jid, int event)
 *  @endcode
 *
 *  @param[in] jid The joystick that was connected or disconnected.
 *  @param[in] event One of `GLFW_CONNECTED` or `GLFW_DISCONNECTED`. Future
 *  releases may add more events.
 *
 *  @sa @ref joystick_event
 *  @sa @ref glfwSetJoystickCallback
 *
 *  @since Added in version 3.2.
 *
 *  @ingroup input
 */
export using GLFWjoystickfun = void (*)(int jid, int event);

/*! @brief Video mode type.
 *
 *  This describes a single video mode.
 *
 *  @sa @ref monitor_modes
 *  @sa @ref glfwGetVideoMode
 *  @sa @ref glfwGetVideoModes
 *
 *  @since Added in version 1.0.
 *  @glfw3 Added refresh rate member.
 *
 *  @ingroup monitor
 */
export struct GLFWvidmode
{
    /*! The width, in screen coordinates, of the video mode.
     */
    int width;
    /*! The height, in screen coordinates, of the video mode.
     */
    int height;
    /*! The bit depth of the red channel of the video mode.
     */
    int redBits;
    /*! The bit depth of the green channel of the video mode.
     */
    int greenBits;
    /*! The bit depth of the blue channel of the video mode.
     */
    int blueBits;
    /*! The refresh rate, in Hz, of the video mode.
     */
    int refreshRate;
};

/*! @brief Gamma ramp.
 *
 *  This describes the gamma ramp for a monitor.
 *
 *  @sa @ref monitor_gamma
 *  @sa @ref glfwGetGammaRamp
 *  @sa @ref glfwSetGammaRamp
 *
 *  @since Added in version 3.0.
 *
 *  @ingroup monitor
 */
export struct GLFWgammaramp
{
    /*! An array of value describing the response of the red channel.
     */
    unsigned short* red;
    /*! An array of value describing the response of the green channel.
     */
    unsigned short* green;
    /*! An array of value describing the response of the blue channel.
     */
    unsigned short* blue;
    /*! The number of elements in each array.
     */
    unsigned int size;
};

/*! @brief Image data.
 *
 *  This describes a single 2D image. See the documentation for each related
 *  function what the expected pixel format is.
 *
 *  @sa @ref cursor_custom
 *  @sa @ref window_icon
 *
 *  @since Added in version 2.1.
 *  @glfw3 Removed format and bytes-per-pixel members.
 *
 *  @ingroup window
 */
export struct GLFWimage
{
    /*! The width, in pixels, of this image.
     */
    int width;
    /*! The height, in pixels, of this image.
     */
    int height;
    /*! The pixel data of this image, arranged left-to-right, top-to-bottom.
     */
    unsigned char* pixels;
};

/*! @brief Gamepad input state
 *
 *  This describes the input state of a gamepad.
 *
 *  @sa @ref gamepad
 *  @sa @ref glfwGetGamepadState
 *
 *  @since Added in version 3.3.
 *
 *  @ingroup input
 */
export struct GLFWgamepadstate
{
    /*! The states of each [gamepad button](@ref gamepad_buttons), `GLFW_PRESS`
     *  or `GLFW_RELEASE`.
     */
    unsigned char buttons[15];
    /*! The states of each [gamepad axis](@ref gamepad_axes), in the range -1.0
     *  to 1.0 inclusive.
     */
    float axes[6];
};

/*! @brief Custom heap memory allocator.
 *
 *  This describes a custom heap memory allocator for GLFW. To set an allocator, pass it
 *  to @ref glfwInitAllocator before initializing the library.
 *
 *  @sa @ref init_allocator
 *  @sa @ref glfwInitAllocator
 *
 *  @since Added in version 3.4.
 *
 *  @ingroup init
 */
export struct GLFWallocator
{
    /*! The memory allocation function. See @ref GLFWallocatefun for details about
     *  allocation function.
     */
    GLFWallocatefun allocate;
    /*! The memory reallocation function. See @ref GLFWreallocatefun for details about
     *  reallocation function.
     */
    GLFWreallocatefun reallocate;
    /*! The memory deallocation function. See @ref GLFWdeallocatefun for details about
     *  deallocation function.
     */
    GLFWdeallocatefun deallocate;
    /*! The user pointer for this custom allocator. This value will be passed to the
     *  allocator functions.
     */
    void* user;
};