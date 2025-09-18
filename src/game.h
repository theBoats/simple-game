#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FIELD_WIDTH 700
#define FIELD_HEIGHT 500

typedef struct {

	Rectangle field;

} Game;


// Function prototypes
void InitGame(Game* game);
void DrawGame(const Game* game);

#endif