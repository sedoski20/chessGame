#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

namespace kingEscaping
{
    Piece *selected_piece = new King(Position(0,0));

    std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(4,0))
    };

    std::list<Position> possible_movements_expected = 
    {
        Position(0,1),
        Position(1,1)
    };

    Position king_position(0,0);
}

namespace kingAttacking
{
    Piece *selected_piece = new King(Position(0,0));

    std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,0))
    };

    std::list<Position> possible_movements_expected = 
    {
        Position(1,0),
        Position(0,1),
        Position(1,1)
    };

    Position king_position(0,0);
}

namespace kingProtectionFence
{
    Piece *selected_piece = new Pawn(Position(1,1));

    std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(3,2))
    };

    std::list<Position> possible_movements_expected = 
    {
        Position(2,1),
    };

    Position king_position(1,0);
}

namespace kingProtectionAttack
{
    Piece *selected_piece = new Pawn(Position(1,1));

    std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(2,0))
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(2,2))
    };

    std::list<Position> possible_movements_expected = 
    {
        Position(2,1),
        Position(2,2),
    };

    Position king_position(2,0);
}

namespace noSafeMovements1
{
    Piece *selected_piece = new Pawn(Position(1,1));

    std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,2))
    };

    std::list<Position> possible_movements_expected = 
    {
    };

    Position king_position(1,0);
}

namespace noSafeMovements2
{
    Piece *selected_piece = new Pawn(Position(1,5));

    std::list<const Piece*> current_player = 
    {
        selected_piece,
        new King(Position(1,0))
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,2))
    };

    std::list<Position> possible_movements_expected = 
    {
    };

    Position king_position(1,0);
}

namespace checkMate
{
    Piece *selected_piece = new King(Position(0,0));

    std::list<const Piece*> current_player = 
    {
        selected_piece
    };

    std::list<const Piece*> opponent_player = 
    {
        new Queen(Position(1,3)),
        new Rook(Position(0,3))
    };

    std::list<Position> possible_movements_expected = 
    {
    };

    Position king_position(0,0);
}