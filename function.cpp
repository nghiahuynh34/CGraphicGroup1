#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

GLfloat g_angle_moon_turn = 0.0;

GLuint g_earthTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_sunTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_moonTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_mercuryTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_venusTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_marsTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_jumpiterTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_santurnTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_uranusTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_neptuneTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_backgroundTextureID; // Th�m bi?n n�y d? luu ID c?a texture
GLuint g_CirleTextureID; 



const int numPlanets = 9;
//float planetRadii[numPlanets] = {0.2f, 0.1f, 0.15f,0.2f, 0.1f, 0.15f};
float planetDistances[numPlanets] = {0.0f,15.0f,22.0f,30.0f, 37.0f, 47.0f,60.0f,70.0f,77.0f};
float circleDistances[12] = { 4.0f,4.25f,4.3f, 4.5f,4.75f,4.8f,4.9f,5.0f,5.1f,5.15f,5.20f,5.25f};

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

void display_Name()
{
    glMatrixMode(GL_PROJECTION);       // Chuy?n ch? d? ma tr?n hi?n t?i th�nh ch? d? chi?u (GL_PROJECTION).
    glPushMatrix();                    //�ua ma tr?n chi?u hi?n t?i v�o ngan x?p ma tr?n.
    glLoadIdentity();                  //�?t ma tr?n chi?u hi?n t?i th�nh ma tr?n don v?.
    glOrtho(0, 800, 0, 800,-1,1);      // Thi?t l?p ma tr?n chi?u theo ph�p chi?u tr?c giao
    glMatrixMode(GL_MODELVIEW);        //Chuy?n ch? d? ma tr?n hi?n t?i th�nh ch? d? m� h�nh (GL_MODELVIEW).
    glPushMatrix();                    //�ua ma tr?n m� h�nh hi?n t?i v�o ngan x?p ma tr?n.
    glLoadIdentity();                  //�?t ma tr?n m� h�nh hi?n t?i th�nh ma tr?n don v?.
	
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(5, 790);             //�?t v? tr� v? (position) cho c�c k� t? ti?p theo b?t d?u t? di?m (5, 790).
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

    glPopMatrix();               //Kh�i ph?c ma tr?n m� h�nh t? ngan x?p ma tr?n.
    glMatrixMode(GL_PROJECTION); //Chuy?n l?i ch? d? ma tr?n hi?n t?i th�nh ch? d? chi?u.
    glPopMatrix();               //Kh�i ph?c ma tr?n chi?u t? ngan x?p ma tr?n.
    glMatrixMode(GL_MODELVIEW);  //Chuy?n l?i ch? d? ma tr?n hi?n t?i th�nh ch? d? m� h�nh.
    glFlush();                    //L�m cho t?t c? c�c l?nh trong buffer d?m du?c th?c hi?n ngay l?p t?c, kh�ng ch? d?n khi c� th�m l?nh v?.

} 
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
    loadPlanetTexture("e2.jpg", g_earthTextureID);
    loadPlanetTexture("sun1.jpg", g_sunTextureID);
    loadPlanetTexture("moon5.jpg", g_moonTextureID);
    loadPlanetTexture("mc7.jpg", g_mercuryTextureID);
    loadPlanetTexture("venus.bmp", g_venusTextureID);
    loadPlanetTexture("mar.bmp", g_marsTextureID);
    loadPlanetTexture("jp.jpg", g_jumpiterTextureID);
    loadPlanetTexture("st2.jpg", g_santurnTextureID);
    loadPlanetTexture("uranus.bmp", g_uranusTextureID);
    loadPlanetTexture("n.jpg", g_neptuneTextureID);
    loadPlanetTexture("bgns.jpg", g_backgroundTextureID);
 	loadPlanetTexture("st.jpg", g_CirleTextureID);
}
GLuint MakeSphere(const float& radius, GLuint TextureID)
{
    GLuint sphereDisplay = glGenLists(1);            // Tao mot danh s�ch hien thi moi v� lay ID cua n�
    glNewList(sphereDisplay, GL_COMPILE);            //Bat dau ghi c�c lenh ve v�o danh s�ch hien thi voi ID l� sphereDisplay.
    GLUquadricObj *quadric = gluNewQuadric();        // Tao mot doi tuong quadric (doi tuong h�nh tr�n) de ve h�nh cau.
    gluQuadricTexture(quadric, GL_TRUE);             // Cho ph�p su dung toa do texture khi ve h�nh cau.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
    gluSphere(quadric, radius, 64, 32);             //Ve h�nh cau su dung quadric voi b�n k�nh l� radius, 64 duong k�nh, v� 32 duong vi tuyen
//	glutSolidSphere(radius, 64, 32);
	glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quadric);                      // giai phong bo nho 
    glEndList();
    return sphereDisplay;
}
void loadPlanet(){
	g_sun = MakeSphere(7.0,g_sunTextureID);
	g_earth = MakeSphere(1.75,g_earthTextureID);
	g_moon = MakeSphere(0.7,g_moonTextureID);
	g_mercury = MakeSphere(0.8,g_mercuryTextureID);
	g_venus = MakeSphere(1.1,g_venusTextureID);
	g_mars = MakeSphere(1.5,g_marsTextureID);
	g_jumpiter=MakeSphere(3.6,g_jumpiterTextureID);
	g_santurn=MakeSphere(2.9,g_santurnTextureID);
	g_uranus=MakeSphere(2.5,g_uranusTextureID);
	g_neptune=MakeSphere(2.2,g_neptuneTextureID);
}
void renderBitmapString(float x, float y, float z, void *font, const char *string) {
    const char *c;                        // Khai b�o con tr? c ki?u const char d? tr? t?i c�c k� t? trong chu?i.
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3f(x, y, z);              // �?t v? tr� c?a ngu?n v? (raster position) trong kh�ng gian 3D
    for (c = string; *c != '\0'; c++) {   // B?t d?u v�ng l?p duy?t qua t?ng k� t? trong chu?i cho d?n khi g?p k� t? k?t th�c chu?i ('\0')
        glutBitmapCharacter(font, *c);    //: D�ng d? v? m?t k� t? t? chu?i. Tham s? font l� ki?u font (ch?ng h?n nhu GLUT_BITMAP_TIMES_ROMAN_10), v� *c l� k� t? c?n v?.
    } 
}
void drawSun(){

	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
//	glRotatef(0,0.0, 0.0, 0.0);
	GLfloat light_pos [] = {1.0,0.0, 0.0, 0.0};
	GLfloat light_ambien [] = {1.0,1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambien);
 	glCallList(g_sun);
  	glPopAttrib();
	renderBitmapString(9.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun");
    glPopMatrix();
      
	}
	
void drawEarthMoon(){
	
	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
	glRotatef (g_angle_year, 0.0f, 1.0f, 0.0f);
	glTranslated(30.0, 0.0, 0.0);
	glRotatef (g_angle_day, 0.0f, 1.0f, 0.0f);
	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glCallList(g_earth);
	glPopAttrib();
	renderBitmapString(0.0, 3.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Earth");
	glPushAttrib(GL_LIGHTING_BIT);
	glRotatef (gl_angle_moon, 0.0f, 1.0f, 0.0f);
	glTranslated(3.0, 0.0, 0.0);
	GLfloat light_pos2 [] = {g_angle_moon_turn, 0.0, 0.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos2); // S? d?ng g_earthTextureID thay v� g_earthTexture
	glCallList(g_moon);
	glPopAttrib();
	renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");
	glPopMatrix();
	    
}

void drawMercury(){
//	  
	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_mercury, 0.0f, 1.0f, 0.0f);
  	glTranslated(15.0, 0.0, 0.0);

  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  	glEnable(GL_TEXTURE_2D);
 	glCallList(g_mercury);
    glPopAttrib();
	renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mercury");
  	glPopMatrix();
     
}
void drawMars(){
	//mars
 	glPushMatrix();
 	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_mars, 0.0f, 1.0f, 0.0f);
  	glTranslated(37.0, 0.0, 0.0);
  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  	glCallList(g_mars);
 	glPopAttrib();
   	renderBitmapString(3.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
  	glPopMatrix();
      
}
void drawVenus(){
	//venus
 	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_venus, 0.0f, 1.0f, 0.0f);
  	glTranslated(22.0, 0.0, 0.0);
  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glCallList(g_venus);
   	glPopAttrib();
   	renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
  	glPopMatrix();
     
}

