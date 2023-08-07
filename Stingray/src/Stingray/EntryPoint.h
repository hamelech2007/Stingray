#pragma once

#ifdef SR_PLATFORM_WINDOWS


extern Stingray::Application* Stingray::CreateApplication();

int main(int argc, char** argv) {
	
	Stingray::Log::Init();
	SR_CORE_WARN("Initialized Log!");
	SR_INFO("Hello!");


	auto app = Stingray::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Stingray supports Windows only!
#endif