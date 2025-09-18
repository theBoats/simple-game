#

## 2025-09-18 

Setup minimal compilable game. 
src\main.c
src\game.c
src\game.h
src\field.c
src\field.h

main.c is minimal and has the most higher order code, initialzing the game and the game loop, updating and drawing
game.c contains the game state. There is a struct called Game which contains the information and is the memory passed as a pointer to most functions
field.c contains the information for drawing the field. The field itself is a Rectangle inside of game (game->field)