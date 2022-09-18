#include "mainmenumodel.h"
#include <iostream>

MainMenuModel::MainMenuModel(QObject *parent) : QObject(parent) { finished = false; }

QString MainMenuModel::getPlayer1()
{
    return player1;
}

void MainMenuModel::setPlayer1(const QString &value)
{
    player1 = value;
}

QString MainMenuModel::getPlayer2()
{
    return player2;
}

void MainMenuModel::setPlayer2(const QString &value)
{
    player2 = value;
}

QString MainMenuModel::getServerAddress()
{
    return serverAddress;
}

void MainMenuModel::setServerAddress(const QString &value)
{
    serverAddress = value;
}

bool MainMenuModel::getGameMode()
{
    return gameMode;
}

void MainMenuModel::setGameMode(bool value)
{
    gameMode = value;
}

bool MainMenuModel::getMultiplayer()
{
    return multiplayer;
}

void MainMenuModel::setMultiplayer(bool value)
{
    multiplayer = value;
}

void MainMenuModel::start()
{
    emit connect(player1, serverAddress);
}

bool MainMenuModel::getFinished()
{
    return finished;
}

void MainMenuModel::connectResult(bool value)
{
    finished = value;

    if(finished)
        emit finishedChanged();
}