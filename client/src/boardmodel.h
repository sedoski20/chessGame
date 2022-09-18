#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include "squaremodel.h"
#include "igame.h"
#include <QTimer>

class BoardModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isPlayer1Turn READ getIsPlayer1Turn NOTIFY isPlayer1TurnChanged)
    Q_PROPERTY(bool isGameEnded READ getIsGameEnded NOTIFY isGameEndedChanged)

private:
    QList<SquareModel*> squares;
    IGame *i_game;
    void updatePieces();
    void resetSquares();
    bool isPlayer1Turn;
    bool isGameEnded;
    QString getPiecePath(PieceType type, bool isPlayer1);
    QTimer refreshTimer;


public:
    explicit BoardModel(IGame *game, QObject *parent = nullptr);
    explicit BoardModel(QObject *parent = nullptr);
    ~BoardModel();
    void setGameInterface(IGame *game);
    void reset();
    void setIsPlayer1Turn(bool value);
    void setIsGameEnded(bool value);
    bool getIsPlayer1Turn();
    bool getIsGameEnded();
    bool isLoaded();

    Q_INVOKABLE QObject* findSquare(int row, int column) const;
    Q_INVOKABLE QObject* findSquare(int index) const;
    Q_INVOKABLE bool select(int index);

signals:
    void isPlayer1TurnChanged();
    void isGameEndedChanged();

public slots:
    void update();




};

#endif // BOARDMODEL_H
