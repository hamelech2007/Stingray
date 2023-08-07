#include <Stingray.h>

#include <iostream>

class ExampleLayer : public Stingray::Layer {
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override {
		//SR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Stingray::Event& event) override {
		SR_TRACE("{0}", event);
	}
};

class Sandbox : public Stingray::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Stingray::ImGuiLayer());

	}

	~Sandbox() {

	}
};

Stingray::Application* Stingray::CreateApplication() {
	return new Sandbox();
} 