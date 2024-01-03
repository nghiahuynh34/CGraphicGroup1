#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/gl.h>
#include <math.h>
#define CALLBACK
#define M_PI           3.14159265358979323846
#define STB_IMAGE_IMPLEMENTATION  //làm cho compiler đặt triển khai của các hàm từ thư viện STB Image trực tiếp
#include<windows.h>
#include "stb_image.h"
#include "func.h"
#include <iostream>
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

// Khai báo các biến texture
GLuint g_earthTextureID;
GLuint g_sunTextureID;
GLuint g_moonTextureID;
GLuint g_mercuryTextureID;
GLuint g_venusTextureID;
GLuint g_marsTextureID;
GLuint g_jumpiterTextureID;
GLuint g_santurnTextureID;
GLuint g_uranusTextureID;
GLuint g_neptuneTextureID;
GLuint g_backgroundTextureID;
GLuint g_CirleTextureID;

GLfloat g_angle_quick = 0;

GLfloat posX = 0.0;
GLfloat posY = 90.0;
GLfloat posZ = 0.0;
GLfloat eyeX = 1.0;
GLfloat eyeY = 0.0;
GLfloat eyeZ = 0.0;


const int numPlanets = 9;
float planetDistances[numPlanets] = { 0.0f,10.0f,15.0f,20.0f, 25.0f, 32.0f,42.0f,50.0f,56.0f }; // kc giữa các hành tinh
float circleDistances[numPlanets] = { 3.0f,3.5f,3.7f,3.9f, 4.0f,4.25f, 4.5f,4.75f,5.0f };       // kc giữa các quỹ đạo quanh hành tinh 

void loadPlanetTexture(const char* file, GLuint& ID) {
    //con trỏ chuỗi dẫn tới file hình ảnh , GLuint& ID: lưu id của texture
    int screenWidth = GetSystemMetrics(SM_CXSCREEN); // lấy thông tin độ phân giải 
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    std::cout << "Screen resolution: " << screenWidth << "x" << screenHeight << std::endl;
    int width, height, channels;
    unsigned char* data = stbi_load(file, &width, &height, &channels, STBI_rgb_alpha);  // load hình ảnh lên 
    if (!data) {
        std::cout << "Failed to load texture." << std::endl;
        return;
    }
    glGenTextures(1, &ID);                                  // tạo ra 1 texture
    glBindTexture(GL_TEXTURE_2D, ID);                       // kết nối texture vừa tạo với 1 texture cụ thể 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);  // đặt dữ liệu ảnh vào texture được liên kết 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //GL_TEXTURE_2D: cấu hình texture 2D, tham số texture  --- GL_TEXTURE_WRAP_S: thiết lập thuộc tính "wrap" cho trục S (trục ngang) của texture.
     //GL_REPEAT: texture sẽ được "lặp lại" (repeated) khi tọa độ texture trên trục S vượt quá khoảng [0.0, 1.0]. 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   //GL_TEXTURE_MIN_FILTER: lọc texture nhỏ hơn pixel
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   //GL_TEXTURE_MIN_FILTER: lọc texture lớn hơn pixel

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
    loadPlanetTexture("bg2.jpg", g_backgroundTextureID);
}

