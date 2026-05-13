/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 20:39:23 by tchartie         ###   ########.fr       */
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
std::ostream& operator<<(std::ostream& os, const Vector<K>& v) {
	size_t maxWidth = 0;
	for (size_t i = 0; i < v._size; ++i) {
		std::ostringstream oss;
		oss << v._content[i];
		if (oss.str().size() > maxWidth)
			maxWidth = oss.str().size();
	}

	os << MAGENTA << "Vector:" << std::endl;
	for (size_t i = 0; i < v._size; ++i) {
		std::ostringstream oss;
		oss << v._content[i];
		std::string val = oss.str();

		size_t totalPad = maxWidth - val.size();
		size_t padLeft  = totalPad / 2;
		size_t padRight = totalPad - padLeft;

		os << BLUE << "[" << CYAN << std::string(padLeft, ' ') << val << std::string(padRight, ' ') << BLUE << "]";
		if (i + 1 < v._size)
			os << BLUE << "," << std::endl;
	}
	os << std::endl << std::endl;
	return os;
}
