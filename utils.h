#pragma once
#include "structs.h"
#include "string"
#include "Vector2f.h"

namespace utils
{
	void FillRect(float left, float bottom, float width, float height);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Point2f center, float radX, float radY);
	void DrawDotGrid(Point2f center, float radX, float radY, float gap, int row, int column);
	void DrawRect(float left, float bottom, float width, float height);
	void DrawRect(Point2f point1, Point2f point2);
	void DrawRect(Rectf rect);
	void DrawSquares(float left, float bottom, float width, float height, float count);
	void DrawQuadrangle(float left, float bottom, float width, float height);
	void DrawEquilateralTriangle(float left, float size, int fill);
	void DrawPentagon(float radius, float centerX, float centerY);
	void DrawLinearGradient(Rectf pos, Color4f lColor, Color4f rColor);
	void IsPointInCircle(Circlef circle, Point2f point);
	void FillRect(Rectf rect);
	bool IsPointInRect(Rectf rect, Point2f point);
	void IsOverlapping(Rectf rect, Rectf mouse);
	void DrawVector(Vector2f vector, Point2f point);
	std::string ToString(Vector2f vector, Point2f point);
	Vector2f Add(Vector2f vector1, Vector2f vector2);
	Vector2f Subtract(Vector2f vector1, Vector2f vector2);
	float DotProduct(Vector2f vector1, Vector2f vector2);
	float CrossProduct(Vector2f vector1, Vector2f vector2);
	float Lenght(Vector2f vector);
	Vector2f Scale(Vector2f vector, float scalar);
	Vector2f Normalize(Vector2f vector);
	float AngleBetween(Vector2f vector1, Vector2f vector2);
	bool AreEqual(Vector2f vector1, Vector2f vector2);
	bool IsPointInEllipse(Point2f center, float radX, float radY, Point2f point);
};



	
