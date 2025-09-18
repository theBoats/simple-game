#include "raylib.h"
#include "field.h"

void DrawField(Rectangle field) {
	// cast as int because Rectangle struct has type float
	DrawRectangleLines((int)field.x, (int)field.y, (int)field.width, (int)field.height, WHITE);
}

void DrawGoalLines(Rectangle field) {
	// Left goal line (Team 1's goal)
    DrawLine((int)field.x + 50, (int)field.y, 
             (int)field.x + 50, (int)(field.y + field.height), WHITE);
    
    // Right goal line (Team 2's goal)
    DrawLine((int)(field.x + field.width - 50), (int)field.y, 
             (int)(field.x + field.width - 50), (int)(field.y + field.height), WHITE);
}

// Draw center line
void DrawCenterLine(Rectangle field) {
    DrawLine((int)(field.x + field.width/2), (int)field.y, 
             (int)(field.x + field.width/2), (int)(field.y + field.height), WHITE);
}

// Draw try zones (in-goal areas)
void DrawTryZones(Rectangle field) {
    // Left try zone
    Rectangle leftTryZone = {
        field.x,
        field.y,
        50,
        field.height
    };
    DrawRectangleLines((int)leftTryZone.x, (int)leftTryZone.y, 
                      (int)leftTryZone.width, (int)leftTryZone.height, 
                      ColorAlpha(YELLOW, 0.3f));
    
    // Right try zone
    Rectangle rightTryZone = {
        field.x + field.width - 50,
        field.y,
        50,
        field.height
    };
    DrawRectangleLines((int)rightTryZone.x, (int)rightTryZone.y, 
                      (int)rightTryZone.width, (int)rightTryZone.height, 
                      ColorAlpha(YELLOW, 0.3f));
}

// Draw forty and twenty metre lines
void DrawFortyTwenties(Rectangle field) {
	// 60 pixels = 10 metres

	// Left 20 metre line
    DrawLine((int)field.x + 170, (int)field.y, 
             (int)field.x + 170, (int)(field.y + field.height), ColorAlpha(MAROON, 0.3f));

    // Left 40 metre line
    DrawLine((int)field.x + 290, (int)field.y, 
             (int)field.x + 290, (int)(field.y + field.height), ColorAlpha(MAROON, 0.3f));

    // Right 40 metre line
    DrawLine((int)field.x + 410, (int)field.y, 
             (int)field.x + 410, (int)(field.y + field.height), ColorAlpha(MAROON, 0.3f));

    // Right 20 metre line
    DrawLine((int)field.x + 530, (int)field.y, 
             (int)field.x + 530, (int)(field.y + field.height), ColorAlpha(MAROON, 0.3f));
}
