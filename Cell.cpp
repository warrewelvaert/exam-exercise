#include "pch.h"
#include "Cell.h"
#include "Texture.h"

const float Cell::size{ 128.f };

Cell::Cell(const Point2f& pos, Cell::Type type)
	:m_Type{type}
	, m_CellRect{pos.x, pos.y, size, size}
	, m_pTrapTexture{new Texture{ "./Resources/Trap" + std::to_string( rand() % 7 + 1) + ".png"}}
	, m_pStartTexture{ new Texture{ "./Resources/Start.png"} }
	, m_pEndTexture{ new Texture{ "./Resources/End.png"} }
	, m_pSaveTexture{ new Texture{ "./Resources/Save.png"} }
	, m_CellWitdth{ float(rand() % int(size)) }
{
	if ( rand() % 2 == 1)
	{
		m_Speed = 10.f;
	}
	else
	{
		m_Speed = -10.f;
	}
}

Cell::Cell()
	:Cell{ Point2f{0.f, 0.f}, Cell::Type::trap }
{
}

Cell::~Cell()
{
	delete m_pTrapTexture;
	delete m_pStartTexture;
	delete m_pEndTexture;
	delete m_pSaveTexture;

	m_pTrapTexture = nullptr;
	m_pStartTexture = nullptr;
	m_pEndTexture = nullptr;
	m_pSaveTexture = nullptr;
}

void Cell::Draw() const
{
	switch (m_Type)
	{
	case Cell::Type::trap:
		m_pTrapTexture->Draw(m_CellRect);
		break;
	case Cell::Type::start:
		m_pStartTexture->Draw(m_CellRect);
		break;
	case Cell::Type::end:
		m_pEndTexture->Draw(m_CellRect);
		break;
	case Cell::Type::save:
		m_pSaveTexture->Draw(m_CellRect);
		break;
	}

	if (m_Type == Cell::Type::trap)
	{
		glColor4f(.8f, .4f, .05f, 0.8f);
		utils::FillRect(Rectf{ m_CellRect.left, m_CellRect.bottom, m_CellWitdth, m_CellRect.height });
	}

	glColor3f(1.f, 1.f, 1.f);
	glLineWidth(2.f);
	utils::DrawRect(m_CellRect);
}

void Cell::Update(float elapsedSec)
{
	if (m_Type == Cell::Type::trap)
	{
		if (m_CellWitdth < 0.f || m_CellWitdth > size)
		{
			m_Speed = -m_Speed;
		}
		m_CellWitdth += m_Speed * elapsedSec;
	}
}

bool Cell::IsTrapped(const Point2f& avatarCenter) const
{
	if (m_CellWitdth < size / 2 && m_Type == Cell::Type::trap && utils::IsPointInRect(m_CellRect, avatarCenter) )
	{
		return true;
	}
	return false;
}

void Cell::SetPosition(const Point2f& pos)
{
	m_CellRect.left = pos.x;
	m_CellRect.bottom = pos.y;
}

void Cell::SetType(const Cell::Type& type) 
{
	m_Type = type;
}

Point2f Cell::GetPosition() const
{
	return Point2f(m_CellRect.left + size / 2, m_CellRect.bottom + size / 2);
}