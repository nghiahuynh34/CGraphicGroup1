#include <GL/glut.h>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
//#include <GL/>
GLuint g_sun;
GLuint g_earth;
GLuint g_moon;
GLuint g_mercury;
GLuint g_mars;
GLuint g_venus;
GLuint g_jumpiter;
GLuint g_santurn;
GLuint g_uranus;
GLuint g_neptune;
 
GLuint g_angle_day = 0;
GLuint g_angle_year = 0;
GLuint gl_angle_moon = 0;
GLfloat g_angle_mercury = 0;
GLfloat g_angle_venus = 0;
GLfloat g_angle_mars = 0;
GLfloat g_angle_jumpiter = 0;
GLfloat g_angle_santurn = 0;
GLfloat g_angle_uranus = 0;
GLfloat g_angle_neptune = 0;

GLuint g_earthTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_sunTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_moonTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_mercuryTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_venusTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_marsTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_jumpiterTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_santurnTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_uranusTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_neptuneTextureID; // Thêm bi?n này d? luu ID c?a texture

GLfloat g_angle_quick = 0;

GLfloat posX=0.0;
GLfloat posY=70.0;
GLfloat posZ=0.0;
GLfloat eyeX=1.0;
GLfloat eyeY=0.0;
GLfloat eyeZ=0.0;

const int numPlanets = 9;
//float planetRadii[numPlanets] = {0.2f, 0.1f, 0.15f,0.2f, 0.1f, 0.15f};
float planetDistances[numPlanets] = {0.0f,6.0,8.0, 10.0f, 12.0f,16.0f,20.0f,23.0f,25.0f};
//float planetSpeeds[numPlanets] = {1.0f, 0.5f, 0.3f,1.0f, 0.5f, 0.3f};
// GLuint g_santurn_ring;
// GLuint g_earthTexture; // Bi?n d? luu ID c?a texture
// 

 void loadPlanetTexture(const char *file, GLuint &ID) {
 	 int width, height, channels;
    unsigned char* data = stbi_load(file, &width, &height, &channels, STBI_rgb_alpha);
    if (!data) {
    std::cout << "Failed to load texture."<<std::endl;
    return;
}
 		glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
}
void loadImage(){
		loadPlanetTexture("4.jpg",g_earthTextureID);
		loadPlanetTexture("sun1.jpg",g_sunTextureID);
		loadPlanetTexture("moon4.jpg",g_moonTextureID);
		loadPlanetTexture("mc3.jpg",g_mercuryTextureID);
		loadPlanetTexture("venus.jpg",g_venusTextureID);
	}
GLuint MakeSphere(const float& radius)
{
    GLuint sphereDisplay = glGenLists(1);
    glNewList(sphereDisplay, GL_COMPILE);

    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);

    gluSphere(quadric, radius, 64, 32);

    gluDeleteQuadric(quadric);
    glEndList();

 
    return sphereDisplay;
}
void renderBitmapString(float x, float y, float z, void *font, const char *string) {
    const char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void RendenScene()
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(posX, posY, posZ, 0.0, 0.0, 0.0, eyeX, eyeY, eyeZ);
	// Draw orbits for each planet
    glColor3f(0.9, 1.3, 0.3);  // Set orbit color (gray)
    for (int i = 1; i < numPlanets; i++) {
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 360; j++) {
            float theta = static_cast<float>(j) * M_PI / 180.0;
            float x = planetDistances[i] * cosf(theta);
            float y = planetDistances[i] * sinf(theta);
            glVertex3f(x, 0.0, y);
        }
        glEnd();
    }
     glRotatef (5, 0.0f, 0.0f, 0.0f);
  GLfloat mat_ambien[] = {1.0, 1.0, 0.0f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien);
  GLfloat diff[] = {05, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
//glEnable(GL_TEXTURE_2D);
glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_sunTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_sun);
    glDisable(GL_TEXTURE_2D);

 
    renderBitmapString(2.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun");
  //mercury
	glPushMatrix();
  glRotatef (g_angle_mercury, 0.0f, 1.0f, 0.0f);
  glTranslated(6.0, 0.0, 0.0);
  GLfloat mat_ambien4[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien4);
  GLfloat diff4[] = {1.0, 1.0, 0.2, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff4);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_mercuryTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_mercury);
    glDisable(GL_TEXTURE_2D);
  
//   glRasterPos3f(1.5, 0.0, 0.0);
//    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, E);
renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mercury");
  glPopMatrix();
  //venus
glPushMatrix();
  glRotatef (g_angle_venus, 0.0f, 1.0f, 0.0f);
  glTranslated(8.0, 0.0, 0.0);
  GLfloat mat_ambien5[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien5);
  GLfloat diff5[] = {1.0, 1.0, 0.5, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff5);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_venusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
glCallList(g_venus);
    glDisable(GL_TEXTURE_2D);
  
   renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
  glPopMatrix();
 //mars
 glPushMatrix();
  glRotatef (g_angle_mars, 0.0f, 1.0f, 0.0f);
  glTranslated(12.0, 0.0, 0.0);
  GLfloat mat_ambien6[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien6);
  GLfloat diff6[] = {0.4, 0.5, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff6);
  glCallList(g_mars);
   renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
  glPopMatrix();
