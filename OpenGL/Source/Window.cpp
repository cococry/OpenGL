#include "Window.h"
#include <iostream>

Window::Window(const std::string& title, uint32_t width, uint32_t height)
{
	this->Init(title, width, height);
}

Window::~Window()
{
	glfwDestroyWindow(m_Window_ID);
}

void Window::OnUpdate()
{
	glfwSwapBuffers(m_Window_ID);
	glfwPollEvents();
}

void Window::Init(const std::string& title, uint32_t width, uint32_t height)
{
	if (!glfwInit())
	{
		std::cout << "[GLFW Fehler]: GLFW konnte nicht korrekt initialisiert werden!\n";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_Window_ID = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title.c_str(), nullptr, nullptr);
	if (!m_Window_ID)
	{
		std::cout << "[GLFW Window Fehler]: GLFW Window konnte nicht erstellt werden!\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_Window_ID);
	glfwSwapInterval(1);
}
