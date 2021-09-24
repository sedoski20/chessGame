#ifndef BOARD_H
#define BOARD_H

#include "IBoard.h"
class Board :
    public IBoard
{
public:
    std::vector<Position> getAvailablePositionsOnBoard();
    int getValue();
    void setValue(int value);
private:
    int value;

};


#endif // BOARD_H
