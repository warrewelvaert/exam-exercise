#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	Point2f pos{ (m_Window.width - Cell::size * 5) / 2, (m_Window.height - Cell::size * 5) / 2 };
	for (int i = 0; i < m_ArraySize; i++)
	{
		if (pos.x >= Cell::size * 5)
		{
			pos.x = (m_Window.width - Cell::size * 5) / 2;
			pos.y += Cell::size;
		}
		m_CellsArray[i].SetPosition(pos);
		pos.x += Cell::size;
	}
	m_CellsArray[0].SetType(Cell::Type::start);
	m_CellsArray[12].SetType(Cell::Type::save);
	m_CellsArray[24].SetType(Cell::Type::end);

	m_PlayerPos.x = m_CellsArray[0].GetPosition().x;
	m_PlayerPos.y = m_CellsArray[0].GetPosition().y;
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	for (int i = 0; i < m_ArraySize; i++)
	{
		m_CellsArray[i].Update(elapsedSec);
		if (m_CellsArray[i].IsTrapped(m_PlayerPos))
		{
			m_PlayerPos = Point2f(m_CellsArray[0].GetPosition());
		}
	}
}

void Game::Draw( )
{
	const float playersize{ 40.f };

	ClearBackground( );
	for (int i = 0; i < m_ArraySize; i++)
	{

		m_CellsArray[i].Draw();
	}
	glColor4f(1.f, 0.f, 0.f, 0.6f);
	utils::FillEllipse(m_PlayerPos, playersize, playersize);
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	case SDLK_LEFT:
		if ( m_PlayerPos.x > m_CellsArray[0].GetPosition().x )
		{
			m_PlayerPos.x -= Cell::size;
		}
		break;
	case SDLK_RIGHT:
		if (m_PlayerPos.x < m_CellsArray[4].GetPosition().x)
		{
			m_PlayerPos.x += Cell::size;
		}
		break;
	case SDLK_UP:
		if (m_PlayerPos.y < m_CellsArray[24].GetPosition().y)
		{
			m_PlayerPos.y += Cell::size;
		}
		break;
	case SDLK_DOWN:
		if (m_PlayerPos.y > m_CellsArray[0].GetPosition().y)
		{
			m_PlayerPos.y -= Cell::size;
		}
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
