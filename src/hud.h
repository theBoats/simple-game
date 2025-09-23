#ifndef HUD_H
#define HUD_H

#include "raylib.h"
#include "player.h"

// Function prototypes

// void DrawHUD(int team1Score, int team2Score, int gameState, int playerWithBall, 
//              int passReceiver, int tackler, int dummyHalf, const Player* players);


void DrawHUD();
void DrawPlayerInfo(int playerWithBall, const Player* players);
void DrawScore(int team1Score, int team2Score);

#endif