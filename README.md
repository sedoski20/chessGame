# ChessGame
Didactic project created to test and implement C++ in a Object Oriented approach and following the Clear Code rules.

![] doc/main.PNG

* Add image off the game
* Add badges


## Contents

* Introduction
* Setting Up
* How to contribute
* Documentation

## Introduction

ChessGame is a C++ project that enables the user to play Chess in a virtual enviroment.
The engine use STL's functions and all the logic was created during the development. 
We use Qt and QML for the GUI, which allow us to create some great effects and provide a better user experience.

Learning and understanding software design and development is the main goal of this project. It includes many concepts such as object oriented programming, C++, Qt, CMake, software Architecture, UML and software documentation. Writing this simple README also has a value for the learning process as a Software Engineer.

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

There are 3 important situations:

* **Check:** when the king is one unsafe position and can be captured.
* **Check Mate:** When the king certaily will be captured on the next turn, so the game has finished
* **Pawn promoting:** when a pawn reaches the opposite border of the board it can be promoted to any other piece.
* **Castle:** if there any pieces between the king and the rook, and it is the very first move for both, they can change the position each other. 

For more game details and rules: https://www.chess.com/learn-how-to-play-chess.

### Gameplay

The gameplay is simple, the two players must use the same device and the interaction is done by mouse clicks. The player 1 starts with the bottom pieces (whites). 

* By clicking in one piece, it will be selected and possible movements will be highlighted on the board. With a second click, if the position is one of the possible movements, it is possible to move the selected piece,  otherwise the piece will be unselected. 

* After a movement the turn will be updated to the next player.

* When the one of the possible movement is an attack, the highlighted color will be red and after the movement the opponent piece will be captured.

* When the king of the current player is in check and it isn't the selected piece its position will be red highlighted as well.

* When the player is in check mate the game ends and a message is shown to inform the winner.

## Project Requirements

This sections aims to list the main requirements of this project.

* The game must have a board with 64 positions.
* The game board must have 2 different colors.
* The game must have 2 players.
* The player must start with 16 Pieces.
* The player pieces must be arranged as follow: 16 paws, 2 rooks, 2 knights, 2 bishops, 1 queen and 1  king.
* The pieces must have 2 colors.
* The player must select a piece by cicking on it position.
* The player must move a piece by clicking in a valid destination.
* The piece must be moved only when it was selected previously.
* The game must highlight the possible movements when a piece is selected.
* The game must highlight the attacks.
* The game must highlight the king when it is in check.
* The game must show a message when the game finishes.









