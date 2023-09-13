#pragma once

class Container
{
public:
	Container( int capacity  = 10); 
	~Container( );
	int Size( ) const;
	int Capacity( ) const;
	int Get( int index ) const;
	void Set( int index, int value );
	void PushBack( int element );
	int& operator[] (const int index);
	const int& operator[] (const int index) const;
	Container(const Container& other);
	Container& operator=(const Container& rhs);

private:
	int m_Size;
	int m_Capacity;
	int *m_pElement;

	void Reserve( int newCapacity );
};
