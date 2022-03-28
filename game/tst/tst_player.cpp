#include <gtest/gtest.h>
#include "player.h"
#include "pawn.h"

TEST(PlayerTestCase, ConstructorTest1)
{
    Player player(MovementDirection::MOVING_UP);

    std::list<const Piece *> pieces = player.getPieces(); 
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

        Position current_position = piece->getPosition();

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
    Player player(MovementDirection::MOVING_DOWN);

    std::list<const Piece *> pieces = player.getPieces(); 
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

        Position current_position = piece->getPosition();

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

TEST(PlayerTestCase, movingPiece1)
{
    Player player(MovementDirection::MOVING_UP);
    Position from;
    Position to;
    Piece * piece;

    from.row = 1;
    from.column = 0;

    to.row = 2;
    to. column = 0;

    //Moving a pawn
    EXPECT_EQ(true, player.movePiece(to, from));
    
    piece = player.findPiece(to);

    EXPECT_EQ(true, piece != nullptr);
    EXPECT_EQ(true, piece->getType() == PieceType::PAWN);
    
    //Moving the pawn again
    from.row = 1;
    from.column = 5;

    to.row = 3;
    to. column = 5;

    EXPECT_EQ(true, player.movePiece(to, from)); 

    piece = player.findPiece(to);

    EXPECT_EQ(true, piece != nullptr);
    EXPECT_EQ(true, piece->getType() == PieceType::PAWN);

    // Tryiing to move to invalid position
    from.row = 1;
    from.column = 7;

    to.row = 2;
    to. column = 7;

    EXPECT_EQ(false, player.movePiece(from, to)); 

    // Tryiing to move to an inexistent piece
    from.row = 4;
    from.column = 4;

    to.row = 2;
    to. column = 7;

    EXPECT_EQ(false, player.movePiece(from, to)); 

}

TEST(PlayerTestCase, capture)
{
    Player player(MovementDirection::MOVING_UP);
    Position target;
    Piece * piece;

    target.row = 0;
    target.column = 0;

    piece = player.findPiece(target);
    EXPECT_EQ(true, piece != nullptr);
    EXPECT_EQ(true, piece->getType() == PieceType::ROOK);

    //Capturing the ROOK
    EXPECT_EQ(true, player.capturePiece(target));
    piece = player.findPiece(target);
    EXPECT_EQ(true, piece == nullptr);

    target.row = 1;
    target.column = 5;

    piece = player.findPiece(target);
    EXPECT_EQ(true, piece != nullptr);
    EXPECT_EQ(true, piece->getType() == PieceType::PAWN);

    //Capturing the PAWN
    EXPECT_EQ(true, player.capturePiece(target));
    piece = player.findPiece(target);
    EXPECT_EQ(true, piece == nullptr);

    target.row = 4;
    target.column = 4;

    piece = player.findPiece(target);
    EXPECT_EQ(true, piece == nullptr);

    //Trying to capture on invalid position
    piece = player.findPiece(target);
    EXPECT_EQ(true, piece == nullptr);

    EXPECT_EQ(false, player.capturePiece(target));
}

TEST(PlayerTestCase, getKingPosition)
{
    Player player(MovementDirection::MOVING_UP);
    Position king_position = player.getKingPosition();
    Position check = Position(0,4);

    EXPECT_EQ(king_position, check);
}
TEST(PlayerTestCase, ReadOnlyGetPieces)
{
    //  This testcase checks the encapsulation of the class player
    // 
    //  It is necessary to get the pieces information outside of player
    //  this way there is a method called "getPieces" that returns the
    //  pieces list from player object. 
    // 
    //  GetPieces returns a const list of const Pieces to ensure that any
    //  data or behavior wiil be changed outseide of player.
    //
    //  So the the commented lines aims to modify the const object returned from
    //  the getPieces method. It needs to  get a compile error, so uncomment and 
    //  verify thid behavior. 


    Player player(MovementDirection::MOVING_UP);
    
    std::list<const Piece *> pieces = player.getPieces();
    // pieces.front()->move(Position(4,5));
}
TEST(PlayerTestCase, getPieces)
{
    Player player(MovementDirection::MOVING_UP);
    std::list<const Piece *> pieces = player.getPieces(); 
    EXPECT_EQ(pieces.size(), 16);
}