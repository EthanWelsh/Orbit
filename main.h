#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define min(a,b) ((a) < (b)? a:b)
#define FALSE 0
#define TRUE  1

#define DELTA_DEG  4
#define PI 3.14159265358979323
#define DEG_TO_RAD (180/PI)

void glut_setup(void);
void gl_setup(void);
void my_setup(void);
void my_reshape(int w, int h);
void my_keyboard(unsigned char key, int x, int y);
void my_display(void);
void make_tesseract();
void reset_camera();