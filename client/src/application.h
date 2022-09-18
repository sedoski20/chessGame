#ifndef APPLICATION_H
#define APPLICATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include "serverinterface.h"
#include "mainmenumodel.h"
#include "boardmodel.h"

class Application : public QObject
{
    Q_OBJECT

    public:
    Application(int &argc, char **argv, QObject *parent = nullptr);

    private:
    QGuiApplication *app;
    QQmlApplicationEngine *engine;
    ServerInterface *game;
    MainMenuModel *mainMenu;
    BoardModel *board;

    public slots:
    void startGame(bool result);
};

#endif // APPLICATION_H
