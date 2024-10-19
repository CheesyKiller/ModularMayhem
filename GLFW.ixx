export module GLFW;

/*************************************************************************
 * GLFW 3.4 - www.glfw.org
 * A library for OpenGL, window and input
 *------------------------------------------------------------------------
 * Copyright (c) 2002-2006 Marcus Geelnard
 * Copyright (c) 2006-2019 Camilla Löwy <elmindreda@glfw.org>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would
 *    be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not
 *    be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 *    distribution.
 *
 * NOTE: This is an extremely modified version of GLFW 3.4. It has been
 * modified to be a module instead of a single-file header library.
 * Additionally, the GL headers have been supplimented with a custom
 * GLAD module, based aroound GLAD 4.6. That module has also been modified
 * to take a custom KHR module... They will all be built together in this
 * CMake project.
 *************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

import <stddef.h>;
import <stdint.h>;

#if defined(GLFW_INCLUDE_VULKAN)
import <vulkan/vulkan.h>;
#endif /* Vulkan header */

import GLAD;

#if defined(GLFW_DLL) && defined(_GLFW_BUILD_DLL)
	/* GLFW_DLL must be defined by applications that are linking against the DLL
	 * version of the GLFW library.  _GLFW_BUILD_DLL is defined by the GLFW
	 * configuration header when compiling the DLL version of the library.
	 */
#error "You must not have both GLFW_DLL and _GLFW_BUILD_DLL defined"
#endif

