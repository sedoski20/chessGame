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

ServerInterface::ServerInterface(QObject *parent) : QObject(parent) 
{
    setServerAddress("127.0.0.1");
}

ServerInterface::ServerInterface(std::string address, QObject *parent) : QObject(parent)
{
    setServerAddress(address);
}

void ServerInterface::setServerAddress(std::string address)
{
    std::shared_ptr<Channel> channel = grpc::CreateChannel(address + ":50051", grpc::InsecureChannelCredentials());
    stub = ServerRequest::NewStub(channel);
}

bool ServerInterface::connect(std::string name) 
{
    ClientContext context;
    GameInterface::Name name_;
    GameInterface::PlayerID player_id;

    name_.set_name(name);
    grpc::Status status = stub->connect(&context, name_, &player_id);

    if(!status.ok())
        return false;

    this->playerId = static_cast<int>(player_id.id());
    return true;
}

void ServerInterface::selectPosition(Position position) 
{
    if(!this->isConnected)
        return;

    ClientContext context;
    GameInterface::PlayerID *player_id = new GameInterface::PlayerID();
    GameInterface::Position *target = new GameInterface::Position();
    GameInterface::Empty empty;
    GameInterface::ClickRequest request;

    target->set_x(position.row);
    target->set_y(position.column);
    player_id->set_id(this->playerId);
    request.set_allocated_id(player_id);
    request.set_allocated_position(target);

    stub->click(&context, request, &empty);
}

const GameStatus ServerInterface::getGameStatus() const 
{
    if(!this->isConnected)
        GameStatus::INITIAL;
        
    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::GameStatus status;
    
    stub->getGameStatus(&context, empty, &status);

    return static_cast<GameStatus>(status.status());
}

const std::list<PositionStatus> ServerInterface::getHighlightedPositions() const 
{
    std::list<PositionStatus> highlighted_positions;

    if(!this->isConnected)
        return highlighted_positions;

    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PositionStatus grpc_position_status;

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
    std::list<PieceInfo> pieces;
    
    if(!this->isConnected)
        return pieces;

    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PlayerPieces grpc_piece;

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
    std::list<PieceInfo> pieces;

    if(!this->isConnected)
        return pieces;

    ClientContext context;
    GameInterface::Empty empty;
    GameInterface::PlayerPieces grpc_piece;

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

PlayerTurn ServerInterface::getPlayerTurn() const
{
    std::cout << "Not implemented";
    return PlayerTurn::TURN_PLAYER1;
}

void ServerInterface::connectRequest(QString name, QString address)
{
    if(address != "")
        this->setServerAddress(address.toStdString());

    this->isConnected = this->connect(name.toStdString());
    emit connectResult(this->isConnected);        
}

