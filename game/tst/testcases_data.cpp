#include "testcases_data.h"

TestCasesData::~TestCasesData()
{
    for(auto piece : current_player)
        delete piece;
        
    for(auto piece : opponent_player)
        delete piece;
}

KingEscaping::KingEscaping()
{
    selected_piece = new King(Position(0,0));

    current_player.push_back(selected_piece);
    opponent_player.push_back(new Queen(Position(4,0)));

    possible_movements_expected.push_back(Position(0,1));
    possible_movements_expected.push_back(Position(1,1));
    king_position = Position(0,0);
}

KingAttacking::KingAttacking()
{
    selected_piece = new King(Position(0,0));

    current_player.push_back(selected_piece);
    opponent_player.push_back(new Queen(Position(1,0)));

    possible_movements_expected.push_back(Position(1,0));
    king_position = Position(0,0);
}

KingProtectionFence::KingProtectionFence()
{
    selected_piece = new Pawn(Position(1,1));

    current_player.push_back(selected_piece);
    current_player.push_back(new King(Position(1,0)));
    opponent_player.push_back(new Queen(Position(3,2)));

    possible_movements_expected.push_back(Position(2,1));
    king_position = Position(1,0);
}

KingProtectionAttack::KingProtectionAttack()
{
    selected_piece = new Pawn(Position(1,1));

    current_player.push_back(selected_piece);
    current_player.push_back(new King(Position(2,0)));
    opponent_player.push_back(new Queen(Position(2,2)));

    possible_movements_expected.push_back(Position(2,1));
    possible_movements_expected.push_back(Position(2,2));
    king_position = Position(2,0);
}

NoSafeMovements1::NoSafeMovements1()
{
    selected_piece = new Pawn(Position(1,1));

    current_player.push_back(selected_piece);
    current_player.push_back(new King(Position(1,0)));
    opponent_player.push_back(new Queen(Position(1,2)));

    king_position = Position(1,0);
}

NoSafeMovements2::NoSafeMovements2()
{
    selected_piece = new Pawn(Position(1,5));

    current_player.push_back(selected_piece);
    current_player.push_back(new King(Position(1,0)));
    opponent_player.push_back(new Queen(Position(1,2)));

    king_position = Position(1,0);
}

CheckMate::CheckMate()
{
    selected_piece =new King(Position(0,0));

    current_player.push_back(selected_piece);
    opponent_player.push_back(new Queen(Position(1,3)));
    opponent_player.push_back(new Rook(Position(0,3)));

    king_position = Position(0,0);
}

