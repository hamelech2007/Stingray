#include <Stingray.h>

#include <iostream>


#include <imgui/imgui.h>

class ExampleLayer : public Stingray::Layer {
public:
	ExampleLayer() : Layer("Example"){}

	void OnUpdate() override {
		//SR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Stingray::Event& event) override {
		//SR_TRACE("{0}", event);
	}

	void OnImGuiRender() override {
		/*ImGui::Begin("Project Files");
		ImGui::Text("main.cpp");
		ImGui::End();*/
	}
};

class Sandbox : public Stingray::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());

	}

	~Sandbox() {

	}
};

Stingray::Application* Stingray::CreateApplication() {
	return new Sandbox();
} 