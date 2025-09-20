#include "ai.h"
#include "raylib.h"

void UpdateLooseBallChase(Player* players, Ball* ball) {
	for (int i=0; i< TOTAL_PLAYERS; i++) {
		// find direction between ball and players
		Vector2 direction = {
			ball->position.x - players[i].position.x,
			ball->position.y - players[i].position.y
		};

		float distance = Vector2Distance(players[i].position, ball->position);

		if (distance > 5) {
			direction = Vector2Normalize(direction);

			float speed = 100;

			players[i].velocity.x = direction.x * speed;
            players[i].velocity.y = direction.y * speed;
		}
	} 
}
