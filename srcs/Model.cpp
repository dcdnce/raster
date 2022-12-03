/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:24:05 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 20:10:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include "Model.hpp"

// TODO
// - check if .obj
r_Model::r_Model(const char* filename){
	std::ifstream 		ifs(filename);
	std::string			sLine;
	char				trash;

	if (!ifs.is_open()) {std::cout << "r_Model::r_Model(filename) - couldn't open file" << std::endl; return ;}
	// Parsing
	while (!ifs.eof()) {
		std::getline(ifs, sLine);
		std::istringstream	isLine(sLine.c_str());
		if (!sLine.compare(0, 2, "v ")) {
			Vector3 v;
			isLine >> trash;
			isLine >> v.x >> v.y >> v.z;
			this->_vertices.push_back(v);
		}
		else if (!sLine.compare(0, 2, "f ")) {
			std::vector<int>	f;
			int					id;
			int					itrash;
			isLine >> trash;
			for (int i = 0 ; i < 3 ; i++) {
				isLine >> id >> trash >> itrash >> trash >> itrash;
				f.push_back(id--);
			}
			this->_faces.push_back(f);
		}
	}
	ifs.close();
}

int	r_Model::nFaces(void) {
	return (this->_faces.size());
}

int	r_Model::nVertices(void) {
	return (this->_vertices.size());
}

Vector3	r_Model::getVertice(int n) {
	return (this->_vertices[n]);
}

std::vector<int>	r_Model::getFace(int n) {
	return (this->_faces[n]);
}

r_Model::~r_Model(void){
}
