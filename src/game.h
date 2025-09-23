#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "ball.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FIELD_WIDTH 700
#define FIELD_HEIGHT 500

typedef enum GameState {

	NORMAL_PLAY, // game in progress
	LOOSE_BALL // implement ball chase logic

} GameState;

typedef struct Game {
	Player players[TOTAL_PLAYERS];
	Rectangle field;
	Ball ball;
	int ballCarrier;
	int team1score;
	int team2score;

	// Game state variables
    float stateTimer;

} Game;


// Function prototypes
void InitGame(Game* game);
void DrawGame(const Game* game);
void UpdateGame(Game* game, float deltaTime);
static void UpdateNormalPlay(Game* game, float deltaTime);
void ResetGame(Game* game);

#endif