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
    void unselect();

public:
    Board(const PlayerManager *players);
    ~Board();   
    bool select(Position &position);
    bool isPieceSelected() const;
    bool moveSelectedPiece(Position position);
    const Piece *getSelectedPiece() const;
};
#endif // BOARD_H
