#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "piece.h"
#include "playermanager.h"

class Board : public IBoard
{

private:
    const PlayerManager *players;
    const Piece *selectedPiece;

public:
    Board(const PlayerManager *players);    
    void unslect();
    bool select(Position &position);
    bool isPieceSelected() const;
    bool moveSelectedPiece(Position position);
    const Piece *getSeletedPiece() const;
};
#endif // BOARD_H