// jumpiter
glPushMatrix();
  glRotatef (g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
  glTranslated(16.0, 0.0, 0.0);
  GLfloat mat_ambien7[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien7);
  GLfloat diff7[] = {0.5, 1.0, 0.3, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff7);
  glCallList(g_jumpiter);
   renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Jupiter");
  glPopMatrix();
  //santurn
  glPushMatrix();
// for (int i = 1; i < 2; i++) {
//        glBegin(GL_LINE_LOOP);
//        for (int j = 0; j < 360; j++) {
//            float theta = static_cast<float>(j) * M_PI / 180.0;
//            float x = planetDistances[i] * cosf(theta);
//            float y = planetDistances[i] * sinf(theta);
//            glVertex3f(x, 0.0, y);
//        }
//        glEnd();
//    }
  glRotatef (g_angle_santurn, 0.0f, 1.0f, 0.0f);
  glTranslated(20.0, 0.0, 0.0);
  GLfloat mat_ambien8[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien8);
  GLfloat diff8[] = {1.0, 0.4, 1.0, 0.5};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff8);
  glCallList(g_santurn);
  renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Saturn");
  glPopMatrix();
  
  //uranus
  glPushMatrix();
  glRotatef (g_angle_uranus, 0.0f, 1.0f, 0.0f);
  glTranslated(23.0, 0.0, 0.0);
  GLfloat mat_ambien9[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien9);
  GLfloat diff9[] = {1.0, 1.0, 0.4, 0.6};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff9);
  glCallList(g_uranus);
   renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
  glPopMatrix();
  //neptune
  glPushMatrix();
  glRotatef (g_angle_neptune, 0.0f, 1.0f, 0.0f);
  glTranslated(25.0, 0.0, 0.0);
  GLfloat mat_ambien10[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien10);
  GLfloat diff10[] = {0.2, 1.0, 1.0, 0.4};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff10);
  glCallList(g_neptune);
   renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Neptune");
  glPopMatrix();
 //earth
// glPushMatrix();
  glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
  glTranslated(10.0, 0.0, 0.0);
  glRotatef (g_angle_day, 0.0f, 1.0f, 0.0f);
 
//  GLfloat mat_ambien2[] = {0.0, 0.0, 1.0f, 1.0f};
//  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien2);
//  GLfloat diff2[] = {1.5, 1.0, 1.0, 1.0};
//  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
//  
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, g_earthTextureID);
  glCallList(g_earth);
  glDisable(GL_TEXTURE_2D);
	renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Earth");
	
  glPushMatrix();
  glRotatef (gl_angle_moon, 0.0f, 1.0f, 0.0f);
  glTranslated(2.0, 0.0, 0.0);
  GLfloat mat_ambien3[] = {0.7, 0.7, 0.7f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);
  GLfloat diff3[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
 glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_moonTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_moon);
    glDisable(GL_TEXTURE_2D);
   renderBitmapString(0.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");
  glPopMatrix();
 
   
    
  Sleep(83);
  gl_angle_moon = (gl_angle_moon + 13+g_angle_quick);
  if (gl_angle_moon >= 360)
  {
    gl_angle_moon = 0;
  }
 
  g_angle_day = (g_angle_day + 360+g_angle_quick);
  if (g_angle_day >= 360)
  {
    g_angle_day = 0;
  }
 
  g_angle_year = (g_angle_year + 1+g_angle_quick);
  if (g_angle_year >= 360)
  {
    g_angle_year = 0;
  }
   g_angle_mercury = (g_angle_mercury + 5+g_angle_quick);
  if (g_angle_mercury >= 360)
  {
    g_angle_mercury = 0;
  }
    g_angle_venus = (g_angle_venus +  2+g_angle_quick);
  if (g_angle_venus >= 360)
  {
    g_angle_venus = 0;
  }
   g_angle_mars = (g_angle_mars +  0.5+g_angle_quick);
  if (g_angle_mars >= 360)
  {
    g_angle_mars = 0;
  }
    g_angle_jumpiter = (g_angle_jumpiter + 0.07+g_angle_quick);
  if (g_angle_jumpiter >= 360)
  {
    g_angle_jumpiter = 0;
  }
   g_angle_santurn = (g_angle_santurn +  0.04+g_angle_quick);
  if (g_angle_santurn >= 360)
  {
    g_angle_santurn = 0;
  }
   g_angle_uranus = (g_angle_uranus + 0.03+g_angle_quick);
  if (g_angle_uranus >= 360)
  {
    g_angle_uranus = 0;
  }
   g_angle_neptune = (g_angle_neptune + 0.02+g_angle_quick);
  if (g_angle_neptune >= 360)
  {
    g_angle_neptune = 0;
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
  gluPerspective(45.0, ratio, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
}
 
 void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'n':
        posX=35.0;
		 posY=50.0;
		 posZ=35.0;
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
		 posY=-70.0;
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
 
    }
}
 
void Init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-5, 5, -5, 5, -1, 1);
  glEnable(GL_DEPTH_TEST);
 
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
 
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
  g_sun = MakeSphere(2.0);
  g_earth = MakeSphere(1.0);
  g_moon = MakeSphere(0.5);
  g_mercury = MakeSphere(0.6);
  g_venus = MakeSphere(0.8);
  g_mars = MakeSphere(0.65);
  g_jumpiter=MakeSphere(1.5);
  g_santurn=MakeSphere(1.2);
  g_uranus=MakeSphere(1.0);
  g_neptune=MakeSphere(0.75);
}
 
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE  |GLUT_RGB);
  glutInitWindowSize(850, 850);
  glutInitWindowPosition(250, 100);
  glutCreateWindow("Opengl Study");
 
  Init();
  glutKeyboardFunc(keyboard);  
  glutReshapeFunc(ReShape);
  glutDisplayFunc(RendenScene);
 
  glutMainLoop();
 return 0;

}
