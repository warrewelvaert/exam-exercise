#include "pch.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h> 
#include <iostream>
#include <string>
#include <ctime>
#include "structs.h"
#include "utils.h"
#include <cmath>

namespace utils
{
	void FillRect(float left, float bottom, float width, float height)
	{
		//glColor3f( 0.f, 0.f, 250.f );
		glBegin(GL_POLYGON);
		glVertex2f(left, bottom);
		glVertex2f(left + width, bottom);
		glVertex2f(left + width, bottom + height);
		glVertex2f(left, bottom + height);
		glEnd();
	}

	void FillEllipse(float centerX, float centerY, float radX, float radY)
	{
		const float dAngle{ float(M_PI) / 100.f };
		glBegin(GL_POLYGON);
		for (float angle{}; angle < 2 * float(M_PI); angle += dAngle)
		{
			glVertex2f(centerX + radX * cos(angle),
				centerY + radY * sin(angle));
		}
		glEnd();
	}

	void FillEllipse(const Point2f center, float radX, float radY)
	{
		FillEllipse(center.x, center.y, radX, radY);
	}

	void DrawDotGrid(Point2f center, float radX, float radY, float gap, int row, int column)
	{

		while (row >= 0)
		{
			FillEllipse(center.x + gap, center.y + gap, radX, radY);
			center.x = center.x + radX;
			--row;

		}
		while (column >= 0)
		{

		}
	}