void drawJupiter(){

	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
  	glTranslated(47.0, 0.0, 0.0);
  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
 	glCallList(g_jumpiter);
  	glPopAttrib();
   	renderBitmapString(4.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Jupiter");
  	glPopMatrix();
      
}
void drawOrbitsSanturn(){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_CirleTextureID); 
  	glLineWidth(3.0f);
   	for (int i = 0; i < 12; i++) {
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
}
void drawSanturn(){
	
	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
	glRotatef (g_angle_santurn, 0.0f, 1.0f, 0.0f);
	glTranslated(60.0, 0.0, 0.0);
	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
	GLfloat specular[] = {0.2, 0.2, 0.2, 1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	  

	glCallList(g_santurn);
	glPopAttrib();
	glPushAttrib(GL_LINE_BIT);
	glPopAttrib();
		drawOrbitsSanturn();
	renderBitmapString(5.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Saturn");
	glPopMatrix();
	     
}
void drawUranus(){
	 //uranus
	
  	glPushMatrix();
   	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_uranus, 0.0f, 1.0f, 0.0f);
  	glTranslated(70.0, 0.0, 0.0);
  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	GLfloat specular[] = {0.2, 0.2, 0.2, 1.0};
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  
 	glCallList(g_uranus);
    glPopAttrib();
   	renderBitmapString(3.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
  	glPopMatrix();
    
}
void drawNeptune(){
	
  //neptune
 
  	glPushMatrix();
  	glPushAttrib(GL_LIGHTING_BIT);
  	glRotatef (g_angle_neptune, 0.0f, 1.0f, 0.0f);
  	glTranslated(77.0, 0.0, 0.0);
  	GLfloat light_pos [] = {-1.0, 0.0, 0.0, 0.0};
  	GLfloat specular[] = {0.1, 0.1, 0.1, 1.0};
  	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
   	glCallList(g_neptune);
	glPopAttrib();
   	renderBitmapString(3.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Neptune");
  	glPopMatrix();
     
}
void drawBackground() {
	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
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
	glLineWidth(1.5f);
    glColor3f(1.0, 1.0, 1.0); 
    for (int i = 1; i < numPlanets; i++) {
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 360; j++) {
            float theta = static_cast<float>(j) * M_PI / 180.0;
            float x = planetDistances[i] * cosf(theta);
            float z = planetDistances[i] * sinf(theta);
            glVertex3f(x, 0.0, z);
        }
        glEnd();
    }
}
void turning(GLfloat g_angle_quick = 0){
		gl_angle_moon = (gl_angle_moon + 13+g_angle_quick);
	
		if (gl_angle_moon >= 270)
	  {
	  	g_angle_moon_turn=0.0;
	   
	  }else if (gl_angle_moon >= 90){
	  		g_angle_moon_turn=1.0;}
	  		
	if (gl_angle_moon >= 360)
	  {
	    gl_angle_moon = 0;
	   
	  }
	 
	  g_angle_day = (g_angle_day + 360);
	  if (g_angle_day >= 360)
	  {
	    g_angle_day = 0;
	  }
	 
	  g_angle_year = (g_angle_year + 1 +g_angle_quick);
	  if (g_angle_year >= 360)
	  {
	    g_angle_year = 0;
	  }
	   g_angle_mercury = (g_angle_mercury + 4.2+g_angle_quick);
	  if (g_angle_mercury >= 360)
	  {
	    g_angle_mercury = 0;
	  }
	    g_angle_venus = (g_angle_venus +  1.62+g_angle_quick);
	  if (g_angle_venus >= 360)
	  {
	    g_angle_venus = 0;
	  }
	   g_angle_mars = (g_angle_mars +  0.54 +g_angle_quick);
	  if (g_angle_mars >= 360)
	  {
	    g_angle_mars = 0;
	  }
	    g_angle_jumpiter = (g_angle_jumpiter + 0.084+g_angle_quick);
	  if (g_angle_jumpiter >= 360)
	  {
	    g_angle_jumpiter = 0;
	  }
	   g_angle_santurn = (g_angle_santurn +  0.035+g_angle_quick);
	  if (g_angle_santurn >= 360)
	  {
	    g_angle_santurn = 0;
	  }
	   g_angle_uranus = (g_angle_uranus + 0.012+g_angle_quick);
	  if (g_angle_uranus >= 360)
	  {
	    g_angle_uranus = 0;
	  }
	   g_angle_neptune = (g_angle_neptune + 0.0061+g_angle_quick);
	  if (g_angle_neptune >= 360)
	  {
	    g_angle_neptune = 0;
	  }
}

