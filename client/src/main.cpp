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
#include "application.h"

// void loadMainMenu(const MainMenuModel &menu, int argc, char *argv[]);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Application app(argc, argv);
}

    // Game game;
    // MainMenuModel main_menu;
    // ServerInterface game;
    // IGame *igame = &game;
    // BoardModel board(igame);

    // QObject::connect(&main_menu, SIGNAL(connect(QString, QString)), &game, SLOT(connectRequest(QString, QString)));
    // QObject::connect(&game, SIGNAL(connectResult(bool), &board )
    // loadMainMenu(main_menu, argc, argv);



// void loadMainMenu(const MainMenuModel &menu, const BoardModel &board, int argc, char *argv[])
// {
//     QGuiApplication app(argc, argv);
//     QQmlApplicationEngine engine;
//     const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

//     engine.rootContext()->setContextProperty("mainMenuModel", &menu);
//     engine.rootContext()->setContextProperty("boardModel", &board );

//     QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                      &app, [url](QObject *obj, const QUrl &objUrl) {
//         if (!obj && url == objUrl)
//             QCoreApplication::exit(-1);
//     }, Qt::QueuedConnection);
//     engine.load(url);

//     app.setWindowIcon(QIcon(":/images/black_king.png"));
//     app.exec();
// }
