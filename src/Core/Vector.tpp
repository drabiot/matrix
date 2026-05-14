/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:39:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:42:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
Vector<K>::Vector() : _size(1) {
	this->_content = new K[_size];
	this->_content[0] = 0;
}

template<typename K>
Vector<K>::Vector(size_t size) : _size(size), _content(new K[size]()) {}

template<typename K>
Vector<K>::Vector(K *newContent, size_t newSize) : _size(newSize) {
	this->_content = new K[_size];
	for (size_t i = 0; i < this->_size; ++i)
		this->_content[i] = newContent[i];
}

template<typename K>
Vector<K>::Vector(const Vector<K>& other) : _size(other._size) {
    this->_content = new K[_size];
    for (size_t i = 0; i < _size; ++i)
        this->_content[i] = other._content[i];
}

template<typename K>
Vector<K>::Vector(std::initializer_list<K> list) : _size(list.size()) {
	_content = new K[_size];
	size_t i = 0;
	for (const auto& elem : list) {
		_content[i++] = elem;
	}
}

template<typename K>
Vector<K>& Vector<K>::operator=(const Vector<K>& other) {
    if (this == &other)
        return (*this);
    delete[] this->_content;
    this->_size = other._size;
    this->_content = new K[this->_size];
    for (size_t i = 0; i < this->_size; ++i)
        this->_content[i] = other._content[i];
    return (*this);
}

template<typename K>
Vector<K>::~Vector() {
	delete[] this->_content;
}

template<typename K>
size_t  Vector<K>::size(void) const {
	return (this->_size);
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
	os << std::endl;
	return os;
}

template<typename K>
K&  Vector<K>::operator[](size_t i) {
	return (this->_content[i]);
}

template<typename K>
const K&    Vector<K>::operator[](size_t i) const {
	return (this->_content[i]);
}
