#include <map>
#include <string>
#include <sstream>
#include <iterator>

#include "main.hpp"
#include "Raster.hpp"
#include "Model.hpp"
#include "raylib.h"


int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "noiseTerrain");
    SetTargetFPS(60);

	// Model loading
	r_Model	model("obj/face.obj");

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(BLACK);
			for (int i = 0; i < model.nFaces(); i++) { 
				std::vector<int> f = model.getFace(i); 
				for (int j = 0; j < 3; j++) { 
					Vector3 v0 = model.getVertice(f[j]); 
					Vector3 v1 = model.getVertice(f[(j+1)%3]); 
					Vector2	a;
					Vector2	b;
					a.x = (v0.x+1.)*SCREEN_WIDTH/2.; 
					a.y = SCREEN_HEIGHT - (v0.y+1.)*SCREEN_HEIGHT/2.; 
					b.x = (v1.x+1.)*SCREEN_WIDTH/2.; 
					b.y = SCREEN_HEIGHT - (v1.y+1.)*SCREEN_HEIGHT/2.; 
					DrawLineV(a, b, RAYWHITE);
				} 
			}

			/*
			Raster::drawTriangle((Vector2){10, 10},	\
					(Vector2){250, 100}, \
					(Vector2){150, 250}, \
					RAYWHITE);
			Raster::drawTriangle((Vector2){100, 400},	\
					(Vector2){50, 300}, \
					(Vector2){350, 350}, \
					RAYWHITE);
			*/

		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

