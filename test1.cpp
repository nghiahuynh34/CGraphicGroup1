#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/gl.h>
#include <math.h>
#define CALLBACK
# define M_PI           3.14159265358979323846
#include<windows.h>
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

GLfloat posX = 0.0;
GLfloat posY = 70.0;
GLfloat posZ = 0.0;
GLfloat eyeX = 1.0;
GLfloat eyeY = 0.0;
GLfloat eyeZ = 0.0;

const int numPlanets = 9;
//float planetRadii[numPlanets] = {0.2f, 0.1f, 0.15f,0.2f, 0.1f, 0.15f};
float planetDistances[numPlanets] = { 0.0f,6.0,8.0, 10.0f, 12.0f,16.0f,20.0f,23.0f,25.0f };
//float planetSpeeds[numPlanets] = {1.0f, 0.5f, 0.3f,1.0f, 0.5f, 0.3f};
GLuint g_santurn_ring;

GLuint MakeSphere(const float& radius)
{
    GLuint boxDisplay;
    boxDisplay = glGenLists(1);
    glNewList(boxDisplay, GL_COMPILE);
    glutSolidSphere(radius, 64, 16);
    glEndList();
    return boxDisplay;
}
void renderBitmapString(float x, float y, float z, void* font, const char* string) {
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void RendenScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();
    // for (int i = 0; i < 100; i++) {
    //        float theta = 2.0f * M_PI * float(i) / float(100);
    //        float x = 0.5f * cosf(theta);
    //        float y = 0.5f * sinf(theta);
    //        glVertex2f(x, y);
    //    }
    //	glEnd();
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
    GLfloat mat_ambien[] = { 1.0, 1.0, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien);
    GLfloat diff[] = { 05, 0.5, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glCallList(g_sun);
    renderBitmapString(2.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun");
    //mercury
    glPushMatrix();
    glRotatef(g_angle_mercury, 0.0f, 1.0f, 0.0f);
    glTranslated(6.0, 0.0, 0.0);
    GLfloat mat_ambien4[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien4);
    GLfloat diff4[] = { 1.0, 1.0, 0.2, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff4);
    glCallList(g_mercury);
    //   glRasterPos3f(1.5, 0.0, 0.0);
    //    glBitmap(16, 16, 0.0, 0.0, 15.0, 0.0, E);
    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mercury");
    glPopMatrix();
    //venus
    glPushMatrix();
    glRotatef(g_angle_venus, 0.0f, 1.0f, 0.0f);
    glTranslated(8.0, 0.0, 0.0);
    GLfloat mat_ambien5[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien5);
    GLfloat diff5[] = { 1.0, 1.0, 0.5, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff5);
    glCallList(g_venus);
    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
    glPopMatrix();
    //mars
    glPushMatrix();
    glRotatef(g_angle_mars, 0.0f, 1.0f, 0.0f);
    glTranslated(12.0, 0.0, 0.0);
    GLfloat mat_ambien6[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien6);
    GLfloat diff6[] = { 0.4, 0.5, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff6);
    glCallList(g_mars);
    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
    glPopMatrix();
    // jumpiter
    glPushMatrix();
    glRotatef(g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
    glTranslated(16.0, 0.0, 0.0);
    GLfloat mat_ambien7[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien7);
    GLfloat diff7[] = { 0.5, 1.0, 0.3, 1.0 };
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
    glRotatef(g_angle_santurn, 0.0f, 1.0f, 0.0f);
    glTranslated(20.0, 0.0, 0.0);
    GLfloat mat_ambien8[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien8);
    GLfloat diff8[] = { 1.0, 0.4, 1.0, 0.5 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff8);
    glCallList(g_santurn);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Saturn");
    glPopMatrix();

    //uranus
    glPushMatrix();
    glRotatef(g_angle_uranus, 0.0f, 1.0f, 0.0f);
    glTranslated(23.0, 0.0, 0.0);
    GLfloat mat_ambien9[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien9);
    GLfloat diff9[] = { 1.0, 1.0, 0.4, 0.6 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff9);
    glCallList(g_uranus);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
    glPopMatrix();
    //neptune
    glPushMatrix();
    glRotatef(g_angle_neptune, 0.0f, 1.0f, 0.0f);
    glTranslated(25.0, 0.0, 0.0);
    GLfloat mat_ambien10[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien10);
    GLfloat diff10[] = { 0.2, 1.0, 1.0, 0.4 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff10);
    glCallList(g_neptune);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Neptune");
    glPopMatrix();
    //earth
    glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
    glTranslated(10.0, 0.0, 0.0);
    glRotatef(g_angle_day, 0.0f, 1.0f, 0.0f);

    GLfloat mat_ambien2[] = { 0.0, 0.0, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien2);
    GLfloat diff2[] = { 1.5, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
    glCallList(g_earth);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Earth");
    glPushMatrix();
    glRotatef(gl_angle_moon, 0.0f, 1.0f, 0.0f);
    glTranslated(2.0, 0.0, 0.0);

    GLfloat mat_ambien3[] = { 0.7, 0.7, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);
    GLfloat diff3[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);

    glCallList(g_moon);
    renderBitmapString(0.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");
    glPopMatrix();









    Sleep(83);
    gl_angle_moon = (gl_angle_moon + 13);
    if (gl_angle_moon >= 360)
    {
        gl_angle_moon = 0;
    }

    g_angle_day = (g_angle_day + 360);
    if (g_angle_day >= 360)
    {
        g_angle_day = 0;
    }

    g_angle_year = (g_angle_year + 1);
    if (g_angle_year >= 360)
    {
        g_angle_year = 0;
    }
    g_angle_mercury = (g_angle_mercury + 5);
    if (g_angle_mercury >= 360)
    {
        g_angle_mercury = 0;
    }
    g_angle_venus = (g_angle_venus + 2);
    if (g_angle_venus >= 360)
    {
        g_angle_venus = 0;
    }
    g_angle_mars = (g_angle_mars + 0.5);
    if (g_angle_mars >= 360)
    {
        g_angle_mars = 0;
    }
    g_angle_jumpiter = (g_angle_jumpiter + 0.07);
    if (g_angle_jumpiter >= 360)
    {
        g_angle_jumpiter = 0;
    }
    g_angle_santurn = (g_angle_santurn + 0.04);
    if (g_angle_santurn >= 360)
    {
        g_angle_santurn = 0;
    }
    g_angle_uranus = (g_angle_uranus + 0.03);
    if (g_angle_uranus >= 360)
    {
        g_angle_uranus = 0;
    }
    g_angle_neptune = (g_angle_neptune + 0.02);
    if (g_angle_neptune >= 360)
    {
        g_angle_neptune = 0;
    }
    glutSwapBuffers();
    glFlush();

    glutPostRedisplay();
}

void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0, ratio, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'n':
        posX = 35.0;
        posY = 50.0;
        posZ = 35.0;
        eyeX = 0.0;
        eyeY = 1.0;
        eyeZ = 0.0;
        glutPostRedisplay();
        break;
    case 'a':
        posX = 0.0;
        posY = 70.0;
        posZ = 0.0;
        eyeX = 1.0;
        eyeY = 0.0;
        eyeZ = 0.0;
        glutPostRedisplay();
        break;
    case 'u':
        posX = 0.0;
        posY = -70.0;
        posZ = 0.0;
        eyeX = 1.0;
        eyeY = 0.0;
        eyeZ = 0.0;
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

    GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

    GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

    GLfloat shininess = 50.0f;
    glMateriali(GL_FRONT, GL_SHININESS, shininess);

    g_sun = MakeSphere(2.0);
    g_earth = MakeSphere(1.0);
    g_moon = MakeSphere(0.3);
    g_mercury = MakeSphere(0.5);
    g_venus = MakeSphere(0.8);
    g_mars = MakeSphere(0.65);
    g_jumpiter = MakeSphere(1.5);
    g_santurn = MakeSphere(1.2);
    g_uranus = MakeSphere(1.0);
    g_neptune = MakeSphere(0.75);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
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