GLuint MakeSphere(const float& radius)
{
    GLuint sphereDisplay = glGenLists(1);                    // Tạo một danh sách hiển thị mới và lấy ID của nó
    glNewList(sphereDisplay, GL_COMPILE);                    //Bắt đầu ghi các lệnh vẽ vào danh sách hiển thị với ID là sphereDisplay.

    GLUquadricObj* quadric = gluNewQuadric();                // Tạo một đối tượng quadric (đối tượng hình tròn) để vẽ hình cầu.
    gluQuadricTexture(quadric, GL_TRUE);                     // Cho phép sử dụng tọa độ texture khi vẽ hình cầu.

    gluSphere(quadric, radius, 64, 32);                      //Vẽ hình cầu sử dụng quadric với bán kính là radius, 64 đường kính, và 32 đường vĩ tuyến.

    gluDeleteQuadric(quadric);                                  // giải phongs bộ nhớ 
    glEndList();
    return sphereDisplay;
}
void renderBitmapString(float x, float y, float z, void* font, const char* string) {
    // x, y,z: tọa độ điểm vẽ chữ  ------ *font: font chữ để vẽ ---- string: chuỗi chữ cần viết 
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {     // duyệt qua từng kí tự trong chuỗi 
        glutBitmapCharacter(font, *c);      // vẽ từng kí tự một 
    }
}
void drawSun() {
    glRotatef(9.0f, 0.0f, 0.0f, 0.0f);                          // xoay theo trục x 9 độ 

    glPushMatrix();
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);          // Thiết lập màu phản xạ của chất liệu.
    GLfloat shininess = 100.0;
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);             // Thiết lập độ nhẵn (shininess) của chất liệu.
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);            // Thiết lập màu của nguồn sáng.
    GLfloat constant_attenuation = 1.0;
    GLfloat linear_attenuation = 0.001;
    GLfloat quadratic_attenuation = 0.001;
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constant_attenuation);        // Thiết lập giảm ánh sáng tuyến tính và giảm ánh sáng bậc hai.
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linear_attenuation);            // 
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_sunTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
    glCallList(g_sun);
    glDisable(GL_TEXTURE_2D);


    renderBitmapString(2.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Sun"); //Gọi hàm renderBitmapString để vẽ chuỗi "Sun" tại tọa độ (2.5, 0.0, 0.0) 
    glPopMatrix();
}

void drawMoon() {

    glPushMatrix();
    glRotatef(gl_angle_moon, 0.0f, 1.0f, 0.0f);
    glTranslated(3.0, 0.0, 0.0);                                            // dịch chuyển về quỹ đạo 
    GLfloat mat_ambien3[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien3);               // thiết lập ánh sáng môi trường là màu TRẮNG hoàn toàn 
    GLfloat diff3[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);                     // thiết lập phản xạ khuếch tán là màu TRẮNG 
    glEnable(GL_TEXTURE_2D);                       //Bật sử dụng 
    glBindTexture(GL_TEXTURE_2D, g_moonTextureID); // SỬ dụnng g_earthTextureID thay vì g_earthTexture
    glCallList(g_moon);                             // Gọi danh sách hiển thị 
    glDisable(GL_TEXTURE_2D);               
    renderBitmapString(0.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Moon");       // Vẽ chuỗi "Moon" trên màn hình ở vị trí 0.5, 0, 0 
    glPopMatrix();
}
void drawEarth() {
    glRotatef(g_angle_year, 0.0f, 1.0f, 0.0f);
    glTranslated(20.0, 0.0, 0.0);                                           // dịch chuyển trục x xa gốc tọa độ 20
    glRotatef(g_angle_day, 0.0f, 1.0f, 0.0f);                               


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_earthTextureID);                         // gán texture cho hành tinh
    glCallList(g_earth);
    glDisable(GL_TEXTURE_2D);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Earth");
}

