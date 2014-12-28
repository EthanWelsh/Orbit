/*
Orbit: Solar System Simulation
Created by Jon Budd, Ritwik Gupta, and Ethan Welsh
Copyright (c) 2014 JRE. All rights reserved.
*/
#include "main.h"
#include "draw.h"
#include <deque>
#include <string>
#include <iostream>

#define DELTA_TIME 100

bool shouldRotate;
std::deque<Planet> planets;

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

	gluOrtho2D(-50, 50, -50, 50);
}

void my_setup(void) {
	//draw_lighting(); Ignore for now, might do lighting later
	shouldRotate = false;

	int mass = 4;
	int radius = 1;
	Point origin(-10, -15);
	Vector heading(-3, 1);

	Planet planet(mass, radius, origin, heading);

	int mass1 = 100;
	int radius1 = 7; //was 30
	Point origin1(1, 1);
	Vector heading1(0, 0);

	Planet sun(mass1, radius1, origin1, heading1);

	planets.push_front(sun);
	planets.push_front(planet);
	
}

void my_reshape(int w, int h) {

	/* define view port -- x, y, (origin is at lower left corner) width, height */
	glViewport(0, 0, min(w, h), min(w, h));
}

/*
void my_timer(int val) {

	//std::cout << planet.origin.toString() << std::endl;

	glutTimerFunc(DELTA_TIME, my_timer, 0);
	glutPostRedisplay();

	

	return;
}*/

void my_keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'p':
	case 'P':
		//shouldRotate = !shouldRotate;	
		shouldRotate = true;
		break;
	case 'q':
	case 'Q':
		exit(0);
	default:
		return;
		break;
	}


	glutPostRedisplay();

	

	//glutTimerFunc(DELTA_TIME, my_timer, 0);
}

void my_display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	int mass = 4;
	int radius = 1;
	Point origin(-10, -15);
	Vector heading(-3, 1);

	Planet planet(mass, radius, origin, heading);
	std::cout << shouldRotate << std::endl;
	if (shouldRotate){

		for (int i = 0; i < planets.size(); i++)
		{
			//Planet tempPlanet = planets.at(i);
			planets.at(i).sumVector(planets);
		}

	}

	for (int i = 0; i < planets.size(); i++)
	{
		Planet tempPlanet = planets.at(i);

		std::cout << tempPlanet.origin.toString() << std::endl;
	}

	drawSolarSystem(planets);
	shouldRotate = false;
	/* buffer is ready */
	glutSwapBuffers();
}

