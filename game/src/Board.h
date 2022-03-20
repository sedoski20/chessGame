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
    BoardPositions getNewArrangementFromMovement(Position movement) const;
    void removeUnsafeMovements(std::list<Position> &movements) const;

public:
    Board();    
    void updateTurn();
    bool isCheckmate();
    bool isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const;
    bool select(Position &position);
    void unslect();
    bool isPieceSelected() const;
    bool moveSelectedPiece(Position position);

    std::list<Position> getPossibleMovements();
    BoardPositions getBoardPositions() const;
    IPlayer* const getPlayer1() const {return this->player1;};
    IPlayer* const getPlayer2() const {return this->player2;};
};
#endif // BOARD_H
