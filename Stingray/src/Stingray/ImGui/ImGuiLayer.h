#pragma once

#include "Stingray/Core.h"
#include "Stingray/Layer.h"
#include "Stingray/Events/MouseEvent.h"
#include "Stingray/Events/ApplicationEvent.h"
#include "Stingray/Events/KeyEvent.h"

namespace Stingray {
	class STINGRAY_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}