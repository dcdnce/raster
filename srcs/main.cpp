#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <cstdlib>

#include "raylib.h"
#define RAYMATH_IMPLEMENTATION
#include "raymath.h"
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

			Vector3	light_dir = {0, 1, 0};
			for (int i = 0; i < model.nFaces(); i++) { 
				std::vector<int> 		f = model.getFace(i); 
				std::vector<Vector2>	screen_p(3); 
				std::vector<Vector3>	world_p(3); 
				for (int j = 0; j < 3; j++) { 
					world_p[j] = model.getVertice(f[j]); 
					screen_p[j].x = (world_p[j].x+1.)*w_half;
					screen_p[j].y = (world_p[j].y+1.)*h_half;
				} 

				Vector3 A = Vector3Subtract(world_p[1], world_p[0]);
				Vector3 B = Vector3Subtract(world_p[2], world_p[0]);
				Vector3	n = Vector3Multiply(B, A);
				n = Vector3Normalize(n);
				float I = Vector3DotProduct(n,light_dir);
				if (I < 0) continue;

				Color c = (Color){(unsigned char)(I*255.), (unsigned char)(I*255.), (unsigned char)(I*255.), 255};
				//Raster::drawTriangle(screen_p[0], screen_p[1], screen_p[2], c);
				Raster::drawWireframeTriangle(screen_p[0], screen_p[1], screen_p[2], (Color){255, 0, 0, 255});
			}
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

