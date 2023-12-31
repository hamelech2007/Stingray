#pragma once
#pragma warning( disable : 4251 )

#include "srpch.h"

#include "Stingray/Core.h"
#include "Stingray/Events/Event.h"

namespace Stingray {
	struct STINGRAY_API WindowProps {
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Stingray Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class STINGRAY_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;



		static Window* Create(const WindowProps& props = WindowProps());
	};
}