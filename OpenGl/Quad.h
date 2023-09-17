#pragma once
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>



class Quad
{
public:
	Quad();
	~Quad();
	void Update();
	void Render();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void RotateLeft();
	void RotateRight();

	void setPos(int _x, int _y);
	void setColorRed();
	void setColorGreen();

private:
	float x;
	float y;
	float angle;
	int size;

	float speedX;
	float speedY;
	float rotateSpeed;
};

