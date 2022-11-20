#ifndef REQUEST_H
#define REQUEST_H

#include "../../interface/interface.pb.h"
#include "../../interface/interface.grpc.pb.h"

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "igame.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::StatusCode;
using GameInterface::ServerRequest;
using GameInterface::Empty;
using GameInterface::Name;
using GameInterface::PlayerID;
using GameInterface::PlayerPieces;
using GameInterface::ClickRequest;
using GameInterface::PlayerTurnRequest;

class Request : public ServerRequest::Service
{
    public:
        Request(IGame *game) : game(game) {};
        ~Request();
        grpc::Status connect(ServerContext* context, const Name* request, PlayerID* response) override;
        grpc::Status click(ServerContext* context, const GameInterface::ClickRequest* request, Empty* response) override;
        grpc::Status getGameStatus(ServerContext* context, const Empty* request, GameInterface::GameStatus* response) override;
        grpc::Status getHighLightedPositions(ServerContext* context, const Empty* request, ServerWriter<GameInterface::PositionStatus>* writer) override;
        grpc::Status getPlayer1Pieces(ServerContext* context, const Empty* request, ServerWriter<PlayerPieces>* writer) override;
        grpc::Status getPlayer2Pieces(ServerContext* context, const Empty* request, ServerWriter<PlayerPieces>* writer) override;
        grpc::Status getPlayerTurn(ServerContext* context, const Empty* request, ::GameInterface::PlayerTurnRequest* response) override;
                     

    private:
        int clients = 0;
        IGame *game;
};

#endif // REQUEST_H
