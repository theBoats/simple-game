#include "game.h"
#include "player.h"
#include "raylib.h"
#include <stdlib.h>


int random_player_position(int min, int max) {
    return min + rand() % (max - min + 1);
}


// INITIALIZE
void InitializePlayers(Player* players) {

	/*
	Initializes players within their own half. Can be within in-goal area. Padding of 5 pixels from centre line and touch lines.
	*/

	// Team 1 (White) - left side
	for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
		 players[i] = (Player){{random_player_position(50, 50+(FIELD_WIDTH/2)-5),random_player_position(50+5, 50+FIELD_HEIGHT)-5}, {0, 0}, WHITE};
	}

	// Team 2 (Grey) - right side
	for (int i = 0; i < PLAYERS_PER_TEAM; i++) {
		 players[i+PLAYERS_PER_TEAM] = (Player){{random_player_position(50+(FIELD_WIDTH/2)+5, FIELD_WIDTH),random_player_position(50+5, 50+FIELD_HEIGHT-5)}, {0, 0}, GRAY};
	}
}


// UPDATE
// void UpdatePlayerPositions(Player* players, float deltaTime, Rectangle field) {
void UpdatePlayerPositions(Player* players, float deltaTime) {

	for (int i = 0; i < TOTAL_PLAYERS; i++) {
        players[i].position.x += players[i].velocity.x * deltaTime;
        players[i].position.y += players[i].velocity.y * deltaTime;
        
        // // Keep players within field bounds
        // if (players[i].position.x < field.x + PLAYER_SIZE) 
        //     players[i].position.x = field.x + PLAYER_SIZE;
        // if (players[i].position.x > field.x + field.width - PLAYER_SIZE) 
        //     players[i].position.x = field.x + field.width - PLAYER_SIZE;
        // if (players[i].position.y < field.y + PLAYER_SIZE) 
        //     players[i].position.y = field.y + PLAYER_SIZE;
        // if (players[i].position.y > field.y + field.height - PLAYER_SIZE) 
        //     players[i].position.y = field.y + field.height - PLAYER_SIZE;
    }
}

// DRAW
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
