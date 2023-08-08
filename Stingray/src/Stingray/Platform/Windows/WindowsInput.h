#pragma once

#include "Stingray/Core.h"
#include "Stingray/Input.h"

namespace Stingray {
	class WindowsInput : public Input {
	protected:
		bool IsKeyPressedImpl(int keycode) override;
		bool IsMouseButtonPressedImpl(int button) override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
		std::pair<float, float> GetMousePositionImpl() override;
	};
}