#include <GL/glut.h>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <Windows.h>
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
GLuint g_backgroundTextureID; // Thêm bi?n này d? luu ID c?a texture
GLuint g_CirleTextureID; 

GLfloat g_angle_quick = 0;

GLfloat posX=0.0;
GLfloat posY=90.0;
GLfloat posZ=0.0;
GLfloat eyeX=1.0;
GLfloat eyeY=0.0;
GLfloat eyeZ=0.0;

// Insert name: Kieu 
GLubyte rastersK[32] = {
    0x30,   0xF0,
    0x59,   0xC8,
    0x19,   0x80,
    0x19,   0x80,
    0x19,   0x80,
    0x19,   0x80,
    0x19,   0x80,
    0x1B,   0x80,
    0x1F,   0x00,
    0x1C,   0x00,
    0x1E,   0x00,
    0x1B,   0x00,
    0xC9,   0x08,
    0xC9,   0x18,
    0xD9,   0xB0,
    0x70,   0xE0
};
GLubyte rastersI[32] = {
    0x1F,   0x00,
0x23,   0x80,
0x41,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x01,   0x80,
0x71,   0x80,
0x81,   0x80,
0xC1,   0x80,
0x7F,   0x80

};
GLubyte rastersE[32] = {
    0x3F,   0x00,
0x70,   0x80,
0x60,   0x40,
0x60,   0x00,
0x60,   0x00,
0x60,   0x00,
0x30,   0x00,
0x1F,   0x80,
0x30,   0x00,
0x60,   0x00,
0x60,   0x00,
0x60,   0x00,
0x60,   0x00,
0x60,   0x40,
0x30,   0x80,
0x1F,   0x00



};
GLubyte rastersU[32] = {
    0x07,   0x9C,
0x0C,   0xF2,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0x0C,   0x60,
0xCC,   0x60,
0x8C,   0x60,
0xCC,   0x60,
0x7C,   0x60,

};
GLubyte rastersD[32] = {
    0x00, 0x00,
0x00, 0x00,
0x88, 0x00,
0x50, 0x00,
0x20, 0x00,
0x08, 0x00,
0x04, 0x00,
0x02, 0x00,
0x1A, 0x00,
0x0E, 0x00,
0x04, 0x00,
0x00, 0x00,
0x00, 0x00,
0x00, 0x00,
0x00, 0x00,
0x00, 0x00
};


// Insert name: Nghia
GLubyte rasters[42] = { 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x70,0x40,0x88,0xa0, 0x84,0xa0, 0x94,0xa0, 0x64,0xa0, 0x04,0xa0,0x04,0xa0, 0x05,0x20, 0x05,0x20, 0x25,0x20, 0x45,0x22, 0x45,0x25, 0x25,0x21, 0x1a,0x11, 0x00,0x0e, 0x00,0x00, 0x00,0x00, 0x00,0x00
};
GLubyte rasters2[42] = { 0x01,0xc0, 0x02,0x20, 0x00,0x10, 0x00,0x10,  0x00,0x10, 0x00,0x10, 0x07,0xd0, 0x08,0x30, 0x10,0x10, 0x10,0x38, 0x10,0x00, 0x10,0x00, 0x10,0x00, 0x10,0x08, 0x10,0x08, 0x08,0x10, 0x07,0xe0, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00 
};
GLubyte raster3s[42] = {
        0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        0x18, 0x0c,
        0x24, 0x12,
        0x24, 0x12,
        0x14, 0x10,
        0x0c, 0x10,
        0x04, 0x90,
        0x06, 0x90,
        0x05, 0x90,
        0x04, 0xd0,
        0x34, 0xb0,
        0x4c, 0x98,
        0x44, 0x14,
        0x44, 0x12,
        0x3c, 0x12,
        0x00, 0x0c,
        0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00 };
GLubyte raster4s[42] = { 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,  0x03,0xc0, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x01,0x80, 0x03,0xc0, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00
};
GLubyte raster5s[42] = { 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,  0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x04,0x60, 0x02,0x90, 0x01,0x08
};
GLubyte raster6s[42] = { 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x60,0x00,  0x90,0x00, 0x08,0x0f, 0x04,0x09, 0x04,0x08, 0x02,0x08, 0x03,0xf8, 0x01,0x08, 0x01,0x08, 0x04,0x88, 0x04,0x88, 0x08,0x88, 0x08,0x48, 0x04,0x48, 0x03,0xa8, 0x00,0x10, 0x00,0x00, 0x00,0x00
};

