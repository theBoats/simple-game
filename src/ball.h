#ifndef BALL_H
#define BALL_H

#include "raylib.h"

#define BALL_SIZE 4

// Forward declaration
typedef struct Player Player;
typedef struct Game Game;

typedef struct {
	Vector2 position;
	Vector2 velocity;
	bool isLoose;
} Ball;

// Function prototypes
void InitializeBall(Ball* ball);
void UpdateBallPossession(Ball* ball, const Player* players, int ballCarrier);
void DrawBall(const Ball* ball);

#endif



