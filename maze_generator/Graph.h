#pragma once
#include <algorithm>
#include <list>
#include <vector>
#include <map>
/*!
	Class representing graph via adjacency list
	#TODO Implement all needed methods and throw away notion of storing thrice cursed grid in Matrix

	#TODO implement the class by assuming that 1) no new edges/vertices will be added during the use of program,but deletion will be frequent 2) each vertex has unique_ID that has nothing to do with "position" in the grid
	#TODO edge class

	#TODO add node,edge and then methods for removing them safely in directed and undirected graphs
*/
template<typename T,typename Cost>
class Node;

template<typename T>
class Graph
{
public:
	Graph();
	virtual ~Graph();
	// #TODO stick to this idea for now.
	std::vector<std::list<T>> adjList;
	

};

template<typename T>
class Node
{
public:
	Node();
	Node(T obj,std::list<Node*>& adjacent)
	~Node();

	std::list<std::pair<Node*,> adjacent;
	T obj;

};