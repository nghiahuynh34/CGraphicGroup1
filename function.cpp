//#include "function.h"
//#include <math.h>
#include <GL/glut.h>
//#include <iostream>
//void drawHouse(){
//	glBegin(GL_QUADS);
//	    glColor3f(0.5f, 0.5f, 0.9f); // Màu c?a ngôi nhà (màu xanh nh?t)
//	    glVertex2f(-1.5f, -0.9f);
//	    glVertex2f(1.5f, -0.9f);
//	    glVertex2f(1.5f, 0.9f);
//	    glVertex2f(-1.5f, 0.9f);
//    glEnd();
//    glColor3f(0.5f, 0.5f, 0.5f); // Màu c?a ngôi nhà (màu xanh nh?t)
//
//	glBegin(GL_QUADS);
//	    glVertex2f(-0.3f, -0.9f);
//	    glVertex2f(0.3f, -0.9);
//	    glVertex2f(0.3f, 0.2f);
//	    glVertex2f(-0.3f, 0.2f);
//    glEnd();
//    // V? mái nhà (tam giác)
//    glBegin(GL_TRIANGLES);
//	    glColor3f(0.9f, 0.2f, 0.2f); // Màu c?a mái nhà (màu d?)
//	    glVertex2f(-1.4f, 0.9f);
//	    glVertex2f(1.4f, 0.9f);
//	    glVertex2f(0.0f, 1.7f);
//    glEnd();
//}
//void drawPentagon(){
//		//ve hinh ngu giac
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glViewport(0, 0, 600, 600);
//	//v? các d?i tu?ng
//	glBegin(GL_LINE_LOOP);
//	//glVertex2f(0.0f, 2.0f);
//	//glVertex2f(-2.0f, 1.0f);
//	//glVertex2f(-1.0f, -1.0f);
//	//glVertex2f(1.0f, -1.0f);
//	//glVertex2f(2.0f, 1.0f);
//	GLfloat step1 = 2*3.14 / 5.0;
//	register int i1;
//	GLfloat angle1;
//	for (i1 = 0; i1<5; i1++)
//	{
//		angle1 = i1*step1+18;
//		glVertex3f(cos(angle1), sin(angle1), 0.0);
//	}
//	glEnd();
//	
//}
//void drawHexagon(){
//	//ve hinh luc giac
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glViewport(0, 0, 600, 600);
//	//v? các d?i tu?ng
//	glBegin(GL_POLYGON);
//	//glVertex2f(1.0f, 2.0f);
//	//glVertex2f(-1.0f, 2.0f);
//	//glVertex2f(-2.0f, 0.5f);
//	//glVertex2f(-1.0f, -1.0f);
//	//glVertex2f(1.0f, -1.0f);
//	//glVertex2f(2.0f, 0.5f);
//	GLfloat step = 2*3.14 / 6.0;
//	register int i;
//	GLfloat angle;
//	for (i = 0; i<6; i++)
//	{
//		angle = i*step;
//		glVertex3f(cos(angle), sin(angle), 0.0);
//	}
//	glEnd();
//	
//}
//void drawStarTenEdges(){
//	//ve hinh ngoi sao 10 canh
//	glColor3f(0.0f, 0.0f, 1.0f);
////	glViewport(-200, -50, 600, 600);
//	//v? các d?i tu?ng
//	glBegin(GL_LINE_LOOP);
//	GLfloat step2 = 2*3.14 / 10.0;
//	register int k;
//	GLfloat angle2, r;
//	for (k = 0; k<10; k++)
//	{
//		if(k%2==0)
//			r=2;
//		else
//			r=5;
//		angle2 = k*step2;
//		glVertex3f(r*cos(angle2), r*sin(angle2), 0.0);
//	}
//	glEnd();
//	
//}
//void drawStarSixtyEdges(){
//
//	//ve hinh ngoi sao 60 canh
//	glColor3f(0.0f, 0.0f, 1.0f);
////	glViewport(0, 200, 600, 600);
//	//v? các d?i tu?ng
//	glBegin(GL_LINE_LOOP);
//	GLfloat step3 = 2*3.14 / 60.0;
//	register int l;
//	GLfloat angle3, r1;
//	for (l = 0; l<60; l++)
//	{
//		if(l%2==0)
//			r1=2;
//		else
//			r1=5;
//		angle3 = l*step3;
//		glVertex3f(r1*cos(angle3), r1*sin(angle3), 0.0);
//	}
//	glEnd();
//
//}
//void drawTeapot() {
//	
//	gluLookAt(5.0,0.0,0.0,0.0,0.0,0.0,0.0,5.0,0.0);
////	glRotatef(30,1,1,1);
//	glutWireTeapot(1.0);
//}

