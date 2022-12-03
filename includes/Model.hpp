/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:20:31 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 20:08:23 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <algorithm>
#include <vector>

#include "raylib.h"

class r_Model {
	private:
		std::vector<Vector3>			_vertices;
		std::vector<std::vector<int>>	_faces;
			
	public:
		r_Model(const char* filename);
		~r_Model(void);

		int					nFaces(void);
		int					nVertices(void);
		Vector3				getVertice(int n);
		std::vector<int>	getFace(int n);
};

#endif
