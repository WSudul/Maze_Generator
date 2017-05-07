#pragma once
#include "GeneratorBase.h"


class Kruskal :
	public virtual GeneratorBase
{
public:
	Kruskal();
	~Kruskal();


	void create();
	void create(std::size_t size1, std::size_t size2);
	
};

