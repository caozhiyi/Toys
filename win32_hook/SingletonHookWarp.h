#ifndef HOOK_SINGLETON_HOOK_WARP
#define HOOK_SINGLETON_HOOK_WARP

#include "HookWarp.h"
#include "common/Singleton.h"


// singleton hook normal function
template <typename T, typename C = int>
class SingletonHookWarp:
	public NormalHookWarp<T>,
	public Singleton<SingletonHookWarp<T, C>> {
public:
	SingletonHookWarp() {}
	~SingletonHookWarp() {}

};

#endif