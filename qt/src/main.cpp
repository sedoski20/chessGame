#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "squaremodel.h"
#include "QQmlContext"
#include <QIcon>
#include <QLocale>
#include <QTranslator>
#include "boardmodel.h"
#include "iplayer.h"
#include "player.h"
#include "igame.h"
#include "game.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Player player1(MovementDirection::MOVING_UP, "Marcelo");
    Player player2(MovementDirection::MOVING_DOWN, "Anna");

    IPlayer *iplayer1 = &player1;
    IPlayer *iplayer2 = &player2;

    Game game(iplayer1, iplayer2);
    IGame *igame = &game;

    BoardModel board(igame);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    engine.rootContext()->setContextProperty("boardModel", &board );
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    app.setWindowIcon(QIcon(":/images/black_king.png"));
    return app.exec();
}
