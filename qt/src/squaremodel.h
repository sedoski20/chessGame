#ifndef SQUAREMODEL_H
#define SQUAREMODEL_H

#include <QObject>

class SquareModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isHighlited READ getIsHighlited WRITE setIsHighlited NOTIFY isHighlitedChanged)
    Q_PROPERTY(int column READ getColumn NOTIFY columnChanged)
    Q_PROPERTY(int row READ getRow NOTIFY rowChanged)
    Q_PROPERTY(bool isBlack READ getIsBlack NOTIFY isBlackChanged)
    Q_PROPERTY(int index READ getIndex WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(QString iconPath READ getIconPath WRITE setIconPath NOTIFY iconPathChanged)

public:
    explicit SquareModel(const int row, const int _column);
    bool getIsHighlited() const;
    int getColumn() const;
    int getRow() const;
    bool getIsBlack() const;
    int getIndex() const;
    QString getIconPath() const;

private:
    bool isHighlited;
    bool isBlack;
    int column;
    int row;
    int index;
    QString iconPath;

    bool isBlackSquare();

signals:
    void isHighlitedChanged();
    void columnChanged();
    void rowChanged();
    void isBlackChanged();
    void indexChanged();
    void iconPathChanged();

public slots:
    void setIsHighlited(bool);
    void setColumn(int newColumn);
    void setRow(int newRow);
    void setIsBlack(bool newIsBlack);
    void setIndex(int newIndex);
    void setIconPath(QString path);
    void select();

};

#endif // SQUAREMODEL_H
