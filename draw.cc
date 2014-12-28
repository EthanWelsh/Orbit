#include "draw.h"
#include "main.h"
#include <cmath>



static int SMOOTHNESS = 300;

/* colors */
GLfloat colors[][3] = {
	{ 0.0, 0.0, 0.0 },		/* black   */
	{ 1.0, 0.0, 0.0 },		/* red     */
	{ 1.0, 1.0, 0.0 },		/* yellow  */
	{ 1.0, 0.5, 0.0 },		/* orange  */
	{ 0.0, 1.0, 0.0 },		/* green   */
	{ 0.0, 0.0, 1.0 },		/* blue    */
	{ 1.0, 1.0, 1.0 },		/* white   */
	{ 1.0, 0.0, 1.0 },		/* magenta */
	{ 0.0, 1.0, 1.0 },		/* cyan    */
	{ 0.5, 0.5, 0.5 },		/* 50% grey */
	{ 0.019, 0.32, 0.589 }, /* opal */
	{ 0.59, 0.0, 0.0 },		/* brick red */
	{ 0.1, 0.3, 0.0 },		/* dark green */
	{ 0.309804, 0.184314, 0.309804 },/* purple*/
	{ 0.8, 0.498039, 0.196078 }		/* Gold???*/
};




void drawCircle(int radius){
	for (int i = 0; i < SMOOTHNESS; i++){
		double angle = 2 * PI * i / SMOOTHNESS;
		double x = cos(angle)*radius;
		double y = sin(angle)*radius;
		glVertex2f(x, y);
	}
}


void drawPlanet(Planet &p){
	glPushMatrix(); 
	{
		glTranslatef(p.origin.x, p.origin.y, 0);
		glBegin(GL_POLYGON); 
		{
			glColor3fv(colors[p.color]);
			drawCircle(p.radius);
		}
		glEnd();
	}
	glPopMatrix();
}


void drawSolarSystem(std::deque<Planet> planets){
	for (int i = 0; i < planets.size(); i++)
	{
		Planet planet = planets.at(i);
		drawPlanet(planet);
	}
}




/*
void draw_lighting()
{
	
	GLfloat mat_amb_diff[] = { .6, .6, .6, 1 };
	GLfloat mat_specular[] = { 0.6, 0.6, 0.6, 1 };
	GLfloat mat_emission[] = { 0, 0, 0, 0 };
	GLfloat mat_high_shininess[] = { 100 };
	GLfloat globalAmb[] = { .2, .2, .2, 1 };

	
	GLfloat light0_amb[] = { 0, 0, 0, 1 };
	GLfloat light0_diffuse[] = { 1, 1, 1, 1 };
	GLfloat light0_specular[] = { 1, 1, 1, 1 };
	GLfloat light0_pos[] = { 1, 1, 1, 0 };

	//enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	// setup properties of point light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);

	// setup material properties
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_high_shininess);

	// reflective properties -- global ambient light
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

}

void draw_edge(GLfloat point_a[3], GLfloat point_b[3], int draw_sphere, int cylinder_color, int sphere_color)
{
	GLfloat line_seg_vector[3] = { point_a[0] - point_b[0], point_a[1] - point_b[1], point_a[2] - point_b[2] };

	GLfloat magnitude = calc_magnitude_3d(line_seg_vector);
	GLfloat alignment_angle = DEG_TO_RAD * acos(dot3D(z_axis, line_seg_vector) / magnitude);

	cross3D(crossed, z_axis, line_seg_vector);

	glPushMatrix();
	glTranslatef(point_b[0], point_b[1], point_b[2]);
	glRotatef(alignment_angle, crossed[0], crossed[1], crossed[2]);

	if (TRUE == draw_sphere)
	{
		glColor3fv(colors[sphere_color]);
		glutSolidSphere(.07, 90, 90);
	}

	glColor3fv(colors[cylinder_color]);
	GLUquadric* my_quadric = gluNewQuadric();
	gluCylinder(my_quadric, .04, .04, magnitude, 90, 1);
	glPopMatrix();
}
*/