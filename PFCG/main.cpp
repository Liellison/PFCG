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

int eixoy, eixox, eixoxx, eixoyy;
int largura, altura;
GLfloat xf, yf, win;

void display(void);

void teclado(unsigned char key, int x, int y){
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
            eixoy = (eixoy + 2) % 500;
            glutPostRedisplay();
            break;
        case 'W':
            eixoy = (eixoy + 5) % 500;
            glutPostRedisplay();
            break;
        case 's':
            eixoy = (eixoy - 2) % 500;
            glutPostRedisplay();
            break;
        case 'S':
            eixoy = (eixoy - 5) % 500;
            glutPostRedisplay();
            break;
        case 'd':
            eixox = (eixox + 2) % 500;
            glutPostRedisplay();
            break;
        case 'D':
            eixox = (eixox + 5) % 500;
            glutPostRedisplay();
            break;
        case 'a':
            eixox = (eixox - 2) % 500;
            glutPostRedisplay();
            break;
        case 'A':
            eixox = (eixox - 5) % 500;
            glutPostRedisplay();
            break;
        case 'r':
            glLoadIdentity();
            glOrtho (-5, 5, -5, 5, -5 , 5);
            eixox = 0;
            eixoy = 0;
            glutPostRedisplay();
            break;
        case 'R':
            glLoadIdentity();
            glOrtho (-5, 5, -5, 5, -5 , 5);
            eixox = 0;
            eixoy = 0;
            glutPostRedisplay();
            break;
        //Mover a camera
        case 'm':
            eixoxx = (eixoxx + 5) % 200;
            glutPostRedisplay();
        break;
        case 'n':
            eixoyy = (eixoyy + 5) % 200;
            glutPostRedisplay();
        break;
        case 'j':
            eixoxx = (eixoxx - 5) % 200;
            glutPostRedisplay();
        break;
        case 'h':
            eixoyy = (eixoyy - 5) % 200;
            glutPostRedisplay();
           break;
        case 'l':
            glLoadIdentity();
            glOrtho (-5, 5, -5, 5, -5 , 5);
            eixoxx = 0;
            eixoyy = 0;
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
    
    glPushMatrix();
    glRotatef ((GLfloat) eixoxx, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) eixoyy, 0.0, 1.0, 0.0);
    //Parede de entrada
    glBegin(GL_QUADS);
        glVertex3i(0, 30, 0);
        glVertex3i(0, 50, 0);
        glVertex3i(384,50, 0);
        glVertex3i(384, 30, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(404, 30,0);
        glVertex3i(404, 50,0);
        glVertex3i(512,50,0);
        glVertex3i(512,30,0);
    glEnd();
    //Parede esquerda
    glBegin(GL_QUADS);
        glVertex3i(0, 50,0);
        glVertex3i(0, 512,0);
        glVertex3i(20,512,0);
        glVertex3i(20,50,0);
    glEnd();
    //Parede direita
    glBegin(GL_QUADS);
        glVertex3i(492, 50,0);
        glVertex3i(492, 512,0);
        glVertex3i(5122,512,0);
        glVertex3i(512,50,0);
    glEnd();
    //Parede de cima
    glBegin(GL_QUADS);
        glVertex3i(0, 492,0);
        glVertex3i(0, 512,0);
        glVertex3i(512,512,0);
        glVertex3i(512,492,0);
    glEnd();
    //Dentro
    glBegin(GL_QUADS);
        glVertex3i(60, 450,0);
        glVertex3i(60, 470,0);
        glVertex3i(500,470,0);
        glVertex3i(500,450,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(60, 380,0);
        glVertex3i(60, 450,0);
        glVertex3i(80,450,0);
        glVertex3i(80,380,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(430, 150, 0);
        glVertex3i(430, 360, 0);
        glVertex3i(450, 360, 0);
        glVertex3i(450, 150, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(130, 151, 0);
        glVertex3i(130, 171, 0);
        glVertex3i(380, 171, 0);
        glVertex3i(380, 151, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(110, 90, 0);
        glVertex3i(110, 470, 0);
        glVertex3i(130, 470, 0);
        glVertex3i(130, 90, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(30, 70, 0);
        glVertex3i(30, 360, 0);
        glVertex3i(50, 360, 0);
        glVertex3i(50, 70, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3i(70, 70, 0);
        glVertex3i(70, 90, 0);
        glVertex3i(450, 90, 0);
        glVertex3i(450, 70, 0);
    glEnd();
    //Objeto
    glPushMatrix();
    glTranslatef((GLfloat) eixox, 0, 0);
    glTranslatef((GLfloat) 0, eixoy, 0);
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3i(385, 12,0);
        glVertex3i(385, 29,0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3i(405, 29,0);
        glVertex3i(405, 12,0);
    glEnd();
    glPopMatrix();
    //Ponto Final
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(462, 472,0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(472, 490,0);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(482, 472,0);
    glEnd();
    glPopMatrix();
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
