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
