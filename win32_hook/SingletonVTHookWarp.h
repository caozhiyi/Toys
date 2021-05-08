#ifndef HOOK_SINGLETON_VT_HOOK_WARP
#define HOOK_SINGLETON_VT_HOOK_WARP

#include "VTHookWarp.h"
#include "common/Singleton.h"

// singleton hook virtual table function by this point.
// virtual table function type: typedef int(__thiscall *hook_func_type)(TestOriClass* this_pt);
// hook function: int __fastcall HookNotifyUI(TestOriClass* this_pt, DWORD _EDX) { }
template<typename C = int>
class SingletonVTHookWarp:
	public NormalVTHookWarp,
	public Singleton<SingletonVTHookWarp<C>> {
public:
	SingletonVTHookWarp() {}
	~SingletonVTHookWarp() {}

};


