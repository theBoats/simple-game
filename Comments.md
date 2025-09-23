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


## 2025-09-19

Found some nuance in the following. Why is one called with **game** and the other **&game** ? 

Prototypes:
void InitializeBall(Ball* ball);
void InitializePlayers(Player* players);

Calls:
// Initialize players
    InitializePlayers(game->players);
    
    // Initialize ball
    InitializeBall(&game->ball);


Answer, game->ball is a struct not a pointer (-> dereferences a pointer). In this case the function wants a pointer as argument so we pass the address of ball with &game->ball.
game->players is an **array**. **In C when you pass an array to a function it automatically decays to a pointer to the first element in the array** (&game->players[0]). The function InitializePlayers wants a pointer as an argument so passing in the array already gives it a pointer. Therefore you do not need &. 

For some functions you can pass elements of the game struct by value. For instance ballCarrier in an int. If a function just needs to read the value you can pass game->ballCarrier (value) instead of &game->ballCarrier (pointer to ballCarrier).

### Players
The players array is defined in the struct Game. It is an array of struct Player.

Ball posession is defined in ball.c

### Structs
Learned that structs can be named or anonymous. e.g.

Anonymous:
typedef struct {

} Game;

Named:
typedef struct Game {

} Game;


# PLAN




- normal play function


- defender logic
	- move up slowly as a line
	- within radius of ball carrier increase speed

