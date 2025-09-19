#include "ball.h"

// Initialize ball at center field
void InitializeBall(Ball* ball) {
    *ball = (Ball){{400, 300}, {0, 0}};
}

// Draw ball with appropriate coloring
void DrawBall(const Ball* ball) {
    Color ballColor = ORANGE;
    DrawCircleV(ball->position, BALL_SIZE, ballColor);
}