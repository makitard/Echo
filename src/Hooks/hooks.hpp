#include "../includes.hpp"

using namespace cocos2d;

#define _THISCALL_HOOK(name, ret_type, self_type, ...) \
inline ret_type(__thiscall* name)(self_type* self, __VA_ARGS__); \
ret_type __fastcall name##_h(self_type* self, int, __VA_ARGS__);

#define _FASTCALL_HOOK(name, ret_type, ...) \
inline ret_type(__fastcall* name)(__VA_ARGS__); \
ret_type __fastcall name##_h(__VA_ARGS__);

// gracias matcool :]

namespace Hooks {

	inline void(__thiscall* CCScheduler_update)(CCScheduler* self, float dt); void __fastcall CCScheduler_update_h(CCScheduler* self, int, float dt);

	inline int(__fastcall* createCheckpoint)(gd::PlayLayer* self); int __fastcall createCheckpoint_h(gd::PlayLayer* self);

	inline int(__fastcall* removeCheckpoint)(gd::PlayLayer* self); int __fastcall removeCheckpoint_h(gd::PlayLayer* self);

	namespace PlayLayer {
		inline void(__thiscall* update)(gd::PlayLayer* self, float dt); void __fastcall update_h(gd::PlayLayer* self, int, float dt);

		inline int(__thiscall* pushButton)(gd::PlayLayer* self, int, bool); int __fastcall pushButton_h(gd::PlayLayer* self, int, int, bool);

		inline int(__thiscall* releaseButton)(gd::PlayLayer* self, int, bool); int __fastcall releaseButton_h(gd::PlayLayer* self, int, int, bool);

		inline int(__thiscall* resetLevel)(gd::PlayLayer* self); int __fastcall resetLevel_h(gd::PlayLayer* self, int);
	}

	void init_hooks();
}