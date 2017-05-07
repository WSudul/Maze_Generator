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
	Abstract Base class for maze generating.
	Does NOT care what kind of container is used.
	at the very least generate(), clear() needs to be implemented 

*/
class MazeBase
{
public:

	MazeBase();
	virtual ~MazeBase();
	virtual void generate();

	/*!
		clear the object by resetting all data and deleting object pointed by container
	*/
	virtual void clear();
	
	/*!
		return size of maze as number of all created tiles
	*/
	virtual std::size_t sizeOfMaze();


	/*!
		return total number of walls in maze
	*/
	virtual std::size_t getWallsNo();

	/*!
		return total number of path tiles in maze
	*/
	virtual std::size_t getPathTilesNo();

	/*!
		return type of maze as MazeType enum
	*/
	virtual MazeType getMazeType();

	/*!
		returns true if generate() was run and clear() was no called afterwards
	*/
	bool isGenerated();

protected:

	virtual void clearBase();

	std::size_t WallsNo; //number of walls in maze
	std::size_t PathTIlesNo; //total number of path tiles in maze

	MazeType mazeType; //type of maze

	bool generated; //whether a maze has been generated

	

};


inline MazeBase::MazeBase():
WallsNo(0),
PathTIlesNo(0),
generated(false)
{

}


inline MazeBase::~MazeBase()
{
}

inline void MazeBase::generate()
{
	
}

/*!
clear the object by resetting all data and deleting object pointed by container
*/
inline void MazeBase::clear()
{
	clearBase();
}

inline std::size_t MazeBase::sizeOfMaze()
{
	return 0;
}

/*!
return total number of walls in maze
*/
inline std::size_t MazeBase::getWallsNo()
{
	return WallsNo;
}

/*!
return total number of path tiles in maze
*/
inline std::size_t MazeBase::getPathTilesNo()
{
	return PathTIlesNo;
}

inline MazeType MazeBase::getMazeType()
{
	return mazeType;
}

inline bool MazeBase::isGenerated()
{
	return generated;
}


inline void MazeBase::clearBase()
{
	
	WallsNo = PathTIlesNo = 0;
	generated = false;
}

