#include "stdafx.h"
#include "SquareTile.h"

SquareTile::SquareTile() :
	N(false), W(false), S(false), E(false)
{
}

SquareTile::SquareTile(bool N, bool W, bool S, bool E) :
	N(N), W(W), S(S), E(E)
{

}

SquareTile::~SquareTile()
{
}

inline bool SquareTile::isPassable()
{
	return (N && W && S && E);
}

inline bool SquareTile::hasWalls()
{
	return (N || W || S || E);
}

inline bool & SquareTile::atN()
{
	return N;
}

inline bool & SquareTile::atW()
{
	return W;
}

inline bool & SquareTile::atS()
{
	return S;
}

inline bool & SquareTile::atE()
{
	return E;
}

inline std::string SquareTile::toString() const
{
	std::string str;
	str.reserve(4);
	str += (N? 'X' : 'N');
	str += (W? 'X' : 'W');
	str += (S? 'X' : 'S');
	str += (E? 'X' : 'E');
	return str;
}