import GLFW:Macros;
import GLFW:Types;
import GLFWInit;

	 /*************************************************************************
	  * GLFW API functions
	  *************************************************************************/
	/*
	export const char* glfwGetVersionString(void);
	export int glfwGetPlatform(void);
	export int glfwPlatformSupported(int platform);
	export GLFWmonitor** glfwGetMonitors(int* count);
	export GLFWmonitor* glfwGetPrimaryMonitor(void);
	export void glfwGetMonitorPos(GLFWmonitor* monitor, int* xpos, int* ypos);
	export void glfwGetMonitorWorkarea(GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height);
	export void glfwGetMonitorPhysicalSize(GLFWmonitor* monitor, int* widthMM, int* heightMM);
	export void glfwGetMonitorContentScale(GLFWmonitor* monitor, float* xscale, float* yscale);
	export const char* glfwGetMonitorName(GLFWmonitor* monitor);
	export void glfwSetMonitorUserPointer(GLFWmonitor* monitor, void* pointer);
	export void* glfwGetMonitorUserPointer(GLFWmonitor* monitor);
	export GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun callback);
	export const GLFWvidmode* glfwGetVideoModes(GLFWmonitor* monitor, int* count);
	export const GLFWvidmode* glfwGetVideoMode(GLFWmonitor* monitor);
	export void glfwSetGamma(GLFWmonitor* monitor, float gamma);
	export const GLFWgammaramp* glfwGetGammaRamp(GLFWmonitor* monitor);
	export void glfwSetGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp);
	export void glfwDefaultWindowHints(void);
	export void glfwWindowHint(int hint, int value);
	export void glfwWindowHintString(int hint, const char* value);
	export GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	export void glfwDestroyWindow(GLFWwindow* window);
	export int glfwWindowShouldClose(GLFWwindow* window);
	export void glfwSetWindowShouldClose(GLFWwindow* window, int value);
	export const char* glfwGetWindowTitle(GLFWwindow* window);
	export void glfwSetWindowTitle(GLFWwindow* window, const char* title);
	export void glfwSetWindowIcon(GLFWwindow* window, int count, const GLFWimage* images);
	export void glfwGetWindowPos(GLFWwindow* window, int* xpos, int* ypos);
	export void glfwSetWindowPos(GLFWwindow* window, int xpos, int ypos);
	export void glfwGetWindowSize(GLFWwindow* window, int* width, int* height);
	export void glfwSetWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);
	export void glfwSetWindowAspectRatio(GLFWwindow* window, int numer, int denom);
	export void glfwSetWindowSize(GLFWwindow* window, int width, int height);
	export void glfwGetFramebufferSize(GLFWwindow* window, int* width, int* height);
	export void glfwGetWindowFrameSize(GLFWwindow* window, int* left, int* top, int* right, int* bottom);
	export void glfwGetWindowContentScale(GLFWwindow* window, float* xscale, float* yscale);
	export float glfwGetWindowOpacity(GLFWwindow* window);
	export void glfwSetWindowOpacity(GLFWwindow* window, float opacity);
	export void glfwIconifyWindow(GLFWwindow* window);
	export void glfwRestoreWindow(GLFWwindow* window);
	export void glfwMaximizeWindow(GLFWwindow* window);
	export void glfwShowWindow(GLFWwindow* window);
	export void glfwHideWindow(GLFWwindow* window);
	export void glfwFocusWindow(GLFWwindow* window);
	export void glfwRequestWindowAttention(GLFWwindow* window);
	export GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* window);
	export void glfwSetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);
	export int glfwGetWindowAttrib(GLFWwindow* window, int attrib);
	export void glfwSetWindowAttrib(GLFWwindow* window, int attrib, int value);
	export void glfwSetWindowUserPointer(GLFWwindow* window, void* pointer);
	export void* glfwGetWindowUserPointer(GLFWwindow* window);
	export GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* window, GLFWwindowposfun callback);
	export GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow* window, GLFWwindowsizefun callback);
	export GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* window, GLFWwindowclosefun callback);
	export GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow* window, GLFWwindowrefreshfun callback);
	export GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* window, GLFWwindowfocusfun callback);
	export GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* window, GLFWwindowiconifyfun callback);
	export GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow* window, GLFWwindowmaximizefun callback);
	export GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback);
	export GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow* window, GLFWwindowcontentscalefun callback);
	export void glfwPollEvents(void);
	export void glfwWaitEvents(void);
	export void glfwWaitEventsTimeout(double timeout);
	export void glfwPostEmptyEvent(void);
	export int glfwGetInputMode(GLFWwindow* window, int mode);
	export void glfwSetInputMode(GLFWwindow* window, int mode, int value);
	export int glfwRawMouseMotionSupported(void);
	export const char* glfwGetKeyName(int key, int scancode);
	export int glfwGetKeyScancode(int key);
	export int glfwGetKey(GLFWwindow* window, int key);
	export int glfwGetMouseButton(GLFWwindow* window, int button);
	export void glfwGetCursorPos(GLFWwindow* window, double* xpos, double* ypos);
	export void glfwSetCursorPos(GLFWwindow* window, double xpos, double ypos);
	export GLFWcursor* glfwCreateCursor(const GLFWimage* image, int xhot, int yhot);
	export GLFWcursor* glfwCreateStandardCursor(int shape);
	export void glfwDestroyCursor(GLFWcursor* cursor);
	export void glfwSetCursor(GLFWwindow* window, GLFWcursor* cursor);
	export GLFWkeyfun glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun callback);
	export GLFWcharfun glfwSetCharCallback(GLFWwindow* window, GLFWcharfun callback);
	export GLFWcharmodsfun glfwSetCharModsCallback(GLFWwindow* window, GLFWcharmodsfun callback);
	export GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow* window, GLFWmousebuttonfun callback);
	export GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow* window, GLFWcursorposfun callback);
	export GLFWcursorenterfun glfwSetCursorEnterCallback(GLFWwindow* window, GLFWcursorenterfun callback);
	export GLFWscrollfun glfwSetScrollCallback(GLFWwindow* window, GLFWscrollfun callback);
	export GLFWdropfun glfwSetDropCallback(GLFWwindow* window, GLFWdropfun callback);
	export int glfwJoystickPresent(int jid);
	export const float* glfwGetJoystickAxes(int jid, int* count);
	export const unsigned char* glfwGetJoystickButtons(int jid, int* count);
	export const unsigned char* glfwGetJoystickHats(int jid, int* count);
	export const char* glfwGetJoystickName(int jid);
	export const char* glfwGetJoystickGUID(int jid);
	export void glfwSetJoystickUserPointer(int jid, void* pointer);
	export void* glfwGetJoystickUserPointer(int jid);
	export int glfwJoystickIsGamepad(int jid);
	export GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun callback);
	export int glfwUpdateGamepadMappings(const char* string);
	export const char* glfwGetGamepadName(int jid);
	export int glfwGetGamepadState(int jid, GLFWgamepadstate* state);
	export void glfwSetClipboardString(GLFWwindow* window, const char* string);
	export const char* glfwGetClipboardString(GLFWwindow* window);
	export double glfwGetTime(void);
	export void glfwSetTime(double time);
	export uint64_t glfwGetTimerValue(void);
	export uint64_t glfwGetTimerFrequency(void);
	export void glfwMakeContextCurrent(GLFWwindow* window);
	export GLFWwindow* glfwGetCurrentContext(void);
	export void glfwSwapBuffers(GLFWwindow* window);
	export void glfwSwapInterval(int interval);
	export int glfwExtensionSupported(const char* extension);
	export GLFWglproc glfwGetProcAddress(const char* procname);
	export int glfwVulkanSupported(void);
	export const char** glfwGetRequiredInstanceExtensions(uint32_t* count);

#if defined(VK_VERSION_1_0)
	export GLFWvkproc glfwGetInstanceProcAddress(VkInstance instance, const char* procname);
	export int glfwGetPhysicalDevicePresentationSupport(VkInstance instance, VkPhysicalDevice device, uint32_t queuefamily);
	export VkResult glfwCreateWindowSurface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
#endif /*VK_VERSION_1_0*/

#ifdef __cplusplus
}
#endif