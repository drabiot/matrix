/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 19:26:50 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector() : _size(1) {
	this->_content = new int[_size];
	this->_content[0] = 0;
}

Vector::Vector(int *newContent, size_t newSize) : _size(newSize) {
	this->_content = new int[_size];
	for (size_t i = 0; i < this->_size; ++i)
		this->_content[i] = newContent[i];
}

Vector::~Vector() {
	delete[] this->_content;
}

void	Vector::displayVector() {
	PRINT CYAN "Vector: [";
	for (size_t i = 0; i < this->_size; ++i) {
		PRINT BLUE AND this->_content[i];
		if (i + 1 < this->_size)
			PRINT CYAN ", ";
	}
	PRINT CYAN "]" CENDL;
}
