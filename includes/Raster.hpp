#ifndef RASTER_HPP
#define RASTER_HPP

#include "raylib.h"

namespace Raster {
	void	drawWireframeTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color);
	void	drawTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color);
}

#endif
