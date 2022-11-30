#include "raylib.h"
#include "Raster.hpp"

#include <algorithm>

void	Raster::drawWireframeTriangle(Vector2 p1, Vector2 p2, Vector2 p3) {
	DrawLineV(p1, p2, BLACK);
	DrawLineV(p2, p3, BLACK);
	DrawLineV(p3, p1, BLACK);
}

void	Raster::drawTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color) {
	// Sort the y
	if (p1.y > p2.y) std::swap(p1, p2);
	if (p2.y > p3.y) std::swap(p2, p3);
	if (p3.y > p1.y) std::swap(p3, p1);

	// A is the greatest segment of the 3
	// B is one of the 2 shorter segments
	int	A_height = p3.y - p1.y;
	int	B_height = p3.y - p2.y + 1;
	// For each y -> find x
	for (int y = p3.y ; y < p2.y ; y++) {
		float	A_scalar = ((float)y - p3.y) / A_height; // Actual y division by max y
		float	B_scalar = ((float)y - p3.y) / B_height;
		Vector2 A = (Vector2){0, (float)y};
		Vector2 B = (Vector2){0, (float)y};
		A.x = p3.x + (p3.x - p1.x) * A_scalar; // Interpolation
		B.x = p3.x + (p3.x - p2.x) * B_scalar;
		DrawLineV(A, B, color);
	}

	B_height = p2.y - p1.y + 1;
	for (int y = p2.y ; y < p1.y ; y++) {
		float	A_scalar = ((float)y - p3.y) / A_height;
		float	B_scalar = ((float)y - p2.y) / B_height;
		Vector2 A = (Vector2){0, (float)y};
		Vector2 B = (Vector2){0, (float)y};
		A.x = p3.x + (p3.x - p1.x) * A_scalar;
		B.x = p2.x + (p2.x - p1.x) * B_scalar;
		DrawLineV(A, B, color);
	}
}
