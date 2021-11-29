/* */

#include <windows.h>
#include <GL/glut.h>
#include<math.h>

float theta = 0;
float red = 0.85;
float green = 0.85;
float blue = 0.85;
const char* string1 = "";
const char* string2 = "";
const char* string3 = "";



void output(float x, float y, const char* string)
{

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}

}
void names(int value) {
	switch (value) {
	case 1:
		string1 = "CG PROJECT - ";
		string2 = "OM , KAIF";
		string3 = "SUJAL , FARDEEN";
		glutPostRedisplay();
		break;
	case 2:
		string1 = "";
		string2 = "";
		string3 = "";
		glutPostRedisplay();
		break;
	}
}
void rotatefunction() {
	theta -= 0.03;
	if (theta > 360) {
		theta = 0;
	}
	glutPostRedisplay();

}

void normalKey(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;

	}
}
void LightBulb(int value) {
	switch (value) {
	case 1:
		red = 1;
		green = 0.96;
		blue = 0.77;
		glutPostRedisplay();
		break;
	case 2:
		red = 0.878;
		green = 0.807;
		blue = 0.713;
		glutPostRedisplay();
		break;
	}
}
void menu(void) {
	int subid = glutCreateMenu(LightBulb);
	glutAddMenuEntry("Turn ON", 1);
	glutAddMenuEntry("Turn OFF", 2);
	int nameid = glutCreateMenu(names);
	glutAddMenuEntry("visible", 1);
	glutAddMenuEntry("not visible", 2);
	int s = glutCreateMenu(LightBulb);
	glutAddSubMenu("ceiling lamp", subid);
	glutAddSubMenu("Names", nameid);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void drawCircle(float cx, float cy, float r1, float r2, int number_vertices) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < number_vertices; i++)
	{
		float theta = 2.0 * 3.1415926 * i / number_vertices;               //get the current angle 
		float x = r1 * cos(theta);                                         //calculate the x component 
		float y = r2 * sin(theta);                                         //calculate the y component 
		glVertex2f(x + cx, y + cy);                                        //output vertex 
	}
	glEnd();
}

void drawPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	// with 4 vertexes

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawTriangleFun(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	// with 4 vertexes

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawTriangleFun(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6)
{
	// with 6 vertexes

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glEnd();
}

void drawquads(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	// with 4 vertexes

	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawLines(int x1, int y1, int x2, int y2)
{
	// with 2 vertexes

	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}


void draw() {


	glClear(GL_COLOR_BUFFER_BIT);

	//------------------------------ Background of the bottom part

	glColor3f(0.113, 0.160, 0.317);
	drawPolygon(-500, -150, -500, -500, 500, -500, 500, -150);

	//----------------------------- background of the walls
	glClearColor(0.878, 0.807, 0.713, 0);


	//--------------------------------- chair bottom support

	glColor3f(0.1, 0.1, 0.1);
	drawPolygon(150, -260, 275, -260, 275, -235, 150, -235);

	glColor3f(0.1, 0.1, 0.1);
	drawPolygon(190, -235, 190, -180, 235, -180, 235, -235);


	//--------------------------------- chair wheels

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(150, -270, 0);

	glColor3f(0, 0, 0);
	drawCircle(0, 0, 15, 20, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(275, -270, 0);

	glColor3f(0, 0, 0);
	drawCircle(0, 0, 15, 20, 1000);

	//------------------------- A rose


	glTranslatef(358, 365, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();
	glTranslatef(343, 365, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();
	glTranslatef(335, 380, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();
	glTranslatef(358, 395, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();
	glTranslatef(343, 395, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();

	glTranslatef(365, 380, 0);
	glColor3f(1, 0, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();

	glTranslatef(350, 380, 0);
	glColor3f(1, 1, 0);
	drawCircle(0, 0, 8, 10, 1000);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);


	glColor3f(0.5, 0.5, 0.5);
	drawTriangleFun(340, 275, 360, 275, 355, 335, 345, 335);
	glLineWidth(2);
	glColor3f(0, 0, 0);
	drawLines(350, 335, 350, 360);

	//-------------------------------- the watch

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-350, 350, 2);

	glColor3f(0.827, 0.827, 0.827);
	drawCircle(0, 0, 48, 63, 1000);

	glColor3f(1, 1, 1);
	drawCircle(0, 0, 38, 50, 1000);

	glLineWidth(4);
	glColor3f(1, 0, 0);
	drawLines(0, 45, 0, 4);

	glColor3f(0, 0, 0);
	drawCircle(0, 0, 3, 4, 1000);

	glRotatef(90, 0, 0, 1);

	glColor3f(1, 0, 0);
	drawLines(0, -30, 0, -4);

	glRotatef(theta, 0, 0, 1);
	glColor3f(0, 0, 0);
	glLineWidth(1);
	drawLines(0, 30, 0, -4);

	//---------------------------

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//-----------------------keyboard
	glColor3f(0, 0, 0);
	drawPolygon(-275, 25, -125, 25, -125, 35, -275, 35);

	//----------------------- coffee cup

	glColor3f(0.30, 0.30, 0.30);
	drawPolygon(-85, 65, -85, 25, -60, 25, -60, 65);

	glColor3f(0.60, 0.60, 0.60);
	drawPolygon(-55, 65, -55, 80, -90, 80, -90, 65);

	glLineWidth(4);
	glColor3f(0.60, 0.60, 0.60);
	drawLines(-60, 55, -50, 55);
	drawLines(-60, 35, -50, 35);
	drawLines(-52, 55, -52, 35);

	//----------------------- book shelf

	glColor3f(0.51, 0.30, 0);
	drawPolygon(100, 250, 400, 250, 400, 275, 100, 275);

	//----------------------- books

	glColor3f(1, 0, 0);
	drawPolygon(125, 275, 125, 350, 150, 350, 150, 275);

	glColor3f(0.333, 0.298, 0.270);
	drawPolygon(175, 275, 220, 275, 220, 375, 175, 375);

	glColor3f(0.682, 0.396, 0.776);
	drawPolygon(150, 275, 175, 275, 175, 420, 150, 420);

	glColor3f(1, 1, 1);
	drawPolygon(220, 275, 220, 350, 245, 350, 245, 275);

	glColor3f(0.337, 0.588, 0.627);
	drawPolygon(245, 275, 245, 345, 260, 345, 260, 275);

	glColor3f(0.945, 0.447, 0.317);
	drawPolygon(260, 275, 300, 275, 300, 375, 260, 375);

	//-------------------------chair top part 


	glBegin(GL_TRIANGLE_FAN);// with 8 vertexes
	glColor3f(0.337, 0.152, 0.176);
	glVertex2f(165, 85);
	glVertex2f(175, 105);
	glVertex2f(245, 105);
	glVertex2f(255, 85);
	glVertex2f(265, -45);
	glVertex2f(255, -65);
	glVertex2f(170, -65);
	glVertex2f(155, -45);
	glEnd();

	//------------------------chair handle
	glColor3f(0.1, 0.1, 0.1);
	drawTriangleFun(120, -90, 120, -10, 130, 0, 140, -10, 140, -90, 130, -100);


	glColor3f(0.1, 0.1, 0.1);
	drawTriangleFun(286, -90, 286, -10, 296, 0, 306, -10, 306, -90, 296, -100);


	glColor3f(0.337, 0.152, 0.176);        // the actual seat part on the bottom
	drawTriangleFun(140, -85, 285, -85, 295, -105, 130, -105);


	glColor3f(0, 0, 0);                 //lumbar support in black colour present 
	drawPolygon(195, -85, 230, -85, 230, -65, 195, -65);


	glColor3f(0, 0, 0);   //bottom support of the chair 1
	drawPolygon(190, -140, 190, -125, 235, -125, 235, -140);

	glColor3f(0.1, 0.1, 0.1);     //bottom support of the chair pt. 2
	drawPolygon(130, -125, 295, -125, 295, -105, 130, -105);

	glColor3f(1, 1, 1);
	drawPolygon(200, -140, 200, -180, 225, -180, 225, -140);




	//----------------------------- desk

	glColor3f(0.51, 0.25, 0);
	drawPolygon(-450, 0, -440, 0, -440, -275, -450, -275);

	glColor3f(0.51, 0.25, 0);
	drawPolygon(0, 0, 10, 0, 10, -275, 0, -275);

	glColor3f(0.51, 0.30, 0);
	drawPolygon(-465, 25, -465, 0, 25, 0, 25, 25);

	glColor3f(0.51, 0.11, 0);
	drawPolygon(-440, -25, 0, -25, 0, -230, -440, -230);

	glColor3f(0.51, 0.25, 0);
	drawPolygon(-315, 0, -305, 0, -305, -275, -315, -275);

	glColor3f(0.51, 0.25, 0);
	drawPolygon(-440, -40, -440, -50, -315, -50, -315, -40);

	//----------------------- office drawer

	glColor3f(0.51, 0.19, 0);
	drawPolygon(-440, -50, -440, -105, -315, -105, -315, -50);

	glColor3f(0.51, 0.19, 0);
	drawPolygon(-440, -105, -440, -175, -315, -175, -315, -105);


	glColor3f(0.51, 0.10, 0);
	drawLines(-440, -105, -315, -105);

	//-----------------------drawer handle

	glColor3f(0.51, 0.19, 0);
	drawPolygon(-440, -175, -440, -245, -315, -245, -315, -175);

	glColor3f(0.51, 0.11, 0);
	drawLines(-440, -175, -315, -175);


	glColor3f(1, 1.32, 0.13);
	drawPolygon(-400, -60, -360, -60, -360, -70, -400, -70);

	glColor3f(1, 1.32, 0.13);
	drawPolygon(-400, -120, -360, -120, -360, -130, -400, -130);

	glColor3f(1, 1.32, 0.13);
	drawPolygon(-400, -190, -360, -190, -360, -200, -400, -200);

	//----------------------- screen base

	glColor3f(0, 0, 0);
	drawPolygon(-360, 40, -360, 25, -300, 25, -300, 40);

	//----------------------- screen base

	glColor3f(0, 0, 0);
	drawPolygon(-350, 55, -350, 40, -310, 40, -310, 55);

	//----------------------- screen frame

	glColor3f(0, 0, 0);
	drawPolygon(-430, 210, -430, 55, -230, 55, -230, 210);



	//----------------------- screen PC

	glColor3f(0, 0, 1);
	drawPolygon(-425, 205, -425, 60, -235, 60, -235, 205);


	//------------- text inside the screen 
	glColor3f(1, 1, 1);
	output(-410, 170, string1);
	output(-410, 120, string2);
	glColor3f(1, 1, 1);
	output(-410, 80, string3);


	//--------------------------------- the lamp


	//glColor3f(0.5, 0.5, 0.5);
	drawquads(-120, 310, 0, 310, -40, 375, -80, 375);
	glColor3f(red, green, blue);
	drawquads(-100, 310, -20, 310, 30, 250, -150, 250);
	glColor3f(0.5, 0.5, 0.5);
	drawLines(-60, 375, -60, 500);




	//------------------------------

	glFlush();

}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1920, 1080);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("COMPUTER GRAPHICS - OFFICE ROOM");
	glClearColor(0.85, 0.85, 0.85, 0.85);
	glOrtho(-500, 500, -500, 500, -500, 500);
	glutDisplayFunc(draw);
	menu();
	glutIdleFunc(rotatefunction);
	glutKeyboardFunc(normalKey);
	glutMainLoop();
	return 0;
}