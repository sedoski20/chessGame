#ifndef BOARDENGINE_TESTCASES_DATA_H
#define BOARDENGINE_TESTCASES_DATA_H

#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

namespace kingEscaping
{
    static const Piece *selected_piece = new King(Position(0,0));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(4,0))
    };

    static const std::list<Position> possible_movements_expected = 
    {
        Position(0,1),
        Position(1,1)
    };

    static const Position king_position(0,0);
}

namespace kingAttacking
{
    static const Piece *selected_piece = new King(Position(0,0));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,0))
    };

    static const std::list<Position> possible_movements_expected = 
    {
        Position(1,0),
    };

    static const Position king_position(0,0);
}

namespace kingProtectionFence
{
    static const Piece *selected_piece = new Pawn(Position(1,1));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(3,2))
    };

    static const std::list<Position> possible_movements_expected = 
    {
        Position(2,1),
    };

    static const Position king_position(1,0);
}

namespace kingProtectionAttack
{
    static const Piece *selected_piece = new Pawn(Position(1,1));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(2,0))
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(2,2))
    };

    static const std::list<Position> possible_movements_expected = 
    {
        Position(2,1),
        Position(2,2),
    };

    static const Position king_position(2,0);
}

namespace noSafeMovements1
{
    static const Piece *selected_piece = new Pawn(Position(1,1));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,2))
    };

    static const std::list<Position> possible_movements_expected = 
    {
    };

    static const Position king_position(1,0);
}

namespace noSafeMovements2
{
    static const Piece *selected_piece = new Pawn(Position(1,5));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,2))
    };

    static const std::list<Position> possible_movements_expected = 
    {
    };

    static const Position king_position(1,0);
}

namespace checkMate
{
    static const Piece *selected_piece = new King(Position(0,0));

    static const std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    static const std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,3)),
        new Rook(Position(0,3))
    };

    static const std::list<Position> possible_movements_expected = 
    {
    };

    static const Position king_position(0,0);
}

#endif // BOARDENGINE_TESTCASES_DATA_H
