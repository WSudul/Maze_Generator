// maze_generator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Matrix.h"


int main()
{
	int col[4] = { 10,20,30,40 };

	Matrix<int> m1(3, 4);
	std::cout << "filling\n";
	m1.fillCol(col, 4, 0);
	m1.fillCol(col, 4, 1);
	
	m1.reallocate(3, 3, true);
	std::cout << m1.toString();

    return 0;
}

