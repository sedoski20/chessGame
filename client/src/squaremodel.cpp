#include "squaremodel.h"
#include <qdebug.h>
#include "boardmodel.h"

SquareModel::SquareModel(const int row, const int column)
{
    this->row = row;
    this->column = column;
    this->isHighlited = false;
    this->iconPath = "";

    this->index = -1;
    int index = (8 * (7 - row)) + (7 - column);
    this->setIndex(index);
}

int SquareModel::getColumn() const
{
    return column;
}

int SquareModel::getRow() const
{
    return row;
}

bool SquareModel::getIsBlack() const
{
    return isBlack;
}

int SquareModel::getIndex() const
{
    return index;
}

QString SquareModel::getIconPath() const
{
    return iconPath;
}

bool SquareModel::isBlackSquare()
{
    bool is_odd_row = (row % 2 == 0) ? true : false;
    bool is_odd_column = (column % 2 == 0) ? true : false;

    bool result = (is_odd_row == is_odd_column);
    return result;
}

void SquareModel::setIndex(int newIndex)
{
    if (index == newIndex)
        return;

    index = newIndex;

    int row = (63 - index)/8;
    int column = (7 - index % 8);

    this->setRow(row);
    this->setColumn(column);
    this->setIsBlack(isBlackSquare());

    emit rowChanged();
    emit columnChanged();
    emit indexChanged();
    emit isBlackChanged();

}

void SquareModel::setIconPath(QString path)
{
    if(iconPath == path)
        return;

    this->iconPath = path;
    emit iconPathChanged();
}

void SquareModel::select()
{
    this->isHighlited = !isHighlited;
    emit isHighlitedChanged();
    qDebug() << "Square ROW: " << row << " COLUMN: " << column << " Clicked!";
}

void SquareModel::setIsBlack(bool newIsBlack)
{
    if (isBlack == newIsBlack)
        return;

    isBlack = newIsBlack;
    emit isBlackChanged();
}

void SquareModel::setRow(int newRow)
{
    if (row == newRow)
        return;

    row = newRow;
    emit rowChanged();
}

void SquareModel::setColumn(int newColumn)
{
    if (column == newColumn)
        return;

    column = newColumn;
    emit columnChanged();
}

bool SquareModel::getIsHighlited() const
{
    return this->isHighlited;
}

void SquareModel::setIsHighlited(bool value)
{
    if(isHighlited == value)
        return;

    this->isHighlited = value;
    emit isHighlitedChanged();
}

bool SquareModel::getIsAttack() const
{
    return this->isAttack;
}

void SquareModel::setIsAttack(bool value)
{
    if(isAttack == value)
        return;

    this->isAttack = value;
    emit isAttackChanged();
}
