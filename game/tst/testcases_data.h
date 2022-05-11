#ifndef TESTCASES_DATA_H
#define TESTCASES_DATA_H

#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

class TestCasesData
{
    public:
        ~TestCasesData();
        const Piece *selected_piece;
        Position king_position;
        std::list<const Piece*> current_player;
        std::list<const Piece*> opponent_player;
        std::list<Position> possible_movements_expected; 

};

struct KingEscaping : public TestCasesData
{
    KingEscaping();
};

struct KingAttacking : public TestCasesData
{
    KingAttacking();
};

struct KingProtectionFence : public TestCasesData
{
    KingProtectionFence();
};

struct KingProtectionAttack : public TestCasesData
{
    KingProtectionAttack();
};

struct NoSafeMovements1 : public TestCasesData
{
    NoSafeMovements1();
};

struct NoSafeMovements2 : public TestCasesData
{
    NoSafeMovements2();
};

struct CheckMate : public TestCasesData
{
    CheckMate();
};

#endif // TESTCASES_DATA_H
