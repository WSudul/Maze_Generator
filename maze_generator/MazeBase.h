#pragma once

#include <memory>


/*!
	enum class storing information wheter Maze is 2D,3D,... type
*/
enum class MazeType
{
	_2D=2,
	_3D=3
};


/*!
	Abstract Base class for maze generating

*/
template<typename T>
class MazeBase
{
public:

	MazeBase();
	virtual ~MazeBase();
	virtual void generate() = 0;

	/*!
		return total number of walls in maze
	*/
	virtual std::size_t getWallsNo()
	{
		return WallsNo;
	};

	/*!
		return total number of path tiles in maze
	*/
	virtual std::size_t getPathTilesNo() 
	{
		return PathTIlesNo;
	};

	virtual MazeType getMazeType()
	{
		return mazeType;
	};

	bool isGenerated()
	{
		return generated;
	}

protected:



	std::size_t WallsNo; //number of walls in maze
	std::size_t PathTIlesNo; //total number of path tiles in maze

	MazeType mazeType; //type of maze

	bool generated; //whether a maze has been generated

	T container; //container storing generated maze

};

template<typename T>
inline MazeBase<T>::MazeBase():
WallsNo(0),
PathTIlesNo(0),
generated(false),
container<T>()
{

}

template<typename T>
inline MazeBase<T>::~MazeBase()
{
}

