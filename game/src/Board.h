#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "piece.h"


enum class PlayerTurn
{
    TURN_PLAYER1,
    TURN_PLAYER2
};

class Board : public IBoard
{

private:
    IPlayer *player1;
    IPlayer *player2;
    IPlayer *getCurrentPlayer() const;
    IPlayer *getOpponentPlayer() const;

    const Piece *selectedPiece;
    PlayerTurn turn;
    BoardStatus boardStatus;

    void removeUnsafeMovements(std::list<Position> &movements, const Piece* targetPiece) const;
    bool isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const; 
    BoardPositions getNewArrangementFromMovement(Position targetPosition, const Piece* targetPiece) const;
    BoardPositions getBoardPositions() const; 
    std::list<Position> getPossibleMovements(const Piece *piece);

public:
    Board();    
    void updateTurn();
    void unslect();
    void updateBoardStatus();
    bool isCheckmate();
    bool select(Position &position);
    bool isPieceSelected() const;
    bool moveSelectedPiece(Position position);
    const BoardStatus getBoardStatus() const;

};
#endif // BOARD_H
