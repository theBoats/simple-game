#include "ball.h"
#include "game.h"


// INITIALIZE
// Initialize ball at center field
void InitializeBall(Ball* ball) {
    *ball = (Ball){{400, 300}, {0, 0}, true};
}

// UPDATE
// Update ball possession logic
void UpdateBallPossession(Ball* ball, const Player* players, int ballCarrier) {
    if (ballCarrier >= 0) {
        // Ball follows the player who has it
        ball->position = players[ballCarrier].position;
    } 
}


// DRAW
// Draw ball with appropriate coloring
void DrawBall(const Ball* ball) {
    Color ballColor = ORANGE;
    DrawCircleV(ball->position, BALL_SIZE, ballColor);
}