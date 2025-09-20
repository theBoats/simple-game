#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "ball.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FIELD_WIDTH 700
#define FIELD_HEIGHT 500

typedef struct Game {
	Player players[TOTAL_PLAYERS];
	Rectangle field;
	Ball ball;

	// Game state variables
    float stateTimer;

} Game;


// Function prototypes
void InitGame(Game* game);
void DrawGame(const Game* game);
void UpdateGame(Game* game, float deltaTime);

#endif