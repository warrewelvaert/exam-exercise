#include "pch.h"
#include "Container.h"
#include <cassert>

Container::Container( int capacity ) 
	: m_Size{ 0 }
	, m_Capacity{ capacity }
	, m_pElement{ new int[capacity] }
{
}

Container::~Container( ) 
{ 
	delete[] m_pElement; 
}

int Container::Size( ) const
{ 
	return m_Size; 
}

int Container::Capacity( ) const
{
	return m_Capacity;
}

int Container::Get( int index ) const
{
	assert( index >= 0 && index < m_Size );
	return m_pElement[index];
}

void Container::Set( int index, int value )
{
	assert( index >= 0 && index < m_Size );
	m_pElement[index] = value;
}

void Container::PushBack( int value )
{
	if ( !( m_Size < m_Capacity ) )
	{
		Reserve( m_Capacity * 2  + 1);
	}
	m_pElement[m_Size] = value;
	++m_Size;
}

void Container::Reserve( int newCapacity )
{
	if ( newCapacity <= m_Capacity )
	{
		return;
	}

	// Dynamically allocate memory
	int * pNew = new int[newCapacity] {};
	// Copy the elements into this new memory
	for ( int i{ 0 }; i < m_Size; ++i )
	{
		pNew[i] = m_pElement[i];
	}
	// Free the old memory
	delete[] m_pElement;

	// Adapt the data members to this new situation
	m_pElement = pNew;
	m_Capacity = newCapacity;
}

int& Container::operator[] (const int index)
{
	return m_pElement[index];
}

const int& Container::operator[] (const int index) const
{
	return m_pElement[index];
}

Container::Container(const Container& other)
	: m_Size{ other.m_Size }
	, m_Capacity{ other.m_Capacity }
	, m_pElement{ new int[other.m_Capacity] }
{
	for (int i = 0; i < m_Size; ++i)
	{
		m_pElement[i] = other.m_pElement[i];
	}
}

Container & Container::operator=(const Container& rhs)
{
	if (&rhs != this)
	{
		m_Size = rhs.m_Size;
		m_Capacity = rhs.m_Capacity;
		delete[] m_pElement;
		m_pElement = new int[rhs.m_Size];
		for (int i = 0; i < m_Size; ++i)
		{
			m_pElement[i] = rhs.m_pElement[i];
		}
	}
	return *this;
}

