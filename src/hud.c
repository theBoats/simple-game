#include "raylib.h"
#include "hud.h"
#include "player.h"

void DrawHUD(int ballCarrier, const Player* players, int team1score, int team2score) {
	DrawPlayerInfo(ballCarrier, players);
	DrawScore(team1score, team2score);
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

// Draw current score
void DrawScore(int team1Score, int team2Score) {
    DrawText(TextFormat("Score: %d - %d", team1Score, team2Score), 300, 35, 16, YELLOW);
}