#include "stdafx.h"
#include "Kruskal.h"


Kruskal::Kruskal():
	GeneratorBase()
{
}


Kruskal::~Kruskal()
{
}

void Kruskal::create()
{
}

void Kruskal::create(std::size_t size1, std::size_t size2)
{
}

std::unique_ptr<Matrix<SquareTile>> Kruskal::create(std::size_t size1, std::size_t size2, std::pair<std::size_t, std::size_t> startPos)
{

	std::unique_ptr<Matrix<SquareTile>>  mazePtr( new Matrix<SquareTile>(size1, size2));

	


	return mazePtr;
}
