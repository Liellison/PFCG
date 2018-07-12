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

int eixoy, eixox;
int largura, altura;
GLfloat xf, yf, win;

void display(void);

void teclado(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
            eixoy = (eixoy + 5) % 500;
            glutPostRedisplay();
            break;
        case 's':
            eixoy = (eixoy - 5) % 500;
            glutPostRedisplay();
            break;
        case 'd':
            eixox = (eixox + 5) % 500;
            glutPostRedisplay();
            break;
        case 'a':
            eixox = (eixox - 5) % 500;
            glutPostRedisplay();
            break;
        case 'o':
            glLoadIdentity();
            glOrtho (-5, 5, -5, 5, -5 , 5);
            glutPostRedisplay();
            break;
        case 'r':
            glLoadIdentity();
            glOrtho (-5, 5, -5, 5, -5 , 5);
            eixox = 0;
            eixoy = 0;
            glutPostRedisplay();
            break;
    }
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glOrtho (-5, 5, -5, 5, -5, 5);
}


void display(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    //Parede de entrada
    glBegin(GL_QUADS);
        glVertex3i(0, 30, 0);
        glVertex3i(0, 50, 0);
        glVertex3i(384,50, 0);
        glVertex3i(384, 30, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2i(404, 50);
        glVertex2i(404, 30);
        glVertex2i(512,30);
        glVertex2i(512,50);
    glEnd();
    //Parede esquerda
    glBegin(GL_QUADS);
        glVertex2i(0, 512);
        glVertex2i(0, 50);
        glVertex2i(20,50);
        glVertex2i(20,512);
    glEnd();
    //Parede direita
    glBegin(GL_QUADS);
        glVertex2i(492, 512);
        glVertex2i(492, 50);
        glVertex2i(512,50);
        glVertex2i(5122,512);
    glEnd();
    //Parede de cima
    glBegin(GL_QUADS);
        glVertex2i(0, 512);
        glVertex2i(0, 492);
        glVertex2i(512,492);
        glVertex2i(512,512);
    glEnd();
    //Objeto
    glPushMatrix();
    glTranslatef((GLfloat) eixox, 0, 0);
    glTranslatef((GLfloat) 0, eixoy, 0);
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(385, 29);
        //glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(385, 12);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(405, 12);
        glVertex2i(405, 29);
    glEnd();
    glPopMatrix();
    //Ponto Final
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(462, 472);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(472, 490);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(482, 472);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.25,0.25,0.25);
        glVertex3f(-0.75,0.25,0.25);
        glVertex3f(-0.75,0.75,0.25);
        glVertex3f(-0.25,0.75,0.25);
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
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Labirinto Magico de Liellison");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclado);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    
    return 0;
}
