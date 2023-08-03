#pragma once

#include "Core.h"

namespace Stingray {

	class STINGRAY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



