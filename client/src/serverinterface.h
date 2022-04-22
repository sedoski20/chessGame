#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include "igame.h"
#include "interface.grpc.pb.h"

using GameInterface::ServerRequest;

class ServerInterface : public IGame
{
    private:
        int playerId;
        std::unique_ptr<ServerRequest::Stub> stub;
        

    public:
        ServerInterface(std::string address);
        void connect(std::string name);
        void selectPosition(Position position);
        const GameStatus getGameStatus() const; 
        const std::list<PositionStatus> getHighlightedPositions() const;
        const std::list<PieceInfo> getPlayer1Pieces() const;
        const std::list<PieceInfo> getPlayer2Pieces() const;
};



#endif // SERVERINTERFACE_H
