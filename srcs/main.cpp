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
				Color c = (Color){static_cast<unsigned char>(rand()%255), static_cast<unsigned char>(rand()%255), static_cast<unsigned char>(rand()%255), 255};
				//Raster::drawWireframeTriangle(p[0], p[1], p[2], (Color){255, 255, 255, 255});
				Raster::drawTriangle(p[0], p[1], p[2], c);
			}
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

