#include "stdafx.h"
#include "Kruskal.h"


Kruskal::Kruskal():
{
}


Kruskal::Kruskal()
{
}

Kruskal::~Kruskal()
{
}

//void Kruskal::create()
//{
//}
//
//void Kruskal::create(std::size_t size1, std::size_t size2)
//{
//}

std::unique_ptr<Matrix<bool>> Kruskal::create(std::size_t size1, std::size_t size2)
{

	std::unique_ptr<Matrix<bool>>  mazePtr(new Matrix<bool>(size1, size2));

	//mark all edges as connected
	for (std::size_t i = 0; i < mazePtr->getSize1(); ++i)
	{
		for (std::size_t j = 0; j < mazePtr->getSize2(); ++j)
			mazePtr->at(i, j) = true;
	}



	


	return mazePtr;
}
