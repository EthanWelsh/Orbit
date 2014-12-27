/*
Orbit: Solar System Simulation
Created by Jon Budd, Ritwik Gupta, and Ethan Welsh
Copyright (c) 2014 JRE. All rights reserved.
*/
#include "main.h"
#include "draw.h"

bool shouldRotate;

int main(int argc, char **argv) {

	/* General initialization for GLUT and OpenGL
	Must be called first */
	glutInit(&argc, argv);

	/* we define these setup procedures */
	glut_setup();
	gl_setup();
	my_setup();

	/* go into the main event loop */
	glutMainLoop();

	return(0);
}

/* This function sets up the windowing related glut calls */
void glut_setup(void) {

	/* specify display mode -- here we ask for a GLfloat buffer and RGB coloring */
	/* NEW: tell display we care about depth now */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	/* make a 400x400 window with the title of "GLUT Skeleton" placed at the top left corner */
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Orbit: Solar System Simulator");

	/*initialize callback functions */
	glutDisplayFunc(my_display);
	glutReshapeFunc(my_reshape);
	glutKeyboardFunc(my_keyboard);
}

/* This function sets up the initial states of OpenGL related environment */
void gl_setup(void) {

	/* specifies a background color: black in this case */
	glClearColor(0, 0, 0, 0);

	/* Setup for 2d projection */
	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-20, 20, -20, 20);
}

void my_setup(void) {
	//draw_lighting(); Ignore for now, might do lighting later
	shouldRotate = true;
}

void my_reshape(int w, int h) {

	/* define view port -- x, y, (origin is at lower left corner) width, height */
	glViewport(0, 0, min(w, h), min(w, h));
}

void my_keyboard(unsigned char key, int x, int y) {

	shouldRotate = true;

	switch (key) {
	case 'p':
	case 'P':
		shouldRotate = !shouldRotate;
		if (shouldRotate) glutPostRedisplay();
		break;
	case 'q':
	case 'Q':
		exit(0);
	default:
		return;
	}
}

void my_display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	drawSolarSystem();
	/* buffer is ready */
	glutSwapBuffers();
}