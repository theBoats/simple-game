#include "raylib.h"
#include "game.h"
#include <time.h>
#include <stdlib.h>

int main(void) {

	// seed RNG once
	srand(time(NULL));   

	// Initialize window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simplified game - no vibe code");
	SetTargetFPS(60);

	// Init game here
	Game game;
	InitGame(&game);

	// Game loop
	while(!WindowShouldClose()) {
		float deltaTime = GetFrameTime();

		// Update

		// Draw
		DrawGame(&game);
	}

	CloseWindow();
	return 0;
}