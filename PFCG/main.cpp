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

int main(int argc, char** argv)
{
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1, 0, 0);
    
    glBegin(GL_TRIANGLES);
    
    glVertex2f(10, 10);
    glVertex2f(250, 400);
    glVertex2f(400, 10);
    
    glEnd();
    
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0,width,0,height);
    
    glMatrixMode(GL_MODELVIEW);
}
