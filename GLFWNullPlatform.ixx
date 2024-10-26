export module GLFWNullPlatform;

export import :Types;
export import :Tokens;
export import :Functions;

import GLFWInternalEGL;
import GLFWInternalVk;

export EGLenum _glfwGetEGLPlatformNull(EGLint** attribs);
export EGLNativeDisplayType _glfwGetEGLNativeDisplayNull(void);
export EGLNativeWindowType _glfwGetEGLNativeWindowNull(_GLFWwindow* window);

export void _glfwGetRequiredInstanceExtensionsNull(char** extensions);
export GLFWbool _glfwGetPhysicalDevicePresentationSupportNull(VkInstance instance, VkPhysicalDevice device, uint32_t queuefamily);
export VkResult _glfwCreateWindowSurfaceNull(VkInstance instance, _GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);

export void _glfwPollMonitorsNull(void);