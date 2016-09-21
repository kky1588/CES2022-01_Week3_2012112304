#include <glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawOnPixelBuffer()
{


	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	//for (int i = 0; i<width*height; i++) {
	//	pixels[i * 3 + 0] = 1.0f; // red 
	//	pixels[i * 3 + 1] = 1.0f; // green
	//	pixels[i * 3 + 2] = 1.0f; // blue
	//}

	//const int i = rand() % width, j = rand() % height;
	//drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	//Drawing Circle
	int r = 80;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((j - 100)*(j - 100) + (i - 100)*(i - 100) <= r*r)
			{
				drawPixel(i, j, 0.0f, 0.0f, 0.0f);
			}
			if ((j - 100)*(j - 100) + (i - 100)*(i - 100) < r*r -200)
			{
				drawPixel(i, j, 1.0f, 1.0f, 1.0f);
			}

		}
	}

	//Drawing Thickner line
	const int i0_T1 = 100, i1_T1 = 200;
	const int j0_T1 = 300, j1_T1 = 400;

	const int i0_T2 = 99, i1_T2 = 199;
	const int j0_T2 = 300, j1_T2 = 401;

	const int i0_T3 = 100, i1_T3 = 201;
	const int j0_T3 = 299, j1_T3 = 400;

	drawLine(i0_T1, j0_T1, i1_T1, j1_T1, 0.0f, 0.0f, 0.0f);
	drawLine(i0_T2, j0_T2, i1_T2, j1_T2, 0.0f, 0.0f, 0.0f);
	drawLine(i0_T3, j0_T3, i1_T3, j1_T3, 0.0f, 0.0f, 0.0f);

	//Drawing Triangle

	const int i0_l1 = 400, i1_l1 = 600;
	const int j0_l1 = 200, j1_l1 = 150;

	const int i0_l2 = 500, i1_l2 = 600;
	const int j0_l2 = 50, j1_l2 = 150;

	const int i0_l3 = 400, i1_l3 = 500;
	const int j0_l3 = 200, j1_l3 = 50;

	drawLine(i0_l1, j0_l1, i1_l1, j1_l1, 0.0f, 0.0f, 0.0f);
	drawLine(i0_l2, j0_l2, i1_l2, j1_l2, 0.0f, 0.0f, 0.0f);
	drawLine(i0_l3, j0_l3, i1_l3, j1_l3, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing

	//Drawing Normal Square

	const int i0 = 240, i1 = 320;
	const int j0 = 290, j1 = 370;

	const int i0_2 = 320, i1_2 = 400;
	const int j0_2 =370, j1_2 = 290;

	const int i0_3 = 320, i1_3 = 400;
	const int j0_3 = 210, j1_3 = 290;

	const int i0_4 = 240, i1_4 = 320;
	const int j0_4 = 290, j1_4 = 210;

	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0_2, j0_2, i1_2, j1_2, 0.0f, 0.0f, 0.0f);
	drawLine(i0_3, j0_3, i1_3, j1_3, 0.0f, 0.0f, 0.0f);
	drawLine(i0_4, j0_4, i1_4, j1_4, 0.0f, 0.0f, 0.0f);
	//TODO: try moving object

	//Drawing Filled Square

	const int i0_5 = 440, i1_5 = 520;
	const int j0_5 = 290, j1_5 = 370;

	const int i0_6 = 520, i1_6 = 600;
	const int j0_6 = 370, j1_6 = 290;

	const int i0_7 = 520, i1_7 = 600;
	const int j0_7 = 210, j1_7 = 290;

	const int i0_8 = 440, i1_8 = 520;
	const int j0_8 = 290, j1_8 = 210;
	
	drawLine(i0_5, j0_5, i1_5, j1_5, 0.0f, 0.0f, 0.0f);
	drawLine(i0_6, j0_6, i1_6, j1_6, 0.0f, 0.0f, 0.0f);
	drawLine(i0_7, j0_7, i1_7, j1_7, 0.0f, 0.0f, 0.0f);
	drawLine(i0_8, j0_8, i1_8, j1_8, 0.0f, 0.0f, 0.0f);

	//Draw ¿À°¢Çü

	const int i0_f1 = 390, i1_f1 = 440;
	const int j0_f1 = 180, j1_f1 = 60;
	const int i0_f2 = 330, i1_f2 = 440;
	const int j0_f2 = 20, j1_f2 = 60;

	const int i0_f3 = 270, i1_f3 = 330;
	const int j0_f3 = 100, j1_f3 = 20;

	const int i0_f4 = 270, i1_f4 = 330;
	const int j0_f4 = 100, j1_f4 = 170;

	const int i0_f5 = 330, i1_f5 = 390;
	const int j0_f5 = 170, j1_f5 = 180;

	drawLine(i0_f1, j0_f1, i1_f1, j1_f1, 0.0f, 0.0f, 0.0f);
	drawLine(i0_f2, j0_f2, i1_f2, j1_f2, 0.0f, 0.0f, 0.0f);
	drawLine(i0_f3, j0_f3, i1_f3, j1_f3, 0.0f, 0.0f, 0.0f);
	drawLine(i0_f4, j0_f4, i1_f4, j1_f4, 0.0f, 0.0f, 0.0f);
	drawLine(i0_f5, j0_f5, i1_f5, j1_f5, 0.0f, 0.0f, 0.0f);
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	/* Loop unt il the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	
	delete[] pixels;

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}