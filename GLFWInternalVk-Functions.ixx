import <cstdint>;
export module GLFWInternalVk:Functions;

import :Types;

export using PFN_vkVoidFunction = void(*)(void);

export using PFN_vkGetInstanceProcAddr = PFN_vkVoidFunction(*)(VkInstance, const char*);
export using PFN_vkEnumerateInstanceExtensionProperties = VkResult(*)(const char*, uint32_t*, VkExtensionProperties*);