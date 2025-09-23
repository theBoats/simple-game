#include "ai.h"
#include "raylib.h"
#include "game.h"

void UpdateLooseBallChase(Player* players, Game* game, Ball* ball) {
	if (ball->isLoose == true) {
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
			} else {
				// player is very close to ball and should take posession
				game->ballCarrier = i;
				ball->isLoose = false;
			}
		}
	} 
}

void UpdateBallCarrier(Player* players, int ballCarrier, Rectangle field) {
	if (ballCarrier < 0) return;

	Player* carrier = &players[ballCarrier];

	// Determine which try line we're attacking
    float targetX;
    if (carrier->team == 0) {
        targetX = field.x + field.width - 40;
    } else {
        targetX = field.x + 40;
    }

    // Primary direction: toward try line
    Vector2 primaryDirection = {targetX - carrier->position.x, 0};
    primaryDirection = Vector2Normalize(primaryDirection);

    // put additional logic in here to avoid defenders, etc

    float speed = 120;
    carrier->velocity.x = primaryDirection.x * speed;
    carrier->velocity.y = primaryDirection.y * speed;

}