#include "main.hpp"
#include "Raster.hpp"

#include "raylib.h"

#include <map>
#include <string>
#include <sstream>
#include <iterator>

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "noiseTerrain");
    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(BLACK);
			Raster::drawTriangle((Vector2){10, 10},	\
					(Vector2){250, 100}, \
					(Vector2){150, 250}, \
					RAYWHITE);
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

