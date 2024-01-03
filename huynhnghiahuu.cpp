#include <iostream>
#include "funtion.h"
#include <GL/glut.h>

GLfloat posX=0.0;
GLfloat posY=90.0;
GLfloat posZ=0.0;
GLfloat eyeX=1.0;
GLfloat eyeY=0.0;
GLfloat eyeZ=0.0;

GLfloat g_angle_quick = 0;

double planetX = 200.0;
double planetY = 200.0;
bool dragging = false;
bool turn = false;

//void drawStar() {
//glMatrixMode(GL_PROJECTION);
//    glPushMatrix();
//    glLoadIdentity();
//    gluOrtho2D(0, 800, 0, 800); // Adjust screenWidth and screenHeight accordingly
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//    glLoadIdentity();
//    if (starPositionX != -1 && starPositionY != -1) {
////    	std::cout<<"ok";
//        glColor3f(1.0, 1.0, 1.0);  // Màu tr?ng
//        glBegin(GL_TRIANGLES);
//        glVertex2d(starPositionX, starPositionY);
//        glVertex2d(starPositionX - 10, starPositionY - 20);
//        glVertex2d(starPositionX + 10, starPositionY - 20);
//        glEnd();
//    }
//     glPopMatrix();
//    glMatrixMode(GL_PROJECTION);
//    glPopMatrix();
//    glMatrixMode(GL_MODELVIEW);
//    glFlush();
//}

void RendenScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(posX, posY, posZ, 0.0, 0.0, 0.0, eyeX, eyeY, eyeZ);
	drawBackground();
 	glClear(GL_DEPTH_BUFFER_BIT);
    // Enable depth testing for correct 3D rendering
    glEnable(GL_DEPTH_TEST);
    display_Name();
	drawOrbits();
	
	drawSun();
	drawMercury();
	drawVenus();
	drawMars();
	drawJupiter();
	drawSanturn();
	drawUranus();
	drawNeptune();
	drawEarth();
	drawMoon();
    glDisable(GL_DEPTH_TEST);
	if(turn){
		Sleep(83);
		turning(g_angle_quick);
	}
  	glutSwapBuffers();
	glutPostRedisplay();
}
 
void ReShape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float ratio = (float)width/(float)height;
  gluPerspective(70.0, ratio, 1, 170.0);
  glMatrixMode(GL_MODELVIEW);
}
 
 void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'n':
        posX+=5;
		 posY=40.0;
		 posZ+=5;
		 eyeX =0.0;
		 eyeY=1.0;
		 eyeZ=0.0;
        glutPostRedisplay();
        break;
    case 'a':
        posX=0.0;
		 posY=70.0;
		 posZ=0.0;
		 eyeX =1.0;
		 eyeY=0.0;
		 eyeZ=0.0;
        glutPostRedisplay();
        break;
    case 'u':
        posX=0.0;
		 posY=-100.0;
		 posZ=0.0;
		 eyeX =1.0;
		 eyeY=0.0;
		 eyeZ=0.0;
        glutPostRedisplay();
        break;
    case 'q':
        g_angle_quick+=2;
        glutPostRedisplay();
        break;
 	case 's':
        g_angle_quick-=2;
        glutPostRedisplay();
        break;
 	case 'z':
        posX=0.0;
		 posY-=1;
		 posZ=0.0;
		 eyeX =1.0;
		 eyeY=0.0;
		 eyeZ=0.0;
        glutPostRedisplay();
        break;
    case 'o':
        posX=0.0;
		posY+=1;
		posZ=0.0;
		eyeX =1.0;
		eyeY=0.0;
		eyeZ=0.0;
        glutPostRedisplay();
        break;
    case 't':
      	turn=true;
        glutPostRedisplay();
        break;
    }
    
}
void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
//        	std::cout<<planetX<<" "<<planetY<<" "<<x<<" "<<y;
            // Ki?m tra xem chu?t có ? trên hành tinh hay không
            if(x >= planetX && x <= planetX + 50 && y >= planetY && y <= planetY + 50) {
                dragging = true;
                std::cout<<planetX<<" "<<planetY<<" "<<x<<" "<<y;
            }
        } else if(state == GLUT_UP) {
            dragging = false;
        }
    }
}
void mouseMotion(int x, int y) {
    if (dragging) {
        // Di chuy?n hành tinh theo v? trí c?a chu?t
        planetX = x - 25; // Ði?u ch?nh gi?a hành tinh
        planetY = glutGet(GLUT_WINDOW_HEIGHT) - y - 25; // Ð?o ngu?c tr?c y
        std::cout<<planetX<<" "<<planetY;
    }
}

void Init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
//  glDisable(GL_LIGHTING);
	GLfloat light_pos [] = {1.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	 
	GLfloat ambient[] = {1.0, 1.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	GLfloat diff_use[] = {0.5, 0.5, 0.0, 1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	 
	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	loadImage();
	loadPlanet();
}
 
int main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE  |GLUT_RGB);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(250, 100);
  glutCreateWindow("Opengl Study");
  Init();
  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMotion);
  glutKeyboardFunc(keyboard); 
  glutReshapeFunc(ReShape);
  glutDisplayFunc(RendenScene);
  glutMainLoop();
  return 0;
}
