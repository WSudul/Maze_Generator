#pragma once
#include "GeneratorBase.h"
#include "Matrix.h"
#include "SquareTile.h"
#include <memory>


class Kruskal :
	public virtual GeneratorBase
{
public:
	Kruskal();
	~Kruskal();


	void create();
	void create(std::size_t size1, std::size_t size2);

	static std::unique_ptr<Matrix<SquareTile>> create(std::size_t size1, std::size_t size2,std::pair<std::size_t,std::size_t> startPos);
	
};

