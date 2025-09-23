#include "game.h"
#include "raylib.h"
#include "field.h"
#include "ball.h"
#include "player.h"
#include "ai.h"
#include "hud.h"
#include "rules.h"

void InitGame(Game* game) {

	// Initialize the field
	game->field = (Rectangle){50, 50, FIELD_WIDTH, FIELD_HEIGHT}; // xpos: top left corner, ypos: top lefet corner, width, height
	game->ballCarrier = -1; // ball is not posessed at the start of the game
	game->team1score = 0;
	game->team2score = 0;

	// Initialize players
	InitializePlayers(game->players);

	// Initialize the ball
	InitializeBall(&game->ball);
}


// TEMP!!
void UpdateGame(Game* game, float deltaTime) {
	game->stateTimer += deltaTime;

	/*

	Below is eventually split into different game states by an enum

	e.g.

	switch (game->state) {
		case NORMAL_PLAY:
			UpdateNormalPlay(game, deltaTime);
		case TACKLE_MADE:
			UpdateTackleMade(game, deltaTime);
	}

	*/

	UpdateNormalPlay(game, deltaTime);
	// UpdateLooseBallChase(game->players, game, &game->ball);
	UpdatePlayerPositions(game->players, deltaTime);
	UpdateBallPossession(&game->ball, game->players, game->ballCarrier);
}


// UPDATE THE GAME

static void UpdateNormalPlay(Game* game, float deltaTime) {
	if (game->ballCarrier < 0) {
		UpdateLooseBallChase(game->players, game, &game->ball);
	} else {
		UpdateBallCarrier(game->players, game->ballCarrier, game->field); // implement in ai.c

		// Check for scoring
		if (CheckForTry(game->players, game->ballCarrier, game->field)) {
				HandleTryScored(game->players, &game->team1score, &game->team2score, game->ballCarrier);
		}
	}
}

// static void UpdateNormalPlay(Game* game, float deltaTime) {
//     // Handle ball possession
//     if (game->ballCarrier < 0 && game->ball.isLoose) {
//         UpdateLooseBallChase(game->players, game, &game->ball);
//     } else if (game->ballCarrier >= 0) {
//         // Smart AI when someone has the ball
//         UpdateBallCarrier(game->players, game->playerWithBall, game->field, &game->ball, (int*)&game->state, deltaTime);
        
//         // Only update other players if we're still in normal play
//         if (game->state == NORMAL_PLAY) {
//             UpdateSupportPlayers(game->players, game->playerWithBall, game->field, deltaTime);
//             UpdateDefenders(game->players, game->playerWithBall, game->field, deltaTime);
            
//             // Check for tackles
//             game->tackler = CheckForTackle(game->players, game->playerWithBall);
//             if (game->tackler >= 0) {
//                 // Tackle made!
//                 game->state = TACKLE_MADE;
//                 game->tacklePosition = game->players[game->playerWithBall].position;
//                 game->stateTimer = 0;
                
//                 // Stop all players
//                 for (int i = 0; i < TOTAL_PLAYERS; i++) {
//                     game->players[i].velocity = (Vector2){0, 0};
//                 }
//             }
//         }
//     }
    
//     // Update positions and handle possession
//     if (game->state == NORMAL_PLAY) {
//         UpdatePlayerPositions(game->players, deltaTime, game->field);
//         UpdateBallPossession(&game->ball, game->players, &game->playerWithBall);
        
//         // Check for tries
//         float goalLineX;
//         if (CheckForTry(game->players, game->playerWithBall, game->field, &goalLineX)) {
//             HandleTryScored(&game->team1Score, &game->team2Score, game->playerWithBall);
            
//             // Reset for kickoff by other team
//             int newKickingTeam = IsTeam1Player(game->playerWithBall) ? PLAYERS_PER_TEAM : 0;
//             ResetForKickoff(game, newKickingTeam);
//         }
//     }
// }



// Draw the game
void DrawGame(const Game* game) {
	BeginDrawing();
	ClearBackground(DARKGREEN);

	// Draw field
    DrawField(game->field);
    DrawGoalLines(game->field);
    DrawCenterLine(game->field);
	DrawTryZones(game->field);
	DrawFortyTwenties(game->field);

	// Draw players
	DrawAllPlayers(game->players);

	// Draw ball
	DrawBall(&game->ball);

	// Draw HUD
	DrawHUD(game->ballCarrier, game->players, game->team1score, game->team2score);


	EndDrawing();
}