// Insert name: Hieu
GLubyte hraster[34] = {
    0x30,0x18,0x48,0x24,0x84,0x42,0x44,0x4a,0x25,0x54,0x15,0x4e,0x0d,0x41,0x07,0x40,0x05,
    0xc0,0x45,0x40,0x85,0x40,0x44,0x60,0x24,0x50,0xd4,0x48,0xa4,0x88,0x48,0x58,0x30,0x20
};
GLubyte iraster[34] = {
    0x01,0x80,0x02,0x60,0x04,0x30,0x04,0x10,0x04,0x10,0x02,0x90,0x01,0x50,0x06,0x90,0x08,
    0x10,0x10,0x50,0x00,0x90,0x01,0x10,0x06,0x90,0x09,0x10,0x08,0x10,0x05,0xd0,0x02,0x30
};
GLubyte eraster[50] = {
    0x00,0xc0,0x01,0x20,0x02,0x10,0x04,0x28,0x08,0x50,0x08,0x28,0x05,0x04,0x02,0x82,0x05,
    0x00,0x08,0x00,0x08,0xc0,0x05,0x20,0x32,0x10,0x4c,0x08,0x82,0x10,0x49,0x20,0x30,0xc0,

    0x00,0x00,0x02,0x08,0x01,0x10,0x00,0xa0,
    0x00,0x48,0x00,0x04,0x00,0x2,0x00,0x01
};
GLubyte uraster[36] = {
    0x01,0xd0,0x02,0x28,0x04,0x24,0x04,0x23,0x04,0x26,0x04,0x2a,0x04,0x24,0x04,0x20,0x44,
    0x20,0x84,0x20,0x64,0x20,0x44,0x28,0x84,0x24,0x84,0x22,0x44,0x22,0x24,0x12,0x1c,0x0c
};

const int numPlanets = 9;
//float planetRadii[numPlanets] = {0.2f, 0.1f, 0.15f,0.2f, 0.1f, 0.15f};
float planetDistances[numPlanets] = {0.0f,10.0f,15.0f,20.0f, 25.0f, 32.0f,42.0f,50.0f,56.0f};
float circleDistances[numPlanets] = {3.0f,3.5f,3.7f,3.9f, 4.0f,4.25f, 4.5f,4.75f,5.0f};
//float planetSpeeds[numPlanets] = {1.0f, 0.5f, 0.3f,1.0f, 0.5f, 0.3f};
// GLuint g_santurn_ring;
// GLuint g_earthTexture; // Bi?n d? luu ID c?a texture
// 

 void loadPlanetTexture(const char *file, GLuint &ID) {
 	 int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    std::cout << "Screen resolution: " << screenWidth << "x" << screenHeight << std::endl;
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
void loadImage() {
    loadPlanetTexture("4.jpg", g_earthTextureID);
    loadPlanetTexture("sun1.jpg", g_sunTextureID);
    loadPlanetTexture("moon4.jpg", g_moonTextureID);
    loadPlanetTexture("mc7.jpg", g_mercuryTextureID);
    loadPlanetTexture("v3.jpg", g_venusTextureID);
    loadPlanetTexture("mars3.jpg", g_marsTextureID);
    loadPlanetTexture("jp.jpg", g_jumpiterTextureID);
    loadPlanetTexture("st2.jpg", g_santurnTextureID);
    loadPlanetTexture("u2.jpg", g_uranusTextureID);
    loadPlanetTexture("n.jpg", g_neptuneTextureID);
    loadPlanetTexture("bg1.jpg", g_backgroundTextureID);
}
void display_Name()
{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glRasterPos2f(800 - 100, 600 - 20); // Adjust position as needed
//    glBitmap(16, 16, -28.0, 1.0, 0.0, -16.0, rastersD);
//    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, rastersK);
//    glBitmap(16, 16, 0.0, 0.0, 10.0, 0.0, rastersI);
//    glBitmap(16, 16, 0.0, 0.0, 10.0, 0.0, rastersE);
//    glBitmap(16, 16, -2.0, 0.0, 10.0, 0.0, rastersU);
//    glFlush();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800); // Adjust screenWidth and screenHeight accordingly
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(5, 800 - 10); // Adjust position as needed
    glBitmap(16, 16, -28.0, 1.0, 0.0, -16.0, rastersD);
    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, rastersK);
    glBitmap(16, 16, 0.0, 0.0, 10.0, 0.0, rastersI);
    glBitmap(16, 16, 0.0, 0.0, 10.0, 0.0, rastersE);
    glBitmap(16, 16, -2.0, 0.0, 35.0, 0.0, rastersU);
    //    hieu
//  glRasterPos2f(5, 800 - 20); // Adjust position as needed
    glBitmap(16, 18, 0.0, 0.0, 18.0, 0.0, hraster);
    glBitmap(16, 18, 0.0, 0.0, 18.0, 0.0, iraster);
    glBitmap(16, 28, 0.0, 0.0, 18.0, 0.0, eraster);
    glBitmap(16, 18, 0.0, 0.0, 35.0, 0.0, uraster);
    //nghia
//     glRasterPos2f(5, 800 - 20); // Adjust position as needed
	glBitmap(16, 21, 0.0, 0.0, 15.0, 0.0, rasters);
    glBitmap(16, 21, 0.0, 0.0, 15.0, 0.0, rasters2);
    glBitmap(16, 21, 0.0, 0.0, 12.0, 0.0, raster3s);
    glBitmap(16, 21, 0.0, 0.0, 0.0, 0.0, raster4s);
    glBitmap(16, 21, 0.0, 0.0, 13.0, 0.0, raster5s);
    glBitmap(16, 21, 0.0, 0.0, 13.0, 0.0, raster6s);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glFlush();

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
void drawSun(){
	glRotatef (9.0f, 0.0f, 0.0f, 0.0f);

	glPushMatrix();
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0}; // Cài d?t màu ph?n x?
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	GLfloat shininess = 100.0; // Ð? bóng c?a b? m?t
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0}; // Cài d?t ánh sáng khu v?c
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	GLfloat constant_attenuation = 1.0;
	GLfloat linear_attenuation = 0.001;
	GLfloat quadratic_attenuation = 0.001;
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constant_attenuation);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linear_attenuation);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_sunTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 	glCallList(g_sun);
    glDisable(GL_TEXTURE_2D);

 
    renderBitmapString(2.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun");
    glPopMatrix();
	}
	
