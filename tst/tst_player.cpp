#include <gtest/gtest.h>
#include "../src/player.h"

TEST(PlayerTestCase, ConstructorTest1)
{
    Player player(MovementDirection::MOVING_UP, "Marcelo");
    EXPECT_EQ(player.getName(), "Marcelo");
    EXPECT_EQ(player.getActivePieces(), 16);

    std::vector<Piece *> pieces = player.getPieces();
    int count = 0;

    for(auto& piece : pieces)
    {
        Position rook1(0,0);
        Position rook2(0,7);
        Position knight1(0,1);
        Position knight2(0,6);
        Position bishop1(0,2);
        Position bishop2(0,5);
        Position king(0,3);
        Position queen(0,4);

        Position current_position = piece->getCurrentPosition();

        if(current_position == rook1 || current_position == rook2)
        {
            EXPECT_EQ(piece->getType(), PieceType::ROOK); 
            count++;
        }

        if(current_position == knight1 || current_position == knight2)
        {
            EXPECT_EQ(piece->getType(), PieceType::KNIGHT); 
            count++;
        }

        if(current_position == bishop1 || current_position == bishop2)
        {
            EXPECT_EQ(piece->getType(), PieceType::BISHOP); 
            count++;
        }

        if(current_position == king)
        {
            EXPECT_EQ(piece->getType(), PieceType::KING); 
            count++;
        }

        if(current_position == queen)
        {
            EXPECT_EQ(piece->getType(), PieceType::QUEEN); 
            count++;
        }

        if(current_position.row == 1)
        {
            EXPECT_EQ(piece->getType(), PieceType::PAWN); 
            count++;
        }
    }

    EXPECT_EQ(count, 16);
};
TEST(PlayerTestCase, ConstructorTest2)
{
    Player player(MovementDirection::MOVING_DOWN, "Anna Flavia");
    EXPECT_EQ(player.getName(), "Anna Flavia");
    EXPECT_EQ(player.getActivePieces(), 16);

    std::vector<Piece *> pieces = player.getPieces();
    int count = 0;

    for(auto& piece : pieces)
    {
        Position rook1(7,0);
        Position rook2(7,7);
        Position knight1(7,1);
        Position knight2(7,6);
        Position bishop1(7,2);
        Position bishop2(7,5);
        Position king(7,4);
        Position queen(7,3);

        Position current_position = piece->getCurrentPosition();

        if(current_position == rook1 || current_position == rook2)
        {
            EXPECT_EQ(piece->getType(), PieceType::ROOK); 
            count++;
        }

        if(current_position == knight1 || current_position == knight2)
        {
            EXPECT_EQ(piece->getType(), PieceType::KNIGHT); 
            count++;
        }

        if(current_position == bishop1 || current_position == bishop2)
        {
            EXPECT_EQ(piece->getType(), PieceType::BISHOP); 
            count++;
        }

        if(current_position == king)
        {
            EXPECT_EQ(piece->getType(), PieceType::KING); 
            count++;
        }

        if(current_position == queen)
        {
            EXPECT_EQ(piece->getType(), PieceType::QUEEN); 
            count++;
        }

        if(current_position.row == 6)
        {
            EXPECT_EQ(piece->getType(), PieceType::PAWN); 
            count++;
        }
    }

    EXPECT_EQ(count, 16);
};


