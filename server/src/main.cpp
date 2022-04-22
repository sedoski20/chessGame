#include <iostream>
#include "request.h"
#include "game.h"

void runServer()
{
    std::string server_address = "0.0.0.0:50051";

    Game *game = new Game();
    Request request(game);
    
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&request);
    auto server = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main()
{
    runServer();
}

