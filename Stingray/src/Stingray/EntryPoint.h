#pragma once

#ifdef SR_PLATFORM_WINDOWS


extern Stingray::Application* Stingray::CreateApplication();

int main(int argc, char** argv) {
	printf("Stingray Engine");
	auto app = Stingray::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Stingray supports Windows only!
#endif