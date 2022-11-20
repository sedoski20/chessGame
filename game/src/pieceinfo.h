#ifndef PIECEINFO_H
#define PIECEINFO_H

#include "position.h"
#include "piecetype.h"

class PieceInfo
{
    private:
        Position position_;
        PieceType type_;

    public:
        PieceInfo(Position position, PieceType type);
        Position position();
        PieceType type();
};

#endif // PIECEINFO_H
