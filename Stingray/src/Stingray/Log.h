#pragma warning(push)
#pragma warning(disable:4251)
#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Stingray {
	class STINGRAY_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
#pragma warning(pop)
	};


}


// Core log macros
#define SR_CORE_TRACE(...)      ::Stingray::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SR_CORE_INFO(...)       ::Stingray::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SR_CORE_WARN(...)       ::Stingray::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SR_CORE_ERROR(...)      ::Stingray::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SR_CORE_CRITICAL(...)   ::Stingray::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SR_TRACE(...)           ::Stingray::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SR_INFO(...)            ::Stingray::Log::GetClientLogger()->info(__VA_ARGS__)
#define SR_WARN(...)            ::Stingray::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SR_ERROR(...)           ::Stingray::Log::GetClientLogger()->error(__VA_ARGS__)
#define SR_CRITICAL(...)        ::Stingray::Log::GetClientLogger()->critical(__VA_ARGS__)