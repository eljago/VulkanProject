
### Resource management

Just like each chunk of memory allocated with malloc requires a call to free, every Vulkan object that we create needs to be explicitly destroyed when we no longer need it.

Vulkan objects are either created directly with functions like vkCreateXXX, or allocated through another object with functions like vkAllocateXXX. After making sure that an object is no longer used anywhere, you need to destroy it with the counterparts vkDestroyXXX and vkFreeXXX. The parameters for these functions generally vary for different types of objects, but there is one parameter that they all share: pAllocator. This is an optional parameter that allows you to specify callbacks for a custom memory allocator. We will ignore this parameter in the tutorial and always pass nullptr as argument.