void drawMercury() {

    glPushMatrix();
    glRotatef(g_angle_mercury, 0.0f, 1.0f, 0.0f);
    glTranslated(10.0, 0.0, 0.0);
    GLfloat mat_ambien4[] = { 1.0, 1.0, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien4);
    GLfloat diff4[] = { 1.0, 1.0, 1.0, 1.0 };
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
void drawMars() {
    //mars
    glPushMatrix();
    glRotatef(g_angle_mars, 0.0f, 1.0f, 0.0f);
    glTranslated(25.0, 0.0, 0.0);
    GLfloat mat_ambien6[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien6);
    GLfloat diff6[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff6);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_marsTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
    glCallList(g_mars);
    glDisable(GL_TEXTURE_2D);

    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Mars");
    glPopMatrix();
}
void drawVenus() {
    //venus
    glPushMatrix();
    glRotatef(g_angle_venus, 0.0f, 1.0f, 0.0f);
    glTranslated(15.0, 0.0, 0.0);
    GLfloat mat_ambien5[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien5);
    GLfloat diff5[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff5);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_venusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
    glCallList(g_venus);
    glDisable(GL_TEXTURE_2D);

    renderBitmapString(1.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Venus");
    glPopMatrix();
}
void drawJupiter() {
    glPushMatrix();
    glRotatef(g_angle_jumpiter, 0.0f, 1.0f, 0.0f);
    glTranslated(32.0, 0.0, 0.0);
    GLfloat mat_ambien7[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien7);
    GLfloat diff7[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff7);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_jumpiterTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
    glCallList(g_jumpiter);
    glDisable(GL_TEXTURE_2D);

    renderBitmapString(2.0, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Jupiter");
    glPopMatrix();
}
void drawSanturn() {
    glPushMatrix();
    //glColor3f(1.0, 0.4, 1.3);  // Set orbit color (gray)

    glRotatef(g_angle_santurn, 0.0f, 1.0f, 0.0f);
    glTranslated(42.0, 0.0, 0.0);
    GLfloat mat_ambien8[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien8);
    GLfloat diff8[] = { 1.0, 1.0, 1.0, 1.0 };
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
void drawUranus() {
    //uranus
    glPushMatrix();
    glRotatef(g_angle_uranus, 0.0f, 1.0f, 0.0f);
    glTranslated(50.0, 0.0, 0.0);
    GLfloat mat_ambien9[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien9);
    GLfloat diff9[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff9);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_uranusTextureID); // S? d?ng g_earthTextureID thay vì g_earthTexture
    glCallList(g_uranus);
    glDisable(GL_TEXTURE_2D);
    renderBitmapString(1.5, 0.0, 0.0, GLUT_BITMAP_HELVETICA_12, "Uranus");
    glPopMatrix();
}
void drawNeptune() {

    //neptune
    glPushMatrix();
    glRotatef(g_angle_neptune, 0.0f, 1.0f, 0.0f);
    glTranslated(56.0, 0.0, 0.0);
    GLfloat mat_ambien10[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambien10);
    GLfloat diff10[] = { 1.0, 1.0, 1.0, 1.0 };
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
    // Lưu trạng thái hiện tại của ma trận chiếu phối bởi GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);  // Adjust the values based on your needs


    // Lưu trạng thái hiện tại của ma trận biến đổi mô hình-view
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();


    // Bật sử dụng texture và liên kết texture của background
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_backgroundTextureID);

    // Vẽ một hình chữ nhật với texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
    glEnd();
    // Tắt sử dụng texture
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    // Khôi phục trạng thái hiện tại của ma trận chiếu phối
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    // Chuyển trở lại chế độ ma trận biến đổi mô hình-view
    glMatrixMode(GL_MODELVIEW);
}
void drawOrbits() {
    // Draw orbits for each planet (quỹ đạo)
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 1; i < numPlanets; i++) {          // vòng lặp chạy từ 1 tới 8 bỏ qua mặt trời 
        glBegin(GL_LINE_LOOP);                      // Bắt đầu vẽ một đường loop(chuỗi đoạn thẳng nối các điểm 
        for (int j = 0; j < 360; j++) {             // đi từ 0-359 độ 
            float theta = static_cast<float>(j) * M_PI / 180.0;
            float x = planetDistances[i] * cosf(theta);
            float y = planetDistances[i] * sinf(theta);
            glVertex3f(x, 0.0, y);   // Thêm một điểm vào đường loop với tọa độ (x, 0.0, y)
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
    gl_angle_moon = (gl_angle_moon + 13 + g_angle_quick);  // điều chỉnh tốc độ xoay 
    if (gl_angle_moon >= 360)
    {
        gl_angle_moon = 0; //gl_angle_moon vượt quá 360 độ, nó sẽ được đặt lại về 0 để duy trì giá trị góc xoay trong khoảng [0, 360).
    }
    // g_angle_quick tác dụng tăng tốc độ xoay của các hành tinh 
    g_angle_day = (g_angle_day + 360 + g_angle_quick);
    if (g_angle_day >= 360)
    {
        g_angle_day = 0;
    }

    g_angle_year = (g_angle_year + 1 + g_angle_quick);
    if (g_angle_year >= 360)
    {
        g_angle_year = 0;
    }
    g_angle_mercury = (g_angle_mercury + 5 + g_angle_quick);
    if (g_angle_mercury >= 360)
    {
        g_angle_mercury = 0;
    }
    g_angle_venus = (g_angle_venus + 2 + g_angle_quick);
    if (g_angle_venus >= 360)
    {
        g_angle_venus = 0;
    }
    g_angle_mars = (g_angle_mars + 0.5 + g_angle_quick);
    if (g_angle_mars >= 360)
    {
        g_angle_mars = 0;
    }
    g_angle_jumpiter = (g_angle_jumpiter + 0.07 + g_angle_quick);
    if (g_angle_jumpiter >= 360)
    {
        g_angle_jumpiter = 0;
    }
    g_angle_santurn = (g_angle_santurn + 0.04 + g_angle_quick);
    if (g_angle_santurn >= 360)
    {
        g_angle_santurn = 0;
    }
    g_angle_uranus = (g_angle_uranus + 0.03 + g_angle_quick);
    if (g_angle_uranus >= 360)
    {
        g_angle_uranus = 0;
    }
    g_angle_neptune = (g_angle_neptune + 0.02 + g_angle_quick);
    if (g_angle_neptune >= 360)
    {
        g_angle_neptune = 0;
    }

    glutSwapBuffers();             // hoán đổi vị trí của các khung hình 

    glutPostRedisplay();
}

void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);                            // phản ánh kích thước của cửa sổ 
    glMatrixMode(GL_PROJECTION);                                // Chuyển sang ma trận chiếu phối để cập nhật
    glLoadIdentity();                                           // Đặt ma trận chiếu phối về ma trận đơn vị
    float ratio = (float)width / (float)height;                 // Tính tỉ lệ khung hình mới
    gluPerspective(70.0, ratio, 1, 170.0);                      // Thiết lập ma trận chiếu phối bằng phương pháp "perspective projection"
    glMatrixMode(GL_MODELVIEW);                                 // Chuyển trở lại ma trận biến đổi mô hình-view
}

void keyboard(unsigned char key, int x, int y) {

    //Các phím: n, a, u thay đổi các tham số: posX,Y,Z eyeX,Y,Z          làm thay đổi góc nhìn ở các hành tinh 
    //Các phím: q, s    thay đổi các tham số: g_angle_quick              làm thay đổi tốc độ xoay của các hành tinh
    //Các phím: o       thay đổi các tham số: posX,Y,Z eyeX,Y,Z          thay đổi vị trí đứng hướng y ngày càng xa ra
    switch (key) {
    case 'n':
        posX += 5;
        posY = 40.0;
        posZ += 5;
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
        posY = -100.0;
        posZ = 0.0;
        eyeX = 1.0;
        eyeY = 0.0;
        eyeZ = 0.0;
        glutPostRedisplay();
        break;
    case 'q':
        g_angle_quick += 2;
        glutPostRedisplay();
        break;
    case 's':
        g_angle_quick -= 2;
        glutPostRedisplay();
        break;
    case 'z':
        posX = 0.0;
        posY -= 1;
        posZ = 0.0;
        eyeX = 1.0;
        eyeY = 0.0;
        eyeZ = 0.0;
        glutPostRedisplay();
        break;
    case 'o':
        posX = 0.0;
        posY += 1;
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
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //	glOrtho(-5, 5, -5, 5, -1, 1);
    glEnable(GL_DEPTH_TEST);
    //  glEnable(GL_TEXTURE_2D);
    GLfloat globalAmbient[] = { 0.3, 0.3, 0.3, 0.3 }; // Ði?u ch?nh giá tr? theo nhu c?u

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
    glEnable(GL_LIGHTING);                      // bật ánh sáng chiếu vào 
    glEnable(GL_LIGHT0);                        // bật ánh sáng số 0 
    //  glDisable(GL_LIGHTING);

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
    loadImage();
    g_sun = MakeSphere(6.0);                // tạo ra các hành tinh với đường kính đã cho
    g_earth = MakeSphere(1.75);
    g_moon = MakeSphere(0.7);
    g_mercury = MakeSphere(0.8);
    g_venus = MakeSphere(1.1);
    g_mars = MakeSphere(1.5);
    g_jumpiter = MakeSphere(3.6);
    g_santurn = MakeSphere(2.9);
    g_uranus = MakeSphere(2.5);
    g_neptune = MakeSphere(2.2);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
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