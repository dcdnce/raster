#ifndef RASTER_HPP
#define RASTER_HPP

#include <algorithm>
#include <vector>
#include "raylib.h"

namespace Raster {
	class Model {
		private:
			std::vector<Vector3>			_vertices;
			std::vector<std::vector<int>>	_faces;
		public:
			Model(const char* filename);
			~Model(void);
			int					nFaces(void);
			int					nVertices(void);
			Vector3				getVertice(int n);
			std::vector<int>	getFace(int n);
	};

	void	drawWireframeTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color);
	void	drawTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Color color);
}

#endif
