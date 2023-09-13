#pragma once
#include <string>
#include "utils.h"

class Texture;
/*

If you have problems using the given Type enumeration, 
then just use an int type that can have 4 possible values.

*/
class Cell
{
public:
	enum class Type
	{
		trap,
		start,
		end,
		save
	};
	Cell(const Point2f& pos,  Cell::Type type);
	Cell();
	~Cell();
	Cell(const Cell& other) = delete;
	Cell& operator=(const Cell& rhs) = delete;
	Cell(Cell&& other) = delete;
	Cell& operator=(Cell&& rhs) = delete;

	void Draw() const;
	void Update( float elapsedSec);
	bool IsTrapped(const Point2f& avatarCenter) const;
	void SetPosition( const Point2f& pos );
	void SetType(const Type& type);
	Point2f GetPosition() const;
	static const float size;

private:
	Cell::Type m_Type;
	Texture* m_pTrapTexture;
	Texture* m_pStartTexture;
	Texture* m_pEndTexture;
	Texture* m_pSaveTexture;
	Rectf m_CellRect;
	bool m_IsTrapped;
	float m_CellWitdth;
	float m_Speed;
	// Complete this private yourself

};
