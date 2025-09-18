#include "raylib.h"
#include "game.h"

int main(void) {

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