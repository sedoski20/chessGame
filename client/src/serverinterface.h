#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include "igame.h"
#include "interface.grpc.pb.h"
#include <QObject>

using GameInterface::ServerRequest;

class ServerInterface : public QObject, public IGame
{
    Q_OBJECT

    private:
        int playerId;
        bool isConnected;
        std::unique_ptr<ServerRequest::Stub> stub;
        

    public:
        ServerInterface(QObject *parent = nullptr);
        ServerInterface(std::string address, QObject *parent = nullptr);
        bool connect(std::string name);
        void setServerAddress(std::string address);
        void selectPosition(Position position) override;
        const GameStatus getGameStatus() const override; 
        const std::list<PositionStatus> getHighlightedPositions() const override;
        const std::list<PieceInfo> getPlayer1Pieces() const override;
        const std::list<PieceInfo> getPlayer2Pieces() const override;
        PlayerTurn getPlayerTurn() const override;

    public slots:
        void connectRequest(QString name, QString address);


};



#endif // SERVERINTERFACE_H
