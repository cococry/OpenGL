workspace "OpenGL"
	startproject "OpenGL"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

Dependencies = {}
Dependencies["GLFW"] = "OpenGL/vendor/GLFW/include"

group "Dependencies"
	include "OpenGL/vendor/GLFW"
group ""

project "OpenGL"
	location "OpenGL"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{Dependencies.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "configurations:Debug"
		symbols "on"
		runtime "Debug"
	filter "configurations:Release"
		optimize "on"
		runtime "Release"