#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define PLAYER_SIZE 8
#define PLAYERS_PER_TEAM 5
#define TOTAL_PLAYERS (PLAYERS_PER_TEAM * 2)

typedef struct Player {
	Vector2 position;
    Vector2 velocity;
    Color color;
    int team;

} Player;

// Forward declaration
typedef struct Game Game;

// Function prototypes
int random_player_position(int min, int max);
void InitializePlayers(Player* players);
// void UpdatePlayerPositions(Player* players, float deltaTime, Rectangle field);
void UpdatePlayerPositions(Player* players, float deltaTime);
void DrawPlayer(const Player* player, int playerIndex);
void DrawAllPlayers(const Player* players);



#endif