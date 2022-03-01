#include "Window.h"

int main()
{
	Window window("OpenGL Tutorial", 1920, 1080);

	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.OnUpdate();
	}
}