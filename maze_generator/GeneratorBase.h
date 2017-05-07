#pragma once
#include <memory>

class GeneratorBase
{
public:

	GeneratorBase()
	{
	}



	virtual ~GeneratorBase()
	{
	}




protected:

	virtual void create() = 0;
	virtual void create(std::size_t size1, std::size_t size2) = 0;
	

};

