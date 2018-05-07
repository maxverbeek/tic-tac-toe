# Tic-Tac-Toe

A simple tictactoe bot, written in C. Compile with `make`. (will run clean, and start the game as well.)
For now, it uses a 3x3 board, but there will be room for expansion.

The player always plays as **X**, and the computer always plays as **O**. Hopefully, the computer should never lose, or at least play tie. It is random whether the player or the computer starts.


## Make commands

| Make command | Description |
| ------------ | ----------- |
| `make`       | Runs `make remakerun`. |
| `make remakerun` | Runs `make clean`, `make build` and if that's succesful it will run the game with `./game`. |
| `make clean` | Removes any `.o` files, and removes the game binary (`game`). |
| `make build` | Compiles the program into the binary `game`. |

## Commandline arguments

Usage: `./game [size]` where size is the dimension of the board (size x size).

This is still a work in progress, so for now size is hardcoded to 3.
