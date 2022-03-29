#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "piece.h"
#include "playermanager.h"


// enum class PlayerTurn
// {
//     TURN_PLAYER1,
//     TURN_PLAYER2
// };

class Board : public IBoard
{

private:
    PlayerManager *players;

    const Piece *selectedPiece;
    PlayerTurn turn;
    BoardStatus boardStatus;

    void updateTurn();
    void removeUnsafeMovements(std::list<Position> &movements, const Piece* targetPiece) const;
    bool isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const; 
    BoardPositions getNewArrangementFromMovement(Position targetPosition, const Piece* targetPiece) const;
    BoardPositions getBoardPositions() const; 
    std::list<Position> getPossibleMovements(const Piece *piece);

public:
    Board(PlayerManager *players);    
    void unslect();
    bool select(Position &position);
    bool isPieceSelected() const;
    bool moveSelectedPiece(Position position);
    bool isCheckmate();
    const BoardStatus getBoardStatus();

};
#endif // BOARD_H
