#pragma once
#include "MazeBase.h"

template<typename T>
class Maze :
	public virtual MazeBase<T>
{
public:
	Maze();
	virtual ~Maze();

	void generate();
	void clear();
	std::size_t sizeOfMaze();

};

template<typename T>
inline Maze<T>::Maze():
MazeBase()
{
}

template<typename T>
inline Maze<T>::~Maze()
{
}

template<typename T>
inline void Maze<T>::generate()
{

	//create maze and store it in container
	generated = true;
}

template<typename T>
inline void Maze<T>::clear()
{
}

template<typename T>
inline std::size_t Maze<T>::sizeOfMaze()
{
	return std::size_t();
}
