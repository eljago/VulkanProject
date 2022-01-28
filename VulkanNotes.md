
### Resource management

Just like each chunk of memory allocated with malloc requires a call to free, every Vulkan object that we create needs to be explicitly destroyed when we no longer need it.

Vulkan objects are either created directly with functions like vkCreateXXX, or allocated through another object with functions like vkAllocateXXX. After making sure that an object is no longer used anywhere, you need to destroy it with the counterparts vkDestroyXXX and vkFreeXXX. The parameters for these functions generally vary for different types of objects, but there is one parameter that they all share: pAllocator. This is an optional parameter that allows you to specify callbacks for a custom memory allocator. We will ignore this parameter in the tutorial and always pass nullptr as argument.

### Creating an instance

The very first thing you need to do is initialize the Vulkan library by creating an instance. The instance is the connection between your application and the Vulkan library and creating it involves specifying some details about your application to the driver.

```cpp
void createInstance() {

        // This struct is optional
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        // This next struct is not optional and tells the Vulkan driver which global extensions and validation
        // layers we want to use. Global here means that they apply to the entire program and not a specific device,
        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        // The last two members of the struct determine the global validation layers to enable
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        // We've now specified everything Vulkan needs to create an instance and we can finally issue the vkCreateInstance call:
        VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    }
```
As you'll see, the general pattern that object creation function parameters in Vulkan follow is:

- Pointer to struct with creation info
- Pointer to custom allocator callbacks, always nullptr in this tutorial
- Pointer to the variable that stores the handle to the new object

