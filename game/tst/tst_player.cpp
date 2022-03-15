#include <gtest/gtest.h>
#include "../src/player.h"

TEST(PlayerTestCase, ConstructorTest1)
{
    Player player(MovementDirection::MOVING_UP, "Marcelo");
    EXPECT_EQ(player.getName(), "Marcelo");
    EXPECT_EQ(player.getActivePieces(), 16);

    std::list<Piece *> pieces = player.getPieces(); 
    int count = 0;

    for(auto& piece : pieces)
    {
        Position rook1(0,0);
        Position rook2(0,7);
        Position knight1(0,1);
        Position knight2(0,6);
        Position bishop1(0,2);
        Position bishop2(0,5);
        Position king(0,4);
        Position queen(0,3);

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

    std::list<Piece *> pieces = player.getPieces(); 
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
TEST(PlayerTestCase, selectingPiece1)
{
    Player player(MovementDirection::MOVING_UP, "Marcelo Sedoski");
    EXPECT_EQ(player.getActivePieces(), 16);
    EXPECT_EQ(false,           player.isPieceSelected());

    //Selecting first ROOk
    EXPECT_EQ(true,            player.selectPiece(Position(0,0)));
    EXPECT_EQ(true,            player.isPieceSelected());
    EXPECT_EQ(PieceType::ROOK, player.getSelectedPiece()->getType());

    //Selecting empty position
    EXPECT_EQ(false,           player.selectPiece(Position(4,4)));
    EXPECT_EQ(false,           player.isPieceSelected());
    EXPECT_EQ(nullptr,         player.getSelectedPiece());

    //Selecting third pawn
    EXPECT_EQ(true,            player.selectPiece(Position(1,2)));
    EXPECT_EQ(true,            player.isPieceSelected());
    EXPECT_EQ(PieceType::PAWN, player.getSelectedPiece()->getType());

    //Selecting king pawn
    EXPECT_EQ(true,            player.selectPiece(Position(0,4)));
    EXPECT_EQ(true,            player.isPieceSelected());
    EXPECT_EQ(PieceType::KING, player.getSelectedPiece()->getType());
}
TEST(PlayerTestCase, movingPiece1)
{
    Player player(MovementDirection::MOVING_UP, "Marcelo Sedoski");
    Player opponent(MovementDirection::MOVING_DOWN, "Flavia Tamanini");

    std::list<Piece *> opponent_pieces = opponent.getPieces();

    EXPECT_EQ(player.getActivePieces(), 16);
    EXPECT_EQ(false,           player.isPieceSelected());
    bool result;


    //Moving a pawn
    EXPECT_EQ(true,            player.selectPiece(Position(1,5)));
    EXPECT_EQ(true,            player.moveSelectedPiece(opponent_pieces, Position(3,5))); 
    EXPECT_EQ(false,           player.isPieceSelected());
    
    result = false;

    for(auto &piece :player.getPieces())
    {
        if(piece->getCurrentPosition() == Position(3,5))
            if(piece->getType() == PieceType::PAWN)
                result = true;
    }

    EXPECT_EQ(true, result);
    
    //Moving the pawn again
    EXPECT_EQ(true,            player.selectPiece(Position(3,5)));
    EXPECT_EQ(true,            player.moveSelectedPiece(opponent_pieces, Position(4,5))); 
    EXPECT_EQ(false,           player.isPieceSelected());

    result = false;

    for(auto &piece :player.getPieces())
    {
        if(piece->getCurrentPosition() == Position(4,5))
            if(piece->getType() == PieceType::PAWN)
                result = true;
    }

    EXPECT_EQ(true, result);

    //Remove the pawn in front of queen
    EXPECT_EQ(true, player.receiveAttack(Position(1,3)));

    //Moving the queen
    EXPECT_EQ(true,            player.selectPiece(Position(0,3)));
    EXPECT_EQ(true,            player.moveSelectedPiece(opponent_pieces, Position(5,3))); 
    EXPECT_EQ(false,           player.isPieceSelected());

    result = false;

    for(auto &piece :player.getPieces())
    {
        if(piece->getCurrentPosition() == Position(5,3))
            if(piece->getType() == PieceType::QUEEN)
                result = true;
    }

    EXPECT_EQ(true, result);
}



TEST(PlayerTestCase, checkMateTest1)
{

    // Player player(MovementDirection::MOVING_UP, "Marcelo Sedoski");
    // Player opponent(MovementDirection::MOVING_DOWN, "Flavia Tamanini");

    // std::list<Piece *> opponent_pieces = opponent.getPieces();

    // player.isCheckmate(opponent_pieces);
}


