#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstdlib>

#include "raylib.h"
#include "main.hpp"
#include "Raster.hpp"

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "noiseTerrain");
    SetTargetFPS(60);

	// Model loading
	Raster::Model	model("obj/face.obj");

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(BLACK);
			
			/*
			float	w_half = SCREEN_WIDTH / 2.;
			float	h_half = SCREEN_HEIGHT / 2.;
			for (int i = 0; i < model.nFaces(); i++) { 
				std::vector<int> 		f = model.getFace(i); 
				std::vector<Vector2>	p(3); 
				for (int j = 0; j < 3; j++) { 
					Vector3 v = model.getVertice(f[j]); 
					p[j].x = (v.x+1.)*w_half;
					p[j].y = (v.y+1.)*h_half;
				} 
				//Raster::drawWireframeTriangle(p[0], p[1], p[2], (Color){255, 255, 255, 255});
				Raster::drawTriangle(p[0], p[1], p[2], (Color){255, 255, 255, 255});
			}
		*/	
			
			
			Raster::drawTriangle((Vector2){10, 10},	\
					(Vector2){250, 100}, \
					(Vector2){150, 250}, \
					RAYWHITE);
			Raster::drawTriangle((Vector2){100, 400},	\
					(Vector2){50, 300}, \
					(Vector2){350, 350}, \
					RAYWHITE);
			
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

