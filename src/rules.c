#include "rules.h"

// Check if position is over the try line
bool IsOverTryLine(Vector2 position, Rectangle field, int team) {
    float leftGoalLine = field.x + 50;
    float rightGoalLine = field.x + field.width - 50;
    
    if (team == 0) {
        // Team 1 attacks right
        return position.x > rightGoalLine;
    } else {
        // Team 2 attacks left
        return position.x < leftGoalLine;
    }
}

// Check if a try has been scored
bool CheckForTry(const Player* players, int ballCarrier, Rectangle field) {
    if (ballCarrier < 0) return false;
    
    Vector2 ballPos = players[ballCarrier].position;
    float leftGoalLine = field.x + 50;
    float rightGoalLine = field.x + field.width - 50;
    
    // Team 1
    if (players[ballCarrier].team == 0 && ballPos.x > rightGoalLine) {
    	return true;
    } else if (players[ballCarrier].team == 1 && ballPos.x < leftGoalLine) {
    	return true;
    } else {
    	return false;
    }
}


void HandleTryScored(const Player* players, int* team1Score, int* team2Score, int ballCarrier) {
    if (players[ballCarrier].team == 0) {
        *team1Score += 4; // 4 points for a try
    } else {
        *team2Score += 4;
    }
}