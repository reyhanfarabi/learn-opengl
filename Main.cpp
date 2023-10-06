#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

int main()
{
	// set opengl window hint
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// init opengl
	if (!glfwInit()) return -1;

	// create windowed mode window and its opengl context
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL App", NULL, NULL);

	if (!window)
	{
		std::cout << "Failed to initialize window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// make the window context current
	glfwMakeContextCurrent(window);

	// load glad to configure opengl
	gladLoadGL();

	// specify the viewport of opengl in the window
	glViewport(0, 0, 800, 600);

	// set background color
	glClearColor(0.0f, 0.2f, 0.4f, 1.0f);

	// clean back buffer and assign new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// swap between front and back buffer
	glfwSwapBuffers(window);

	// loop until user close the window
	while (!glfwWindowShouldClose(window))
	{
		// poll for and process events
		glfwPollEvents();
	}

	// destroy window and terminate opengl app
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}