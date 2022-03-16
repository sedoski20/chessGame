#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QQmlContext"
#include <QIcon>
#include <QLocale>
#include <QTranslator>
#include "squaremodel.h"
#include "boardmodel.h"
#include "igame.h"
#include "game.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Game game;
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
