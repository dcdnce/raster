#include "main.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <map>
#include <string>
#include <sstream>
#include <iterator>

static void	r_drawWireframeTriangle(Vector2 p1, Vector2 p2, Vector2 p3) {
	DrawLineV(p1, p2, BLACK);
	DrawLineV(p2, p3, BLACK);
	DrawLineV(p3, p1, BLACK);
}

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "noiseTerrain");
    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			r_drawWireframeTriangle((Vector2){10, 10},	\
					(Vector2){250, 100}, \
					(Vector2){150, 250});
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

