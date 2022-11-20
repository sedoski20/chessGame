# ChessGame
Didactic project created to test and implement C++ in a Object Oriented approach and following the Clear Code rules.

[![CMake](https://github.com/sedoski20/chessGame/actions/workflows/build.yml/badge.svg)](https://github.com/sedoski20/chessGame/actions/workflows/build.yml) [![Microsoft C++ Code Analysis](https://github.com/sedoski20/chessGame/actions/workflows/msvc.yml/badge.svg)](https://github.com/sedoski20/chessGame/actions/workflows/msvc.yml)

![](/doc/main.PNG)

## Contents

* Introduction
* The Game
* Project Requirements
* Project Architecture
* Setting Up
* How to contribute
  

## Introduction

ChessGame is a C++ project that enables the user to play Chess in a virtual enviroment.
The engine use STL's functions and all the logic was created during the development. 
We use Qt and QML for the GUI, which allow us to create some great effects and provide a better user experience.

Learning the main goal of this project, which includes many concepts such as object oriented programming, C++, Qt, CMake, software Architecture, UML and software documentation. Writing this simple README has a value for the learning process as well.

## The Game

The game follow the rules of the well known chess. There are a board, two players and 32 pieces (16 whites and 16 blacks).

**Each player has the follow pieces arrangement:**

* 8 Pawns
* 2 Bishops
* 2 Rooks
* 2 Knights
* 1 Queen 
* 1 King

And each piece has your own rule to move on the board.

There are 4 special situations:

* **Check:** when the king is one unsafe position and can be captured.
* **Check Mate:** When the king certaily will be captured on the next turn, so the game has finished
* **Pawn promoting:** when a pawn reaches the opposite border of the board it can be promoted to any other piece.
* **Castle:** if there any pieces between the king and the rook, and it is the very first move for both, they can change the position each other. 

For more game details and rules: https://www.chess.com/learn-how-to-play-chess.

### Gameplay

The gameplay is simple, the  players can use the same device or play remotly. The interaction is done by mouse clicks.

![](https://i.giphy.com/media/71wW6cZUvQyMdet34g/giphy.gif)

* By clicking in one piece, it will be selected and possible movements will be highlighted on the board. 
  
* With a second click, if the position is valid, the selected piece can be moved,  otherwise the piece will be unselected. 

* When one of the possible movement is an attack, the highlighted color will be red and after the movement the opponent piece will be captured.

* When the king of the current player is in check and it isn't the selected piece, its position will be red highlighted as well.

* When the player is in check mate the game ends and a message is shown to inform the winner.
  
* After a movement the turn will be updated to the next player.

## Project Requirements

* The game must follow the rules of a conventional chess game.
* The player must be able to select a piece by cicking on it position.
* The player must be able to move a piece by clicking in a valid destination.
* The piece must be moved only when it was selected previously.
* The game interface must highlight the possible movements when a piece is selected.
* The game interface must highlight the attacks.
* The game interface must highlight the king when it is in check.
* The game interface must show a message when the game finishes.

### Project Architecture

The project architecture illustraded in the diagram below, shows the modules of the game and the relation among them. The server-client pattern is used to ensure the multiplayer mode remotly. When the user wants to play chess with a friend in different devices, the server side handle the connections, and execute the game engine. Otherwise, when the user wants to play offline, the client side create an instance of the game engine and runs it internally.

In the online mode, the connection between the devices is done by the gRPC framework, which create the sockets, manage the requests from each side and handle refuse errors. If you want to get more details of gRPC way of working please refer to https://grpc.io/.

The client side is responsible to render the graphical interface, this is done by the Qt framework. The graphics were created using QtQuick module (QML), which enable us to get complex effects and animations easyier than the most C++ GUI frameworks.

Finally, an executable responsible for testing the game engine is part of the architecture as well. Google Testing framework was used here to unit testing and mocking. The testcases provided ensures that the game logic's is working as expected.

![](/doc/component_diagram.png)

## Setting Up

First of all you need to clone this repository into your file system, make sure to include the **submodules** adding the `--recurse-submodules -j8` parameter in the command.

```git clone --recurse-submodules -j8 https://github.com/sedoski20/chessGame```

### Prerequisits

* CMake 
* C++ Compiler 
* Qt 5.12 or higher 
* Protobuf
* gRPC

### Building the Project

Go to the directory where you have clone the repository. Run the following commands:

```bash
$ cd chessgame
$ cmake -S ./ -B ./build
$ cmake --build ./build --config Release
```

After building the project, the artifacts will be available as follow:

```bash
./build/bin/
├── game
│   └── ChessGame_tst
├── server
│   └── ChessGame_server
└── client
    └── ChessGame_client
```

Another files are built and linked during the building, but the just these 3 executables are relevant to the user.

### Running the game

You can run the game in different ways according to the mode you want to play. For online mode you will need to run both the server and the client application. If you want to play in just one screen you will need to run only the client application.

* Online Mode

```bash
$ cd chessgame/build/bin/server
$ ./ChessGame_server

$ cd chessgame/build/bin/client
$ ./ChessGame_client
```

* Offline Mode

```bash
$ cd chessgame/build/bin/client
$ ./ChessGame_client
```

### Running the tests

The game engine can be tested using the testing application. This uses the Google testing framework to create test reports, improve the testing code and provide mocking classes. To get the result of the unit tests, you just need to run the test application and a summary will be printed on the terminal. 

If you added some feature to the project, you will need to update the unit tests to cover this feature as well.

```bash
$ cd chessgame/build/bin/game
$ ./ChessGame_tst
```