void drawMoon(){
		
  glPushMatrix();
  glRotatef (gl_angle_moon, 0.0f, 1.0f, 0.0f);
  glTranslated(3.0, 0.0, 0.0);
  GLfloat mat_ambien3[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);
  GLfloat diff3[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
 glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_moonTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_moon);
    glDisable(GL_TEXTURE_2D);
   renderBitmapString(0.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");
  glPopMatrix();
}
void drawEarth(){
	glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
  glTranslated(20.0, 0.0, 0.0);
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
}

void drawMercury(){
	  
	glPushMatrix();
  glRotatef (g_angle_mercury, 0.0f, 1.0f, 0.0f);
  glTranslated(10.0, 0.0, 0.0);
  GLfloat mat_ambien4[] = {1.0, 1.0, 1.0f, 1.0f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien4);
  GLfloat diff4[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff4);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_mercuryTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_mercury);
    glDisable(GL_TEXTURE_2D);
  
//   glRasterPos3f(1.5, 0.0, 0.0);
//    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, E);
renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mercury");
  glPopMatrix();
}
void drawMars(){
	//mars
 glPushMatrix();
  glRotatef (g_angle_mars, 0.0f, 1.0f, 0.0f);
  glTranslated(25.0, 0.0, 0.0);
  GLfloat mat_ambien6[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien6);
  GLfloat diff6[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff6);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_marsTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
  glCallList(g_mars);
    glDisable(GL_TEXTURE_2D);
 
   renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
  glPopMatrix();
}
void drawVenus(){
	//venus
glPushMatrix();
  glRotatef (g_angle_venus, 0.0f, 1.0f, 0.0f);
  glTranslated(15.0, 0.0, 0.0);
  GLfloat mat_ambien5[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien5);
  GLfloat diff5[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff5);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_venusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
glCallList(g_venus);
    glDisable(GL_TEXTURE_2D);
  
   renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
  glPopMatrix();
}
void drawJupiter(){
	glPushMatrix();
  glRotatef (g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
  glTranslated(32.0, 0.0, 0.0);
  GLfloat mat_ambien7[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien7);
  GLfloat diff7[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff7);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_jumpiterTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_jumpiter);
    glDisable(GL_TEXTURE_2D);
  
   renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Jupiter");
  glPopMatrix();
}
void drawSanturn(){
	  glPushMatrix();
//glColor3f(1.0, 0.4, 1.3);  // Set orbit color (gray)
   
  glRotatef (g_angle_santurn, 0.0f, 1.0f, 0.0f);
  glTranslated(42.0, 0.0, 0.0);
  GLfloat mat_ambien8[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien8);
  GLfloat diff8[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff8);
  
 
  glPushAttrib(GL_LINE_BIT);
   glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_CirleTextureID); 
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glLineWidth(2.5f);
   for (int i = 1; i < 9; i++) {
//       glBegin(GL_TRIANGLE_FAN);
glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 360; j++) {
            float theta = static_cast<float>(j) * M_PI / 180.0;
            float x = circleDistances[i] * cosf(theta);
            float y = 3.5 * sinf(theta);
             glTexCoord2f(x, y);
            glVertex3f(-x, 0.0, -y);
        }
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
    glPopAttrib();
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_santurnTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
// glCallList(g_mercury);
   glCallList(g_santurn);
   glDisable(GL_TEXTURE_2D);
  renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Saturn");
  glPopMatrix();
}
void drawUranus(){
	 //uranus
  glPushMatrix();
  glRotatef (g_angle_uranus, 0.0f, 1.0f, 0.0f);
  glTranslated(50.0, 0.0, 0.0);
  GLfloat mat_ambien9[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien9);
  GLfloat diff9[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff9);
  
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_uranusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_uranus);
   glDisable(GL_TEXTURE_2D);
   renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
  glPopMatrix();
}
void drawNeptune(){
	
  //neptune
  glPushMatrix();
  glRotatef (g_angle_neptune, 0.0f, 1.0f, 0.0f);
  glTranslated(56.0, 0.0, 0.0);
  GLfloat mat_ambien10[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien10);
  GLfloat diff10[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff10);
  
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_neptuneTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
 glCallList(g_mercury);
   glCallList(g_neptune);
   glDisable(GL_TEXTURE_2D);
   renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Neptune");
  glPopMatrix();
}
void drawBackground() {
	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);  // Adjust the values based on your needs

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
   
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_backgroundTextureID);
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
     glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
