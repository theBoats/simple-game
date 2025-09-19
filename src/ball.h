#ifndef BALL_H
#define BALL_H

#include "raylib.h"

#define BALL_SIZE 4

typedef struct {
	Vector2 position;
	Vector2 velocity;
} Ball;

// Function prototypes
void InitializeBall(Ball* ball);
void DrawBall(const Ball* ball);

#endif



