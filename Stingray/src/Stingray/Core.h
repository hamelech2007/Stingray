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