workspace "Stingray"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Stingray/vendor/GLFW/include"
IncludeDir["Glad"] = "Stingray/vendor/Glad/include"
IncludeDir["ImGui"] = "Stingray/vendor/imgui"
IncludeDir["glm"] = "Stingray/vendor/glm"


group "Dependencies"
	include "Stingray/vendor/GLFW"
	include "Stingray/vendor/Glad"
	include "Stingray/vendor/imgui"

group ""



project "Stingray"
	location "Stingray"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "Stingray/src/srpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines
		{"SR_DEBUG"
		--, "SR_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "On"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Stingray/vendor/spdlog/include",
		"Stingray/src",
		"%{IncludeDir.glm}",
		"Stingray/vendor"
	}

	links
	{
		"Stingray"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		symbols "On"