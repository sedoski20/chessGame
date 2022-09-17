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
#include "mainmenumodel.h"
#include "serverinterface.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Game game;
    ServerInterface game;
    MainMenuModel main_menu;
    IGame *igame = &game;
    BoardModel board(igame);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    QObject::connect(&main_menu, SIGNAL(connect(QString, QString)), &game, SLOT(connectRequest(QString, QString)));

    engine.rootContext()->setContextProperty("mainMenuModel", &main_menu );
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
