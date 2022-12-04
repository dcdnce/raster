#include <map>
#include <string>
#include <sstream>
#include <iterator>

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
				std::vector<int> f = model.getFace(i); 
				for (int j = 0; j < 3; j++) { 
					Vector3 v0 = model.getVertice(f[j]); 
					Vector3 v1 = model.getVertice(f[(j+1)%3]); 
					Vector2	a = (Vector2){(v0.x+1.)*w_half, (v0.y+1.)*h_half};
					Vector2	b = (Vector2){(v1.x+1.)*w_half, (v1.y+1.)*h_half};
					DrawLineV(a, b, RAYWHITE);
				} 
			}
		EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return (0);
}

