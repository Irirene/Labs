#include "Quad.h"

Quad::Quad()
{
	x = 0;
	y = 0;
	angle = 0;
	size = 20;

	srand(time(0));
	speedX = rand() % 10;
	speedY = rand() % 10;
	rotateSpeed = rand() % 10;
}

Quad::~Quad()
{
}

void Quad::Update()
{
	x += speedX;
	y += speedY;
	angle += rotateSpeed;
	
	if (angle > 360) angle = 0;
	if (x + size > 200 || x - size < -200) speedX *= -1;
	if (y + size > 200 || y - size < -200) speedY *= -1;
}

void Quad::Render()
{
	glTranslatef(x,y,0);
	glRotatef(angle, 0,0,1);
	glBegin(GL_QUADS);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-size, -size, 0);
	glVertex3f(size, -size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(-size, size, 0);
	glEnd();
	glRotatef(-angle, 0, 0, 1);
	glTranslatef(-x, -y, 0);
}

void Quad::MoveUp()
{
	if (y + size < 200) 
		y += 10;
}

void Quad::MoveDown()
{
	if (y - size > -200)
		y -= 10;
}

void Quad::MoveLeft()
{
	if (x - size > -200)
		x -= 10;
}

void Quad::MoveRight()
{
	if (x + size < 200)
		x += 10;
}

void Quad::RotateLeft()
{
	angle += 10;
}

void Quad::RotateRight()
{
	angle -= 10;
}

void Quad::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Quad::setColorRed()
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void Quad::setColorGreen()
{
	glColor3f(0.0f, 1.0f, 0.0f);
}
