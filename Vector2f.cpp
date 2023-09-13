#include "pch.h"
#include "Vector2f.h"
#include <sstream>
#include <iomanip>
#include <cmath>

//-----------------------------------------------------------------
// Vector2f Constructors
//-----------------------------------------------------------------
Vector2f::Vector2f( )
	:Vector2f{ 0.0f, 0.0f }
{
}

Vector2f::Vector2f( float x, float y )
	: x{ x }
	, y{ y }
{
}

Vector2f::Vector2f( const Point2f& fromPoint, const Point2f& toPoint )
	: Vector2f{ toPoint.x - fromPoint.x, toPoint.y - fromPoint.y }
{
}

Vector2f::Vector2f( const Point2f& point )
	: Vector2f{ point.x, point.y }
{
}

Vector2f::Vector2f( const Vector2f& other )
	: Vector2f{ other.x, other.y }
{
}

// -------------------------
// Methods
// -------------------------
bool Vector2f::Equals(const Vector2f& other, float epsilon) const
{
	return ( abs(x - other.x) < epsilon ) && ( abs(y - other.y) < epsilon );
}

Point2f Vector2f::ToPoint2f() const
{
	return Point2f{ x, y };
}

float Vector2f::DotProduct(const Vector2f& other) const
{
	return x * other.x + y * other.y;
}

float Vector2f::CrossProduct(const Vector2f& other) const
{
	return x * other.y - y * other.x;
}

std::string Vector2f::ToString() const
{
	std::stringstream buffer;

	buffer << std::fixed;
	buffer << std::setprecision( 2 );
	buffer << "Vector2f(" <<  x  << ", " <<  y  << ")";
	return buffer.str();
}

float Vector2f::Norm() const
{
	return Length();
}

float Vector2f::Length() const
{
	return sqrt(x * x + y * y);
}

float Vector2f::SquaredLength() const
{
	return x * x + y * y;
}

float Vector2f::AngleWith(const Vector2f& other) const
{
	return std::atan2(CrossProduct(other), DotProduct(other));
}

Vector2f Vector2f::Normalized(float epsilon) const
{
	float length = Length();
	if ( length < epsilon )
	{
		return Vector2f{ 0, 0 };
	}
	else
	{
		return Vector2f{ x / length, y / length };
	}
}

Vector2f Vector2f::Orthogonal() const
{
	return Vector2f{ -y, x };
}

void Vector2f::Set(float newX, float newY)
{
	x = newX;
	y = newY;
}

// -------------------------
// Operators
// -------------------------
Vector2f Vector2f::operator-()  
{
	Vector2f newVector;
	newVector.x = -x;
	newVector.y = -y;
	return newVector;
}
Vector2f Vector2f::operator+()
{
	Vector2f newVector;
	newVector.x = +x;
	newVector.y = +y;
	return newVector;
}
Vector2f& Vector2f::operator*=(const float& rhs)
{
	this->x = (this->x * rhs);
	this->y = (this->y * rhs);
	return *this;
}
Vector2f& Vector2f::operator/=(const float& rhs)
{
	this->x = (this->x / rhs);
	this->y = (this->y / rhs);
	return *this;
}
Vector2f operator*(const float& lhs, const Vector2f& rhs)
{
	Vector2f newVector;
	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;
	return newVector;
}
Vector2f operator*(const Vector2f& lhs, const float& rhs)
{
	Vector2f newVector;
	newVector.x = lhs.x * rhs;
	newVector.y = lhs.y * rhs;
	return newVector;
}
Vector2f operator/(const float& lhs, const Vector2f& rhs)
{
	Vector2f newVector;
	newVector.x = lhs / rhs.x;
	newVector.y = lhs / rhs.y;
	return newVector;
}
Vector2f operator/(const Vector2f& lhs, const float& rhs)
{
	Vector2f newVector;
	newVector.x = lhs.x / rhs;
	newVector.y = lhs.y / rhs;
	return newVector;
}
Vector2f& Vector2f::operator+=(const Vector2f& rhs)
{
	this->x = (this->x + rhs.x);
	this->y = (this->y + rhs.y);
	return *this;
};
Vector2f& Vector2f::operator-=(const Vector2f& rhs)
{
	this->x = (this->x - rhs.x);
	this->y = (this->y - rhs.y);
	return *this;
};
Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs)
{
	Vector2f newVector;
	newVector.x = lhs.x + rhs.x;
	newVector.y = lhs.y + rhs.y;
	return newVector;
}
Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs)
{
	Vector2f newVector;
	newVector.x = lhs.x - rhs.x;
	newVector.y = lhs.y - rhs.y;
	return newVector;
}
bool operator==(const Vector2f& lhs, const Vector2f& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}
std::ostream& operator<<(std::ostream &out, const Vector2f & vector)
{
	/*std::cout << std::fixed;
	std::cout << std::setprecision(2);*/
	out << "Vector2f(" << vector.x << ".00, " << vector.y << ".00)";
	return out;
}