export module GLFW:Init;

#if defined(GLFW_INCLUDE_VULKAN)
import <vulkan/vulkan.h>;
#endif /* Vulkan header */

import GLFW:Types;
import GLFW:Macros;

export int glfwInit(void);
export void glfwTerminate(void);
export void glfwInitHint(int hint, int value);
export void glfwInitAllocator(const GLFWallocator* allocator);

#if defined(GLFW_INCLUDE_VULKAN) && defined(VK_VERSION_1_0)
export void glfwInitVulkanLoader(PFN_vkGetInstanceProcAddr loader);
#endif /* VK_VERSION_1_0 */

export void glfwGetVersion(int* major, int* minor, int* rev);
export int glfwGetError(const char** description);
export GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback);