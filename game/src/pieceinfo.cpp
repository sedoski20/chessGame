#include "pieceinfo.h"

PieceInfo::PieceInfo(Position position, PieceType type) : position_(position), type_(type) {}

Position PieceInfo::position() 
{
    return this->position_;    
}

PieceType PieceInfo::type() 
{
 return this->type_;    
}
