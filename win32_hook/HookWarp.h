#ifndef HOOK_WARP
#define HOOK_WARP

#include <windows.h>
#include "detours.h"

// hook normal function
template <typename T>
class NormalHookWarp {
public:
	NormalHookWarp() {}
	virtual ~NormalHookWarp() { DetachLonely(); }

	virtual bool Attach(T origin_func, T hook_func) {
		if (attach_) {
			return false;
		}

		origin_func_ = origin_func;
		hook_func_ = hook_func;

		if (NO_ERROR != DetourAttach(&(PVOID&)origin_func_, *(PBYTE*)&hook_func_)) {
			return false;
		}

		attach_ = true;
		return true;
	}

	virtual bool Detach() {
		if (!attach_) {
			return false;
		}

		if (NO_ERROR != DetourDetach(&(PVOID&)origin_func_, *(PBYTE*)&hook_func_)) {
			return false;
		}

		attach_ = false;
		return true;
	}

	virtual bool AttachLonely(T origin_func, T hook_func) {
		if (attach_) {
			return false;
		}

		origin_func_ = origin_func;
		hook_func_ = hook_func;

		if (NO_ERROR != DetourTransactionBegin()) {
			return false;
		}
		if (NO_ERROR != DetourUpdateThread(GetCurrentThread())) {
			return false;
		}
		if (NO_ERROR != DetourAttach(&(PVOID&)origin_func_, *(PBYTE*)&hook_func_)) {
			return false;
		}
		if (NO_ERROR != DetourTransactionCommit()) {
			return false;
		}
		attach_ = true;
		return true;
	}

	virtual bool DetachLonely() {
		if (!attach_) {
			return false;
		}

		if (NO_ERROR != DetourTransactionBegin()) {
			return false;
		}
		if (NO_ERROR != DetourUpdateThread(GetCurrentThread())) {
			return false;
		}
		if (NO_ERROR != DetourDetach(&(PVOID&)origin_func_, *(PBYTE*)&hook_func_)) {
			return false;
		}
		if (NO_ERROR != DetourTransactionCommit()) {
			return false;
		}
		attach_ = false;
		return true;
	}

	virtual T GetOriFunc() {
		return origin_func_;
	}

private:
	T    origin_func_;
	T    hook_func_;
	bool attach_;
};

#endif