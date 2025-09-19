#include "game.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>


int random_player_position(int min, int max) {
    return min + rand() % (max - min + 1);
}

void InitializePlayers(Player* players) {
	// Team 1 (White) - left side
	for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
		 // players[i] = (Player){{random_player_position(game->field.x, game->field.x+(game->field.width/2)),random_player_position(game->field.y, game->field.y+(game->field.height))}, {0, 0}, WHITE};
		 players[i] = (Player){{random_player_position(50, 50+(FIELD_WIDTH/2)),random_player_position(50, 50+FIELD_HEIGHT)}, {0, 0}, WHITE};
	}
}

void DrawPlayer(const Player* player, int playerIndex) {
	Color playerColor = player->color;
	DrawCircleV(player->position, PLAYER_SIZE, playerColor);
	DrawText(TextFormat("%d", playerIndex + 1), 
             (int)player->position.x - 4, (int)player->position.y - 4, 10, BLACK);
}


// Draw all players
void DrawAllPlayers(const Player* players) {
    for (int i = 0; i < TOTAL_PLAYERS; i++) {
        DrawPlayer(&players[i], i);
    }
}
