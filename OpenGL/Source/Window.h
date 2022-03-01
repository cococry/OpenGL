#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
	Window(const std::string& title, uint32_t width, uint32_t height);
	~Window();
	
	inline GLFWwindow* GetWindow() const { return m_Window_ID; }

	void OnUpdate();
private:
	GLFWwindow* m_Window_ID;

	void Init(const std::string& title, uint32_t width, uint32_t height);
};