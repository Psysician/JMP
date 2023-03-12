#include "Engine.h"

#include <cmath>
#define M_PI 3.14159265358979323846

Vec2 Vec2::operator + (const Vec2& other) const
{
	Vec2 res;
	res.x = this->x + other.x;
	res.y = this->y + other.y;
	return res;
}
Vec2 Vec2::operator - (const Vec2& other) const
{
	Vec2 res;
	res.x = this->x - other.x;
	res.y = this->y - other.y;
	return res;
}
Vec2 Vec2::operator * (const Vec2& other) const
{
	Vec2 res;
	res.x = this->x * other.x;
	res.y = this->y * other.y;
	return res;
}
Vec2 Vec2::operator / (const Vec2& other) const
{
	Vec2 res;
	res.x = this->x / other.x;
	res.y = this->y / other.y;
	return res;
}

void Vec2::operator += (const Vec2& other)
{
	this->x += other.x;
	this->y += other.y;
}


Vec2 Vec2::operator + (float scalar) const
{
	Vec2 res;
	res.x = this->x + scalar;
	res.y = this->y + scalar;
	return res;
}
Vec2 Vec2::operator - (float scalar) const
{
	Vec2 res;
	res.x = this->x - scalar;
	res.y = this->y - scalar;
	return res;
}
Vec2 Vec2::operator * (float scalar) const
{
	Vec2 res;
	res.x = this->x * scalar;
	res.y = this->y * scalar;
	return res;
}
Vec2 Vec2::operator / (float scalar) const
{
	Vec2 res;
	res.x = this->x / scalar;
	res.y = this->y / scalar;
	return res;
}

float Vec2::lenght() const
{

	return sqrt(this->x * this->x + this->y * this->y);
}

float Vec2::dotproduct(Vec2 a, Vec2 b)
{
	return a.x * b.x + a.y * b.y;
}

float Vec2::angle(Vec2 a, Vec2 b)
{
	float alpha = dotproduct(a, b) / (a.lenght() * b.lenght());
	alpha = acos(alpha);
	return (alpha * 180.0f / (float)M_PI);
}

//länge muss 1 sein
Vec2 Vec2::normalize() const
{
	float c = lenght();
	Vec2 res;
	res.x = this->x / c;
	res.y = this->y / c;
	return res;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2::Vec2()
{
	this->x = 0;
	this->y = 0;
}