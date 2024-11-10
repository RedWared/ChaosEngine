#include <GLFW/glfw3.h>

int main(void){
	GLFWwindow* win;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	win = glfwCreateWindow(640, 480, "Wah World",  glfwGetPrimaryMonitor(), NULL);

	if (!win){
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(win);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(win)){
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(win);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
