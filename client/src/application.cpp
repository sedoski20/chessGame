#include "application.h"
#include "igame.h"
#include "QQmlContext"
#include <QIcon>

Application::Application(int &argc, char **argv, QObject *parent) : QObject(parent) 
{
    app = new QGuiApplication(argc, argv);
    engine = new QQmlApplicationEngine;
    game = new ServerInterface;
    mainMenu = new MainMenuModel;
    board = new BoardModel;

    // IGame *igame = &game;
    // BoardModel board(igame);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    QObject::connect(mainMenu, SIGNAL(connect(QString, QString)), game, SLOT(connectRequest(QString, QString)));
    QObject::connect(game, SIGNAL(connectResult(bool)), this, SLOT(startGame(bool)));

    engine->rootContext()->setContextProperty("mainMenuModel", mainMenu);
    engine->rootContext()->setContextProperty("boardModel", board );

    QObject::connect(engine, &QQmlApplicationEngine::objectCreated,
                     app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine->load(url);

    app->setWindowIcon(QIcon(":/images/black_king.png"));
    app->exec();
}

void Application::startGame(bool result)
{
    if(!result)
        return;

    IGame *i_game = game;
    board->setGameInterface(i_game);
    this->mainMenu->connectResult(result);

}