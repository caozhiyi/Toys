#ifndef HOOK_VT_HOOK_WARP
#define HOOK_VT_HOOK_WARP

#include <windows.h>
// hook virtual table function by this point.
// virtual table function type: typedef int(__thiscall *hook_func_type)(TestOriClass* this_pt);
// hook function: int __fastcall HookNotifyUI(TestOriClass* this_pt, DWORD _EDX) { }
class NormalVTHookWarp {
public:
	NormalVTHookWarp():
		origin_func_(nullptr),
		origin_func_addr_(0),
		attach_(false) {}

	virtual ~NormalVTHookWarp() { Detach(); }

	virtual bool Attach(void* ori, unsigned int index/*hook function index in VT*/, void* hook) {
		if (attach_) {
			return true;
		}
		intptr_t vtable = *((intptr_t*)ori);
		intptr_t entry = vtable + sizeof(intptr_t) * index;

		origin_func_ = (void*)*((intptr_t*)entry);
		origin_func_addr_ = entry;

		int original_protection = MemoryUnprotect((void*)entry);
		*((intptr_t*)entry) = (intptr_t)hook;
		MemoryProtect((void*)entry, original_protection);

		attach_ = true;
		return true;
	}

	virtual bool Detach() {
		if (!attach_ || !origin_func_ || !origin_func_addr_) {
			return false;
		}

		int original_protection = MemoryUnprotect((void*)origin_func_addr_);
		*((intptr_t*)origin_func_addr_) = (intptr_t)origin_func_;
		MemoryProtect((void*)origin_func_addr_, original_protection);

		attach_ = false;
		return true;
	}

	virtual void* GetOriFunc() {
		return origin_func_;
	}

private:
	int MemoryUnprotect(void* region) {
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery((LPCVOID)region, &mbi, sizeof(mbi));
		VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect);
		return mbi.Protect;
	}

	void MemoryProtect(void* region, int protection) {
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery((LPCVOID)region, &mbi, sizeof(mbi));
		VirtualProtect(mbi.BaseAddress, mbi.RegionSize, protection, &mbi.Protect);
	}

private:
	void*    origin_func_; 
	intptr_t origin_func_addr_; 
	bool     attach_;
};

}

#endif