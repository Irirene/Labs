#include <iostream>
#include <GL/glut.h>
#include "Quad.h"

Quad* quad;

void Init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 600, 600, 0, -5, 5);
	quad = new Quad();
}

void Update(int)
{
	glutPostRedisplay();
	//quad->Update();
	glutTimerFunc(30, Update, 0);
}

void Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	quad->Render();
	//glFlush();
	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a': quad->RotateLeft(); break;
	case 'd': quad->RotateRight(); break;
	}
}

void SpecialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: quad->MoveLeft(); break;
	case GLUT_KEY_RIGHT: quad->MoveRight(); break;
	case GLUT_KEY_UP: quad->MoveUp(); break;
	case GLUT_KEY_DOWN: quad->MoveDown(); break;
	}
}

void mouseMove(int ax, int ay)
{
	quad->setPos(ax, ay);
}

void mousePressed(int button, int state, int x, int y)
{
	quad->setPos(x, y);
	switch (button)
	{
	case GLUT_LEFT_BUTTON: quad->setColorRed(); break;
	case GLUT_RIGHT_BUTTON: quad->setColorGreen(); break;
	default:
		break;
	}
}

void mousePressedMove(int ax, int ay)
{
	quad->setPos(ax, ay);
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(Render);
	glutTimerFunc(100, Update, 0);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutMotionFunc(mousePressedMove);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mousePressed);
	Init();
	glutMainLoop();
	delete quad;
}
