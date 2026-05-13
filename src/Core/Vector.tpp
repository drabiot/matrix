/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 19:58:17 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
Vector<K>::Vector() : _size(1) {
	this->_content = new K[_size];
	this->_content[0] = 0;
}

template<typename K>
Vector<K>::Vector(K *newContent, size_t newSize) : _size(newSize) {
	this->_content = new K[_size];
	for (size_t i = 0; i < this->_size; ++i)
		this->_content[i] = newContent[i];
}

template<typename K>
Vector<K>::~Vector() {
	delete[] this->_content;
}

template<typename K>
void	Vector<K>::displayVector() {
	for (size_t i = 0; i < this->_size; ++i) {
		PRINT BLUE "[" CYAN AND this->_content[i] AND BLUE "]";
		if (i + 1 < this->_size)
			PRINT BLUE "," CENDL;
	}
	NLINE;
	NLINE;
}
