#include "serverinterface.h"
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <grpcpp/client_context.h>


using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::StatusCode;


ServerInterface::ServerInterface(std::string address) 
{
    std::shared_ptr<Channel> channel = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
    stub = ServerRequest::NewStub(channel);
}

void ServerInterface::connect(std::string name) 
{
    ClientContext context;
    GameInterface::Name name_;
    GameInterface::PlayerID player_id;

    name_.set_name(name);
    stub->connect(&context, name_, &player_id);

    this->playerId = static_cast<int>(player_id.id());
}

void ServerInterface::selectPosition(Position position) 
{
    ClientContext context;
    GameInterface::Position target;
    GameInterface::Empty empty;
    target.set_x(position.row);
    target.set_y(position.column);

    stub->click(&context, target, &empty);
}

const GameStatus ServerInterface::getGameStatus() const 
{
    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::GameStatus status;
    
    stub->getGameStatus(&context, empty, &status);

    return static_cast<GameStatus>(status.status());
}

const std::list<PositionStatus> ServerInterface::getHighlightedPositions() const 
{
    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PositionStatus grpc_position_status;
    std::list<PositionStatus> highlighted_positions;

    std::unique_ptr<ClientReader<GameInterface::PositionStatus>> 
    reader(stub->getHighLightedPositions(&context, empty));

    while (reader->Read(&grpc_position_status))
    {
        Position position;
        Status status;

        position.row = grpc_position_status.position().x();
        position.column = grpc_position_status.position().y();

        status = static_cast<Status>(grpc_position_status.status());
        highlighted_positions.push_back(PositionStatus(position, status));
    }

    grpc::Status status = reader->Finish();

    return highlighted_positions;
}

const std::list<PieceInfo> ServerInterface::getPlayer1Pieces() const 
{
    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PlayerPieces grpc_piece;
    std::list<PieceInfo> pieces;

    std::unique_ptr<ClientReader<GameInterface::PlayerPieces>> 
    reader(stub->getPlayer1Pieces(&context, empty));

    while (reader->Read(&grpc_piece))
    {
        Position position;
        PieceType type;

        position.row = grpc_piece.position().x();
        position.column = grpc_piece.position().y();

        type = static_cast<PieceType>(grpc_piece.piecetype());
        pieces.push_back(PieceInfo(position, type));
    }

    grpc::Status status = reader->Finish();

    return pieces;
}

const std::list<PieceInfo> ServerInterface::getPlayer2Pieces() const 
{
    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PlayerPieces grpc_piece;
    std::list<PieceInfo> pieces;

    std::unique_ptr<ClientReader<GameInterface::PlayerPieces>> 
    reader(stub->getPlayer2Pieces(&context, empty));

    while (reader->Read(&grpc_piece))
    {
        Position position;
        PieceType type;

        position.row = grpc_piece.position().x();
        position.column = grpc_piece.position().y();

        type = static_cast<PieceType>(grpc_piece.piecetype());
        pieces.push_back(PieceInfo(position, type));
    }

    grpc::Status status = reader->Finish();

    return pieces;
}

