#ifndef RULES_H
#define RULES_H

#include <stdbool.h>
#include "player.h"
#include "raylib.h"

// Function prototypes
bool IsOverTryLine(Vector2 position, Rectangle field, int team);
bool CheckForTry(const Player* players, int ballCarrier, Rectangle field);
void HandleTryScored(const Player* players, int* team1Score, int* team2Score, int ballCarrier);

#endif