#pragma once
#include <memory>

/*!
	abstract class used as common object for generating mazes
	Create should retrun smart pointer to created object 

*/
class GeneratorBase
{
public:

	GeneratorBase();



	virtual ~GeneratorBase();




protected:

	//virtual void create() = 0;
	//virtual void create(std::size_t size1, std::size_t size2) = 0;
	

};

