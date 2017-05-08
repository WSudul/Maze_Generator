#pragma once
#include "MazeBase.h"
#include "Matrix.h"
#include "Kruskal.h"
#include "SquareTile.h"
#include <vector>


/*!
 #TODO rework this, as adj matrix won't work for 'larger' rectangle maze (max 4 edges out of V edges!)
	A derived class representing sample version of Maze.
	Container is a 2d boolean Matrix representing graph (V x V) (adjacency matrix)
	A container might be used by another container representing all the tiles (V)
*/
class Maze :
	public virtual MazeBase
{
public:
	Maze();
	Maze(std::size_t width, std::size_t height);
	virtual ~Maze();

	void generate();
	void clear();
	std::size_t sizeOfMaze();

private:

	Matrix<SquareTile> container; //container storing information about each tile 

	//#TODO implement version with  adj list to reduce the memory usage
	std::unique_ptr<Matrix<bool>> graphRepresentation; //smart pointer to object storing maze

};


Maze::Maze():
MazeBase(),
graphRepresentation(nullptr)
{
}

Maze::Maze(std::size_t width, std::size_t height) :
	MazeBase(),
	graphRepresentation(nullptr),
	container(width,height)
{
}


Maze::~Maze()
{
}


void Maze::generate()
{
	if (graphRepresentation) //checks whether smart pointer points is pointing anywhere (not nullptr)
		clear();

	graphRepresentation.reset(new Matrix<bool>());

	graphRepresentation=Kruskal::create(container.getSize1(), container.getSize2());
	





	//create maze and store it in container
	generated = true;
}


void Maze::clear()
{
	graphRepresentation.reset();
	container.clear();

	generated = false;
}


std::size_t Maze::sizeOfMaze()
{
	//#TODO rework this for generic container that will be derived
	return graphRepresentation->getSize1()*graphRepresentation->getSize2();
}
