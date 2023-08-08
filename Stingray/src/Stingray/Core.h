#pragma once

#ifdef SR_PLATFORM_WINDOWS

	#ifdef SR_BUILD_DLL
		#define STINGRAY_API __declspec(dllexport)
	#else
		#define STINGRAY_API __declspec(dllimport)
	#endif
#else
	#error Stingray supports Windows only!
#endif

#ifdef SR_DEBUG
	#define SR_ENABLE_ASSERTS
#endif


#ifdef SR_ENABLE_ASSERTS
	#define SR_ASSERT(x,...) { if(!(x)) {SR_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define SR_CORE_ASSERT(x,...) { if(!(x)) {SR_CORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define SR_ASSERT(x, ...)
	#define SR_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1<<x)

#define SR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)