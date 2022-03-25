#pragma once
#include "position.h"

enum class PieceType
{
	ROOK,
	KNIGHT,
	BISHOP, 
	QUEEN,
	KING,
	PAWN
};

struct PieceInfo
{
	Position position;
	PieceType type;
};