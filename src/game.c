#include "game.h"
#include "raylib.h"
#include "field.h"
#include "ball.h"
#include "player.h"

void InitGame(Game* game) {

	// Initialize the field
	game->field = (Rectangle){50, 50, FIELD_WIDTH, FIELD_HEIGHT}; // xpos: top left corner, ypos: top lefet corner, width, height

	// Initialize players
	InitializePlayers(game->players);

	// Initialize the ball
	InitializeBall(&game->ball);
}


// Draw the game
void DrawGame(const Game* game) {
	BeginDrawing();
	ClearBackground(DARKGREEN);

	// Draw field
    DrawField(game->field);
    DrawGoalLines(game->field);
    DrawCenterLine(game->field);
	DrawTryZones(game->field);
	DrawFortyTwenties(game->field);

	// Draw players
	DrawAllPlayers(game->players);

	// Draw ball
	DrawBall(&game->ball);


	EndDrawing();
}