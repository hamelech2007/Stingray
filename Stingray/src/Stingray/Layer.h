#pragma once

#include "Stingray/Core.h"
#include "Stingray/Events/Event.h"

namespace Stingray {
	class STINGRAY_API Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e){}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;

	};


}


