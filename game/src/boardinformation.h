#ifndef BOARDINFORMATION_H
#define BOARDINFORMATION_H

#include "pieceinfo.h"


class BoardInformation
{
private:
    std::list<PieceInfo> currentPlayerInformation;
    std::list<PieceInfo> opponentPlayerInformation;

public:
    BoardInformation(const std::list<PieceInfo> &currentPlayerInformation,
                     const std::list<PieceInfo> &opponentPlayerInformation);

    const std::list<PieceInfo> getCurrentPlayerPositions() const { return currentPlayerInformation; };
    const std::list<PieceInfo> getOpponentPlayerPositions() const { return opponentPlayerInformation; };
};




#endif // BOARDINFORMATION_H
