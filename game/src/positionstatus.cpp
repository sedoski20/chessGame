#include "positionstatus.h"

PositionStatus::PositionStatus(Position position, Status status) : position(position), status(status) {}

bool PositionStatus::operator==(const PositionStatus &other) const 
{
	if(!(this->position == other.position))
        return false;

	if (this->status != other.status)
		return false;

	return true;
}
