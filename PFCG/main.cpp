//
//  main.cpp
//  PFCG
//
//  Created by Liellison on 07/07/18.
//  Copyright © 2018 Liellison. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

void display(void);
void reshape(int, int);
GLfloat xf, yf, win;

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Labirinto Magico de Liellison");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0, 0, 0, 1);
    glutMainLoop();
    
    return 0;
}

void display(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    //Parede de entrada
    glBegin(GL_QUADS);
        glVertex2i(0, 50);
        glVertex2i(0, 30);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(384,30);
        glVertex2i(384,50);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(404, 50);
        glVertex2i(404, 30);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(512,30);
        glVertex2i(512,50);
    glEnd();
    //Parede esquerda
    glBegin(GL_QUADS);
        glVertex2i(0, 512);
        glVertex2i(0, 50);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(20,50);
        glVertex2i(20,512);
    glEnd();
    //Parede direita
    glBegin(GL_QUADS);
        glVertex2i(492, 512);
        glVertex2i(492, 50);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(512,50);
        glVertex2i(5122,512);
    glEnd();
    //Parede de cima
    glBegin(GL_QUADS);
        glVertex2i(0, 512);
        glVertex2i(0, 492);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(512,492);
        glVertex2i(512,512);
    glEnd();
    glFlush();
}

void reshape(int width, int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0,width,0,height);
    
    glMatrixMode(GL_MODELVIEW);
}
