#pragma once


class Vec2
{
public:
	float x;
	float y;

	Vec2 operator + (const Vec2& other) const;
	Vec2 operator - (const Vec2& other) const;
	Vec2 operator * (const Vec2& other) const;
	Vec2 operator / (const Vec2& other) const;

	void operator += (const Vec2& other);

	Vec2 operator + (float scalar) const;
	Vec2 operator - (float scalar) const;
	Vec2 operator * (float scalar) const;
	Vec2 operator / (float scalar) const;

	float lenght() const;
	static float dotproduct(Vec2 a, Vec2 b);
	static float crossproduct(Vec2 a, Vec2 b);
	static float angle(Vec2 a, Vec2 b);
	Vec2 normalize() const;

	Vec2();
	Vec2(float x, float y);
};
