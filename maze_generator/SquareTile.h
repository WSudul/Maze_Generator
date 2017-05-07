#pragma once

#include <string>

/*!
	Class representing a square tile
*/
class SquareTile
{
public:
	SquareTile();
	SquareTile(bool N, bool W, bool S, bool E);

	virtual ~SquareTile();

	virtual bool isPassable();

	bool hasWalls();

	bool& atN();

	bool& atW();

	bool& atS();

	bool& atE();

	virtual std::string toString() const;



	friend std::ostream& operator<<(std::ostream& out, const SquareTile& S)
	{
		return out << S.toString();
	};

protected:

	bool N, W, S, E; //marks whether there is a wall



};

