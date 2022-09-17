#ifndef MAINMENUMODEL_H
#define MAINMENUMODEL_H

#include <QObject>
#include <QString>

class MainMenuModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString player1 READ getPlayer1 WRITE setPlayer1)
    Q_PROPERTY(QString player2 READ getPlayer2 WRITE setPlayer2)
    Q_PROPERTY(QString serverAddress READ getServerAddress WRITE setServerAddress)
    Q_PROPERTY(bool gameMode READ getGameMode WRITE setGameMode)
    Q_PROPERTY(bool multiplayer READ getMultiplayer WRITE setMultiplayer)

public:
    explicit MainMenuModel(QObject *parent = nullptr);
    QString getPlayer1();
    QString getPlayer2();
    QString getServerAddress();
    bool getGameMode();
    bool getMultiplayer();
    Q_INVOKABLE void start();

private:
    QString player1;
    QString player2;
    QString serverAddress;
    bool gameMode;
    bool multiplayer;


signals:
    void connect(QString name, QString address);

public slots:

    void setPlayer1(const QString &value);
    void setPlayer2(const QString &value);
    void setServerAddress(const QString &value);
    void setGameMode(bool value);
    void setMultiplayer(bool value);
};

#endif //MAINMENUMODEL
