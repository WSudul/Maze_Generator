// maze_generator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include "Maze.h"
#include "Kruskal.h"

int main()
{
	int col[4] = { 10,20,30,40 };
	int col2[4] = { 4,3,2,1 };
	int row[5] = { 6,6,6,6,6 };
	Matrix<int> m1(4, 5);
	std::cout << "filling\n";
	m1.fillCol(col, 4, 0);
	m1.fillCol(col, 4, 1);
	m1.fillCol(col2, 4, 2);
	m1.fillRow(row, 5, 3);
	std::cout << m1.toString();

	m1.reallocate(4, 4, true);
	std::cout << m1.toString() << std::endl;


	std::cout << "Matrix of tiles" << std::endl;

	Matrix<SquareTile> m2(3, 3);
	SquareTile tilerow[3] = { SquareTile(true,true,false,false),SquareTile(true,true,true,false),SquareTile(false,false,false,false) };

	m2.fillRow(tilerow, 3, 0);
	m2.fillRow(tilerow, 3, 1);

	std::cout << tilerow[0] << std::endl;
	std::cout << m2.toString();

    return 0;
}

