#pragma once
#include "MazeBase.h"
#include "Matrix.h"
#include "SquareTile.h"

class Maze :
	public virtual MazeBase
{
public:
	Maze();
	virtual ~Maze();

	void generate();
	void clear();
	std::size_t sizeOfMaze();

private:

	std::unique_ptr<Matrix<SquareTile>> container; //smart pointer to object storing maze

};


Maze::Maze():
MazeBase(),
container(nullptr)
{
}


Maze::~Maze()
{
}


void Maze::generate()
{
	if (container) //checks whether smart pointer points is pointing anywhere (not nullptr)
		clear();

	container.reset(new Matrix<SquareTile>());
	//create maze and store it in container
	generated = true;
}


void Maze::clear()
{
	
	container.reset();

	generated = false;
}


std::size_t Maze::sizeOfMaze()
{
	return container->getSize1()*container->getSize2();
}
