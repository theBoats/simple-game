#ifndef AI_H
#define AI_H

#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "ball.h"

// Forward declarations
typedef struct Game Game;

// Function prototypes
void UpdateLooseBallChase(Player* players, Game* game, Ball* ball);
void UpdateBallCarrier(Player* players, int ballCarrier, Rectangle field);



#endif