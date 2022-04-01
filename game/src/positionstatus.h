#ifndef POSITIONSTATUS_H
#define POSITIONSTATUS_H

#include "position.h"

enum class Status
{
    NORMAL,
    HIGHLIGHTED,
    SELECTED,
    ATTACK,
    CHECK
};

class PositionStatus
{
    private:
        Position position;
        Status status;
    public:
        PositionStatus(Position position, Status status);
        Status getStatus() const { return status; }
        Position getPosition() const { return position; }
};

#endif // POSITIONSTATUS_H
