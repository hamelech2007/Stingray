#include <Stingray.h>

class Sandbox : public Stingray::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Stingray::Application* Stingray::CreateApplication() {
	return new Sandbox();
}