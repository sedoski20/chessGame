#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include "squaremodel.h"
#include "igame.h"

class BoardModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isPlayer1Turn READ getIsPlayer1Turn NOTIFY isPlayer1TurnChanged)

private:
    QList<SquareModel*> squares;
    IGame *i_game = nullptr;
    void updatePieces();
    void resetSquares();
    bool isPlayer1Turn;
    QString getPiecePath(PieceType type, bool isPlayer1);


public:

    explicit BoardModel(IGame *game);
    ~BoardModel();
    void reset();
    void setIsPlayer1Turn(bool value);
    bool getIsPlayer1Turn();

    Q_INVOKABLE QObject* findSquare(int row, int column) const;
    Q_INVOKABLE QObject* findSquare(int index) const;
    Q_INVOKABLE bool select(int index);

signals:
    void isPlayer1TurnChanged();




};

#endif // BOARDMODEL_H