	void DrawRect(float left, float bottom, float width, float height)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2f(left, bottom);
		glVertex2f(left + width, bottom);
		glVertex2f(left + width, bottom + height);
		glVertex2f(left, bottom + height);
		glEnd();
	}

	void DrawRect(Rectf rect)
	{
		DrawRect(rect.left, rect.bottom, rect.width, rect.height);
	}

	void DrawRect(Point2f point1, Point2f point2)
	{
		DrawRect(point1.x, point1.y, point2.x, point2.y);
	}

	void DrawSquares(float left, float bottom, float width, float height, float count)
	{
		float squareGap{ 0 };
		while (count > 0)
		{
			glLineWidth(2.0f);
			glBegin(GL_LINE_LOOP);
			glVertex2f(left + squareGap, bottom + squareGap);
			glVertex2f(left + width - squareGap, bottom + squareGap);
			glVertex2f(left + width - squareGap, bottom + height - squareGap);
			glVertex2f(left + squareGap, bottom + height - squareGap);
			glEnd();
			squareGap = squareGap + width / (count * 2.0f);
			--count;
		}

	}

	void DrawQuadrangle(float left, float bottom, float width, float height)
	{
		glLineWidth(2.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(left, bottom);
		glVertex2f(left + width, bottom);
		glVertex2f(left + width, bottom + height);
		glVertex2f(left, bottom + height);
		glEnd();

		glLineWidth(2.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(left, bottom + height / 2.0f);
		glVertex2f(left + width / 2.0f, bottom + height);
		glVertex2f(left + width, bottom + height / 2.0f);
		glVertex2f(left + width / 2.0f, bottom);
		glEnd();

	}

	void DrawEquilateralTriangle(float left, float size, int fill)
	{
		float bottom{ left * 0.6f };

		if (fill == 1)
		{
			glBegin(GL_TRIANGLES);
			glVertex2f(left, bottom);
			glVertex2f(left + size / 2.0f, bottom + sqrt(pow(size, 2.0f) - pow(size / 2.0f, 2.0f)));
			glVertex2f(left + size, bottom);
			glEnd();
		}
		else {
			glLineWidth(2.0f);
			glBegin(GL_LINE_LOOP);
			glVertex2f(left, bottom);
			glVertex2f(left + size / 2.0f, bottom + sqrt(pow(size, 2.0f) - pow(size / 2.0f, 2.0f)));
			glVertex2f(left + size, bottom);
			glEnd();
		}
	}

	void DrawPentagon(float radius, float centerX, float centerY)
	{

		glLineWidth(4.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(centerX + radius, centerY);
		glVertex2f(centerX - cos(0.628319f) * radius, centerY + sin(0.628319f) * radius);
		glVertex2f(centerX + sin(0.314159f) * radius, centerY - cos(0.314159f) * radius);
		glVertex2f(centerX + sin(0.314159f) * radius, centerY + cos(0.314159f) * radius);
		glVertex2f(centerX - cos(0.628319f) * radius, centerY - sin(0.628319f) * radius);
		glEnd();
	}

	void DrawLinearGradient(Rectf pos, Color4f lColor, Color4f rColor)
	{
		glBegin(GL_POLYGON);
		glColor4f(lColor.r, lColor.g, lColor.b, lColor.a);
		glVertex2f(pos.left, pos.bottom);
		glVertex2f(pos.left, pos.bottom + pos.height);
		glColor4f(rColor.r, rColor.g, rColor.b, rColor.a);
		glVertex2f(pos.left + pos.width, pos.bottom + pos.height);
		glVertex2f(pos.left + pos.width, pos.bottom);
		glEnd();
	}

	void IsPointInCircle(Circlef circle, Point2f point)
	{
		const float dAngle{ float(M_PI) / 100.f };
		glColor3f(1.f, 1.f, 1.f);
		glBegin(GL_POLYGON);
		for (float angle{}; angle < 2 * float(M_PI); angle += dAngle)
		{
			glVertex2f(circle.center.x + circle.radius * cos(angle),
				circle.center.y + circle.radius * sin(angle));
		}
		glEnd();
		if (point.x < (circle.center.x + circle.radius) && point.x >(circle.center.x - circle.radius) && point.y < (circle.center.y + circle.radius) && point.y >(circle.center.y - circle.radius))
		{
			glLineWidth(5.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glBegin(GL_LINE_LOOP);
			for (float angle{}; angle < 2 * float(M_PI); angle += dAngle)
			{
				glVertex2f(circle.center.x + circle.radius * cos(angle),
					circle.center.y + circle.radius * sin(angle));
			}
			glEnd();
		}
	}

	bool IsPointInEllipse(Point2f center, float radX, float radY, Point2f point)
	{
		float result = float(pow((point.x - center.x), 2) / pow(radX, 2))
			+ (pow((point.y - center.y), 2) / pow(radY, 2));
		if (result < 1.f)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void FillRect(Rectf rect)
	{
		FillRect(rect.left, rect.bottom, rect.width, rect.height);
	}

	bool IsPointInRect(Rectf rect, Point2f point)
	{
		if (point.x < rect.left + rect.width && point.x > rect.left && point.y > rect.bottom && point.y < rect.bottom + rect.height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void IsOverlapping(Rectf rect, Rectf mouse)
	{
		DrawRect(mouse);
		if ((mouse.left > rect.left && mouse.left < rect.left + rect.width && mouse.bottom > rect.bottom && mouse.bottom < rect.bottom + rect.height) ||
			(mouse.left + mouse.width > rect.left && mouse.left + mouse.width < rect.left + rect.width && mouse.bottom > rect.bottom && mouse.bottom < rect.bottom + rect.height))
		{
			glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
			FillRect(mouse);
		}
		else
		{
			glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
			FillRect(mouse);
		}
	}

	void DrawVector(Vector2f vector, Point2f point)
	{
		float angle{ atan2(vector.y, vector.x) };

		glLineWidth(3.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(point.x, point.y);
		glVertex2f(point.x + vector.x, point.y + vector.y);
		glEnd();

		/*glLineSize(3.0f);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(point.x + vector.x, point.y + vector.y);
		glVertex2f((point.x + vector.x) - 10.0f, (point.y + vector.y) + 3.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(point.x + vector.x, point.y + vector.y);
		glVertex2f((point.x + vector.x) - 10.0f, (point.y + vector.y) - 3.0f);
		glEnd();*/

		glPointSize(6.0f);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(point.x, point.y);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(point.x + vector.x, point.y + vector.y);
		glEnd();
	}

	std::string ToString(Vector2f vector, Point2f point)
	{
		std::string result = "[" + std::to_string(point.x + vector.x) + "," + std::to_string(point.y + vector.y) + "]";
		return result;
	}

	Vector2f Add(Vector2f vector1, Vector2f vector2)
	{
		Vector2f result;
		result.x = vector1.x + vector2.x;
		result.y = vector1.y + vector2.y;
		return result;
	}

	Vector2f Subtract(Vector2f vector1, Vector2f vector2)
	{
		Vector2f result;
		result.x = vector1.x - vector2.x;
		result.y = vector1.y - vector2.y;
		return result;
	}

	float DotProduct(Vector2f vector1, Vector2f vector2)
	{
		float result{ vector1.x * vector2.x + vector1.y * vector2.y };
		return result;
	}

	float CrossProduct(Vector2f vector1, Vector2f vector2)
	{
		float result{ vector1.x * vector2.y - vector1.y * vector2.x };
		return result;
	}

	float Lenght(Vector2f vector)
	{
		float result{ float(sqrt(pow(vector.x, 2) + pow(vector.y, 2))) };
		return result;
	}

	Vector2f Scale(Vector2f vector, float scalar)
	{
		Vector2f result;
		result.x = vector.x * scalar;
		result.y = vector.y * scalar;
		return result;
	}

	Vector2f Normalize(Vector2f vector)
	{
		Vector2f result;
		float lenght = float(sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
		result.x = vector.x / lenght;
		result.y = vector.y / lenght;
		return result;
	}

	float AngleBetween(Vector2f vector1, Vector2f vector2)
	{
		float angle;
		float cross = vector1.x * vector2.y - vector1.y * vector2.x;
		float dot = vector1.x * vector2.x + vector1.y * vector2.y;
		angle = atan2(cross, dot);
		return angle;
	}

	bool AreEqual(Vector2f vector1, Vector2f vector2)
	{
		bool result;
		int vector1X{ int(vector1.x) * 1000 };
		int vector1Y{ int(vector1.y) * 1000 };
		int vector2X{ int(vector2.x) * 1000 };
		int vector2Y{ int(vector2.y) * 1000 };

		if (vector1X == vector2X && vector1Y == vector2Y)
		{
			result = true;
		}
		else
		{
			result = false;
		}
		return result;
	}
}
