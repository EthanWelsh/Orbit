#include "draw.h"
#include "main.h"
#include <cmath>


static int SMOOTHNESS = 300;

/* colors */
GLfloat colors[][3] = {
        {0.0, 0.0, 0.0},                    /* black      */
        {1.0, 0.0, 0.0},                    /* red        */
        {1.0, 1.0, 0.0},                    /* yellow     */
        {1.0, 0.5, 0.0},                    /* orange     */
        {0.0, 1.0, 0.0},                    /* green      */
        {0.0, 0.0, 1.0},                    /* blue       */
        {1.0, 1.0, 1.0},                    /* white      */
        {1.0, 0.0, 1.0},                    /* magenta    */
        {0.0, 1.0, 1.0},                    /* cyan       */
        {0.5, 0.5, 0.5},                    /* 50% grey   */
        {0.019, 0.32, 0.589},               /* opal       */
        {0.59, 0.0, 0.0},                   /* brick red  */
        {0.1, 0.3, 0.0},                    /* dark green */
        {0.309804, 0.184314, 0.309804},     /* purple     */
        {0.8, 0.498039, 0.196078}           /* gold???    */
};


void drawCircle(int radius)
{
    for (int i = 0; i < SMOOTHNESS; i++)
    {
        double angle = 2 * PI * i / SMOOTHNESS;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2f(x, y);
    }
}


void drawPlanet(Planet &p)
{
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


void drawSolarSystem(std::deque<Planet> planets)
{
    for (int i = 0; i < planets.size(); i++)
    {
        Planet planet = planets.at(i);
        drawPlanet(planet);
    }
}