void drawOrbits(){
		// Draw orbits for each planet
    glColor3f(1.0, 1.0, 1.0); 
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
}
void RendenScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(posX, posY, posZ, 0.0, 0.0, 0.0, eyeX, eyeY, eyeZ);
//	glClearColor(0.8, 0.8, 0.8, 1.0);
	drawBackground();
 glClear(GL_DEPTH_BUFFER_BIT);

    // Enable depth testing for correct 3D rendering
    glEnable(GL_DEPTH_TEST);
    display_Name();
	drawOrbits();
//	loadName();
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
  gluPerspective(70.0, ratio, 1, 170.0);
//  glOrtho(-ratio, ratio, -1, 1, -1, 1);

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
    }
    
    
}
 
void Init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glClearColor(1.0, 1.0, 1.0, 1.0);
//	glOrtho(-5, 5, -5, 5, -1, 1);
  glEnable(GL_DEPTH_TEST);
//  glEnable(GL_TEXTURE_2D);
GLfloat globalAmbient[] = {0.3, 0.3, 0.3, 0.3}; // Ði?u ch?nh giá tr? theo nhu c?u

glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
//  glDisable(GL_LIGHTING);
 
  GLfloat light_pos [] = {1.0, 1.0, 1.0, 0.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
 
  GLfloat ambient[] = {1.0, 1.0, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
 
  GLfloat diff_use[] = {0.5, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
//GLfloat materialAmbient[] = {1.0, 1.0, 1.0, 1.0};
//GLfloat materialDiffuse[] = {1.0, 1.0, 1.0, 1.0};
//
//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient);
//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
// 
  GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
 
  GLfloat shininess = 50.0f;
  glMateriali(GL_FRONT, GL_SHININESS, shininess);
	loadImage();
  g_sun = MakeSphere(6.0);
  g_earth = MakeSphere(1.75);
  g_moon = MakeSphere(0.7);
  g_mercury = MakeSphere(0.8);
  g_venus = MakeSphere(1.1);
  g_mars = MakeSphere(1.5);
  g_jumpiter=MakeSphere(3.6);
  g_santurn=MakeSphere(2.9);
  g_uranus=MakeSphere(2.5);
  g_neptune=MakeSphere(2.2);
}
 
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE  |GLUT_RGB);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(250, 100);
  glutCreateWindow("Opengl Study");
 
  Init();
  glutKeyboardFunc(keyboard);  
  glutReshapeFunc(ReShape);
  glutDisplayFunc(RendenScene);
 
  glutMainLoop();
 return 0;

}
//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <GL/gl.h>
//#include <math.h>
////#include <shader.h>
//#include <vector>
//
//#define CALLBACK
//# define M_PI           3.14159265358979323846
//#define STB_IMAGE_IMPLEMENTATION
//#include<windows.h>
//#include "stb_image.h"
//#include <iostream>
//GLuint g_sun;
//GLuint g_earth;
//GLuint g_moon;
//GLuint g_mercury;
//GLuint g_mars;
//GLuint g_venus;
//GLuint g_jumpiter;
//GLuint g_santurn;
//GLuint g_uranus;
//GLuint g_neptune;
//
//GLuint g_angle_day = 0;
//GLuint g_angle_year = 0;
//GLuint gl_angle_moon = 0;
//GLfloat g_angle_mercury = 0;
//GLfloat g_angle_venus = 0;
//GLfloat g_angle_mars = 0;
//GLfloat g_angle_jumpiter = 0;
//GLfloat g_angle_santurn = 0;
//GLfloat g_angle_uranus = 0;
//GLfloat g_angle_neptune = 0;
//
//GLuint g_earthTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_sunTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_moonTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_mercuryTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_venusTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_marsTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_jumpiterTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_santurnTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_uranusTextureID; // Thêm bi?n này d? luu ID c?a texture
//GLuint g_neptuneTextureID; // Thêm bi?n này d? luu ID c?a texture
//
//GLfloat g_angle_quick = 0;
//
//GLfloat posX = 0.0;
//GLfloat posY = 70.0;
//GLfloat posZ = 0.0;
//GLfloat eyeX = 1.0;
//GLfloat eyeY = 0.0;
//GLfloat eyeZ = 0.0;
//
//const int numPlanets = 9;
////float planetRadii[numPlanets] = {0.2f, 0.1f, 0.15f,0.2f, 0.1f, 0.15f};
//float planetDistances[numPlanets] = { 0.0f,6.0,8.0, 10.0f, 12.0f,16.0f,20.0f,23.0f,25.0f };
//
//
//
//
//
//
////void load() {
////
////    load the shader
////    shader simpleshader("src/shader.vert", "src/shader.frag");
////    g_simpleshader = simpleshader.program;
////
////     create the vao where we store all geometry (stored in g_vao)
////    g_vao = gl_createandbindvao();
////
////    create vertex buffer for positions, colors, and indices, and bind them to shader
////    gl_createandbindattribute(&(shapes[0].mesh.positions[0]), shapes[0].mesh.positions.size() * sizeof(float), g_simpleshader, "a_vertex", 3);
////    gl_createindexbuffer(&(shapes[0].mesh.indices[0]), shapes[0].mesh.indices.size() * sizeof(unsigned int));
////    gl_createandbindattribute(uvs, uvs_size, g_simpleshader, "a_uv", 2);
////    gl_createandbindattribute(normal, normal_size, g_simpleshader, "a_normal", 2);
////
////    unbind everything
////    gl_unbindvao();
////
////    store number of triangles (use in draw())
////    g_numtriangles = shapes[0].mesh.indices.size() / 3;
////
////    paths of the earth and space textures
////    image* image = loadbmp("assets/earthmap1k.bmp");
////    image* space = loadbmp("assets/milkyway.bmp");
////
////    generate textures
////    glgentextures(1, &texture_id);
////    glgentextures(1, &texture_id2);
////
////    bind textures
////    glbindtexture(gl_texture_2d, texture_id);
////    glbindtexture(gl_texture_2d, texture_id2);
////
////    gltexparameteri(gl_texture_2d, gl_texture_min_filter, gl_linear);
////
////    we assign your corresponding data
////    glteximage2d(gl_texture_2d, 1, gl_rgb, image->width, image->height, gl_rgb, gl_unsigned_byte, image->pixels);
////    glteximage2d(gl_texture_2d, 1, gl_rgb, space->width, space->height, gl_rgb, gl_unsigned_byte, space->pixels);
////
////}
////void draw() {
////
////    1. enable/disable
////    glclear(gl_color_buffer_bit | gl_depth_buffer_bit);
////    gldisable(gl_depth_test);
////    glenable(gl_cull_face);
////    glcullface(gl_front);
////
////    2. shader activation
////    gluseprogram(g_simpleshader);
////
////    3. get all uniform locations
////
////    space:
////    gluint model_loc2 = glgetuniformlocation(g_simpleshader, "u_model");
////    gluint u_texture2 = glgetuniformlocation(g_simpleshader, "u_texture2");
////    gluint u_light_dir2 = glgetuniformlocation(g_simpleshader, "u_light_dir2");
////
////    earth
////    gluint model_loc = glgetuniformlocation(g_simpleshader, "u_model");
////    gluint projection_loc = glgetuniformlocation(g_simpleshader, "u_projection");
////    gluint view_loc = glgetuniformlocation(g_simpleshader, "u_view");
////    gluint u_texture = glgetuniformlocation(g_simpleshader, "u_texture");
////    gluint u_light_dir = glgetuniformlocation(g_simpleshader, "u_light_dir");
////
////    4. get values from all uniforms
////    mat4 model_matrix2 = translate(mat4(1.0f), vec3(1.0f, -3.0f, 1.0f));
////    mat4 model_matrix = translate(mat4(1.0f), vec3(0.0f, -0.35f, 0.0f);
////    mat4 projection_matrix = perspective(60.0f, 1.0f, 0.1f, 50.0f);
////    mat4 view_matrix = lookat(vec3(1.0f, -3.0f, 1.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f)glm::vec3(0, 1, 0));
////
////    5. upload uniforms to shader
////    gluniformmatrix4fv(model_loc2, 1, gl_false, glm::value_ptr(model_matrix2));
////
////    gluniformmatrix4fv(model_loc, 1, gl_false, glm::value_ptr(model_matrix));
////    gluniformmatrix4fv(projection_loc, 1, gl_false, glm::value_ptr(projection_matrix));
////    gluniformmatrix4fv(view_loc, 1, gl_false, glm::value_ptr(view_matrix));
////
////    gluniform1i(u_texture, 0);
////    gluniform3f(u_light_dir, g_light_dir.x, g_light_dir.y, g_light_dir.z);
////
////    gluniform1i(u_texture2, 1);
////    gluniform3f(u_light_dir2, g_light_dir.x, g_light_dir.y, g_light_dir.z);
////
////    6. activate texture unit 0 and bind our texture object
////    glactivetexture(gl_texture0);
////    glactivetexture(gl_texture1);
////
////    glbindtexture(gl_texture_2d, texture_id);
////    glbindtexture(gl_texture_2d, texture_id2);
////
////    7. bind vao
////    gl_bindvao(g_vao);
////
////    8. draw elements
////    gldrawelements(gl_triangles, 3 * g_numtriangles, gl_unsigned_int, 0);
////
////}
//
//void loadPlanetTexture(const char* file, GLuint& ID) {
//    int width, height, channels;
//    unsigned char* data = stbi_load(file, &width, &height, &channels, STBI_rgb_alpha);
//    if (!data) {
//        std::cout << "Failed to load texture." << std::endl;
//        return;
//    }
//    glGenTextures(1, &ID);
//    glBindTexture(GL_TEXTURE_2D, ID);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    stbi_image_free(data);
//}
//void loadImage() {
//    loadPlanetTexture("4.jpg", g_earthTextureID);
//    loadPlanetTexture("sun1.jpg", g_sunTextureID);
//    loadPlanetTexture("moon4.jpg", g_moonTextureID);
//    loadPlanetTexture("mc3.jpg", g_mercuryTextureID);
//    loadPlanetTexture("venus.jpg", g_venusTextureID);
//    loadPlanetTexture("mars1.jpg", g_marsTextureID);
//    loadPlanetTexture("j1.jpg", g_jumpiterTextureID);
//    loadPlanetTexture("st.jpg", g_santurnTextureID);
//    loadPlanetTexture("ura1.jpg", g_uranusTextureID);
//    loadPlanetTexture("nep1.jpg", g_neptuneTextureID);
//}
//GLuint MakeSphere(const float& radius)
//{
//    GLuint sphereDisplay = glGenLists(1);
//    glNewList(sphereDisplay, GL_COMPILE);
//
//    GLUquadricObj* quadric = gluNewQuadric();
//    gluQuadricTexture(quadric, GL_TRUE);
//
//    gluSphere(quadric, radius, 64, 32);
//
//    gluDeleteQuadric(quadric);
//    glEndList();
//
//
//    return sphereDisplay;
//}
//void renderBitmapString(float x, float y, float z, void* font, const char* string) {
//    const char* c;
//    glRasterPos3f(x, y, z);
//    for (c = string; *c != '\0'; c++) {
//        glutBitmapCharacter(font, *c);
//    }
//}
//void RendenScene()
//{
//    
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    gluLookAt(posX, posY, posZ, 0.0, 0.0, 0.0, eyeX, eyeY, eyeZ);
//
//    display_Name();
//
//    // Draw orbits for each planet
//    glColor3f(0.9, 1.3, 0.3);  // Set orbit color (gray)
//    for (int i = 1; i < numPlanets; i++) {
//        glBegin(GL_LINE_LOOP);
//        for (int j = 0; j < 360; j++) {
//            float theta = static_cast<float>(j) * M_PI / 180.0;
//            float x = planetDistances[i] * cosf(theta);
//            float y = planetDistances[i] * sinf(theta);
//            glVertex3f(x, 0.0, y);
//        }
//        glEnd();
//    }
//    glRotatef(5, 0.0f, 0.0f, 0.0f);
//    GLfloat mat_ambien[] = { 1.0, 1.0, 0.0f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien);
//    GLfloat diff[] = { 05, 0.5, 0.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
//    //glEnable(GL_TEXTURE_2D);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_sunTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
//    glCallList(g_sun);
//    glDisable(GL_TEXTURE_2D);
//
//
//    renderBitmapString(2.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun");
//    //mercury
//    glPushMatrix();
//    glRotatef(g_angle_mercury, 0.0f, 1.0f, 0.0f);
//    glTranslated(6.0, 0.0, 0.0);
//    GLfloat mat_ambien4[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien4);
//    GLfloat diff4[] = { 1.0, 1.0, 0.2, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff4);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_mercuryTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
//    glCallList(g_mercury);
//    glDisable(GL_TEXTURE_2D);
//
//    //   glRasterPos3f(1.5, 0.0, 0.0);
//    //    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, E);
//    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mercury");
//    glPopMatrix();
//    //venus
//    glPushMatrix();
//    glRotatef(g_angle_venus, 0.0f, 1.0f, 0.0f);
//    glTranslated(8.0, 0.0, 0.0);
//    GLfloat mat_ambien5[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien5);
//    GLfloat diff5[] = { 1.0, 1.0, 0.5, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff5);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_venusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
//    glCallList(g_venus);
//    glDisable(GL_TEXTURE_2D);
//
//    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
//    glPopMatrix();
//    //mars
//    glPushMatrix();
//    glRotatef(g_angle_mars, 0.0f, 1.0f, 0.0f);
//    glTranslated(12.0, 0.0, 0.0);
//    GLfloat mat_ambien6[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien6);
//    GLfloat diff6[] = { 1.0, 1.0, 0.2, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff6);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_marsTextureID);
//    glCallList(g_mars);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
//    glPopMatrix();
//    // jumpiter
//    glPushMatrix();
//    glRotatef(g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
//    glTranslated(16.0, 0.0, 0.0);
//    GLfloat mat_ambien7[] = { 1.0, 1.0, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien7);
//    GLfloat diff7[] = { 1.5, 1.0, 0.5, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff7);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_jumpiterTextureID);
//    glCallList(g_jumpiter);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Jupiter");
//    glPopMatrix();
//    //santurn
//    glPushMatrix();
//    // for (int i = 1; i < 2; i++) {
//    //        glBegin(GL_LINE_LOOP);
//    //        for (int j = 0; j < 360; j++) {
//    //            float theta = static_cast<float>(j) * M_PI / 180.0;
//    //            float x = planetDistances[i] * cosf(theta);
//    //            float y = planetDistances[i] * sinf(theta);
//    //            glVertex3f(x, 0.0, y);
//    //        }
//    //        glEnd();
//    //    }
//    glRotatef(g_angle_santurn, 0.0f, 1.0f, 0.0f);
//    glTranslated(20.0, 0.0, 0.0);
//    GLfloat mat_ambien8[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien8);
//    GLfloat diff8[] = { 1.0, 1.0, 0.5, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff8);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_santurnTextureID);
//    glCallList(g_santurn);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Saturn");
//    glPopMatrix();
//
//    //uranus
//    glPushMatrix();
//    glRotatef(g_angle_uranus, 0.0f, 1.0f, 0.0f);
//    glTranslated(23.0, 0.0, 0.0);
//    GLfloat mat_ambien9[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien9);
//    GLfloat diff9[] = { 0.0f, 0.5f, 0.8f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff9);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_uranusTextureID);
//    glCallList(g_uranus);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
//    glPopMatrix();
//    //neptune
//    glPushMatrix();
//    glRotatef(g_angle_neptune, 0.0f, 1.0f, 0.0f);
//    glTranslated(25.0, 0.0, 0.0);
//    GLfloat mat_ambien10[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien10);
//    GLfloat diff10[] = { 0.0, 0.5, 1.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff10);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_neptuneTextureID);
//    glCallList(g_neptune);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Neptune");
//    glPopMatrix();
//    //earth
//   // glPushMatrix();
//    glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
//    glTranslated(10.0, 0.0, 0.0);
//    glRotatef(g_angle_day, 0.0f, 1.0f, 0.0f);
//
//    //  GLfloat mat_ambien2[] = {0.0, 0.0, 1.0f, 1.0f};
//    //  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien2);
//    //  GLfloat diff2[] = {1.5, 1.0, 1.0, 1.0};
//    //  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
//    //  
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_earthTextureID);
//    glCallList(g_earth);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Earth");
//
//    glPushMatrix();
//    glRotatef(gl_angle_moon, 0.0f, 1.0f, 0.0f);
//    glTranslated(2.0, 0.0, 0.0);
//    GLfloat mat_ambien3[] = { 0.7, 0.7, 0.7f, 1.0f };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);
//    GLfloat diff3[] = { 1.0, 1.0, 1.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, g_moonTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
//    glCallList(g_moon);
//    glDisable(GL_TEXTURE_2D);
//    renderBitmapString(0.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");
//    glPopMatrix();
//
//
//
//    Sleep(83);
//    gl_angle_moon = (gl_angle_moon + 13 + g_angle_quick);
//    if (gl_angle_moon >= 360)
//    {
//        gl_angle_moon = 0;
//    }
//
//    g_angle_day = (g_angle_day + 360 + g_angle_quick);
//    if (g_angle_day >= 360)
//    {
//        g_angle_day = 0;
//    }
//
//    g_angle_year = (g_angle_year + 1 + g_angle_quick);
//    if (g_angle_year >= 360)
//    {
//        g_angle_year = 0;
//    }
//    g_angle_mercury = (g_angle_mercury + 5 + g_angle_quick);
//    if (g_angle_mercury >= 360)
//    {
//        g_angle_mercury = 0;
//    }
//    g_angle_venus = (g_angle_venus + 2 + g_angle_quick);
//    if (g_angle_venus >= 360)
//    {
//        g_angle_venus = 0;
//    }
//    g_angle_mars = (g_angle_mars + 0.5 + g_angle_quick);
//    if (g_angle_mars >= 360)
//    {
//        g_angle_mars = 0;
//    }
//    g_angle_jumpiter = (g_angle_jumpiter + 0.07 + g_angle_quick);
//    if (g_angle_jumpiter >= 360)
//    {
//        g_angle_jumpiter = 0;
//    }
//    g_angle_santurn = (g_angle_santurn + 0.04 + g_angle_quick);
//    if (g_angle_santurn >= 360)
//    {
//        g_angle_santurn = 0;
//    }
//    g_angle_uranus = (g_angle_uranus + 0.03 + g_angle_quick);
//    if (g_angle_uranus >= 360)
//    {
//        g_angle_uranus = 0;
//    }
//    g_angle_neptune = (g_angle_neptune + 0.02 + g_angle_quick);
//    if (g_angle_neptune >= 360)
//    {
//        g_angle_neptune = 0;
//    }
//    glutSwapBuffers();
//
//    glutPostRedisplay();
//}
//
//void ReShape(int width, int height)
//{
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//
//    glLoadIdentity();
//    float ratio = (float)width / (float)height;
//    gluPerspective(45.0, ratio, 1, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'n':
//        posX = 35.0;
//        posY = 50.0;
//        posZ = 35.0;
//        eyeX = 0.0;
//        eyeY = 1.0;
//        eyeZ = 0.0;
//        glutPostRedisplay();
//        break;
//    case 'a':
//        posX = 0.0;
//        posY = 70.0;
//        posZ = 0.0;
//        eyeX = 1.0;
//        eyeY = 0.0;
//        eyeZ = 0.0;
//        glutPostRedisplay();
//        break;
//    case 'u':
//        posX = 0.0;
//        posY = -70.0;
//        posZ = 0.0;
//        eyeX = 1.0;
//        eyeY = 0.0;
//        eyeZ = 0.0;
//        glutPostRedisplay();
//        break;
//    case 'q':
//        g_angle_quick += 2;
//        glutPostRedisplay();
//        break;
//    case 's':
//        g_angle_quick -= 2;
//        glutPostRedisplay();
//        break;
//
//    }
//}
//
//void Init()
//{
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    //	glOrtho(-5, 5, -5, 5, -1, 1);
//    glEnable(GL_DEPTH_TEST);
//
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//
//    GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
//
//    GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
//
//    GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
//
//    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
//
//    GLfloat shininess = 50.0f;
//    glMateriali(GL_FRONT, GL_SHININESS, shininess);
//    loadImage();
//    g_sun = MakeSphere(2.0);
//    g_earth = MakeSphere(1.0);
//    g_moon = MakeSphere(0.5);
//    g_mercury = MakeSphere(0.6);
//    g_venus = MakeSphere(0.8);
//    g_mars = MakeSphere(0.65);
//    g_jumpiter = MakeSphere(1.5);
//    g_santurn = MakeSphere(1.2);
//    g_uranus = MakeSphere(1.0);
//    g_neptune = MakeSphere(0.75);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(850, 850);
//    glutInitWindowPosition(250, 100);
//    glutCreateWindow("Opengl Study");
//
//    Init();
//    glutKeyboardFunc(keyboard);
//
//    glutReshapeFunc(ReShape);
//    
//    glutDisplayFunc(RendenScene);
//
//    glutMainLoop();
//    return 0;
//
//}

