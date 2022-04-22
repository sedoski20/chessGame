#include "request.h"
#include <iostream>

grpc::Status Request::connect(ServerContext* context, const Name* request, PlayerID* response) 
{
    if(clients > 1)
        return  grpc::Status(StatusCode::ALREADY_EXISTS, "There are already 2 players connected!");
    
    clients++;
    response->set_id(clients);

    std::cout << "Connect requested!" << std::endl;
    return  grpc::Status::OK;
}

grpc::Status Request::click(ServerContext* context, const GameInterface::Position* request, Empty* response) 
{
    if(this->game->getGameStatus() == GameStatus::INITIAL)
        return grpc::Status(StatusCode::FAILED_PRECONDITION, "The game has not started yet!");

    Position position;
    position.row = request->x();
    position.column = request->y();

    this->game->selectPosition(position);

    std::cout << "Click requested!" << std::endl;
    return  grpc::Status::OK;
}

grpc::Status Request::getGameStatus(ServerContext* context, const Empty* request, GameInterface::GameStatus* response) 
{
    GameInterface::GameStatus_Status status;
    status = static_cast<GameInterface::GameStatus_Status>(this->game->getGameStatus());

    response->set_status(status);

    std::cout << "GameStatus requested!" << std::endl;
    return  grpc::Status::OK;
}

grpc::Status Request::getHighLightedPositions(ServerContext* context, const Empty* request, ServerWriter<GameInterface::PositionStatus>* writer) 
{
    std::list<PositionStatus> positions = this->game->getBoardStatus().getHighlightedPositions();

    for(auto status : positions)
    {
        GameInterface::PositionStatus *grpc_position_status = new GameInterface::PositionStatus;
        ::GameInterface::Position position;
        ::GameInterface::PositionStatus_Status grpc_status;

        position.set_x(status.getPosition().row);
        position.set_y(status.getPosition().column);
        grpc_status = static_cast<::GameInterface::PositionStatus_Status>(status.getStatus());

        grpc_position_status->set_allocated_position(&position);
        grpc_position_status->set_status(grpc_status);
        writer->Write(*grpc_position_status);
    }

    std::cout << "HighlightedPositions requested!" << std::endl;
    return  grpc::Status::OK;
}

grpc::Status Request::getPlayer1Pieces(ServerContext* context, const Empty* request, ServerWriter<PlayerPieces>* writer) 
{
    std::list<const Piece *> pieces = this->game->getBoardStatus().getPlayer1Pieces();

    for(auto piece : pieces)
    {
        PlayerPieces *player_piece = new PlayerPieces;
        ::GameInterface::Position position;
        ::GameInterface::PlayerPieces_PieceType type;

        position.set_x(piece->getPosition().row);
        position.set_y(piece->getPosition().column);
        type = static_cast<::GameInterface::PlayerPieces_PieceType>(piece->getType());

        player_piece->set_piecetype(type);
        player_piece->set_allocated_position(&position);
        writer->Write(*player_piece);
    }

    std::cout << "Player1Pieces requested!" << std::endl;
    return  grpc::Status::OK;
}

grpc::Status Request::getPlayer2Pieces(ServerContext* context, const Empty* request, ServerWriter<PlayerPieces>* writer) 
{
    std::list<const Piece *> pieces = this->game->getBoardStatus().getPlayer2Pieces();

    for(auto piece : pieces)
    {
        PlayerPieces *player_piece = new PlayerPieces;
        ::GameInterface::Position position;
        ::GameInterface::PlayerPieces_PieceType type;

        position.set_x(piece->getPosition().row);
        position.set_y(piece->getPosition().column);
        type = static_cast<::GameInterface::PlayerPieces_PieceType>(piece->getType());

        player_piece->set_piecetype(type);
        player_piece->set_allocated_position(&position);
        writer->Write(*player_piece);
    }

    std::cout << "Player2Pieces requested!" << std::endl;
    return  grpc::Status::OK;
}
