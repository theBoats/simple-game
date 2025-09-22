#include "raylib.h"
#include "hud.h"
#include "player.h"

void DrawHUD(int ballCarrier, const Player* players) {
	DrawPlayerInfo(ballCarrier, players);
}


// Draw player information
void DrawPlayerInfo(int ballCarrier, const Player* players) {
    if (ballCarrier >= 0) {
        const Player* carrier = &players[ballCarrier];
        DrawText(TextFormat("Ball carrier: %.2d", ballCarrier+1), 10, 30, 20, LIGHTGRAY);
    } else {
    	DrawText(TextFormat("Ball is loose"), 10, 30, 20, LIGHTGRAY);
    }
}