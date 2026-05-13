/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:41:16 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 21:09:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
Matrix<K>::Matrix() : _rows(1), _cols(1) {
	this->_content = new K*[_rows];
	this->_content[0] = new K[_cols];
	this->_content[0][0] = 0;
}

template<typename K>
Matrix<K>::Matrix(K **newContent, size_t newRows, size_t newCols) : _rows(newRows), _cols(newCols) {
	this->_content = new K*[_rows];
	for (size_t i = 0; i < this->_rows; ++i) {
		this->_content[i] = new K[_cols];
		for (size_t j = 0; j < this->_cols; ++j)
			this->_content[i][j] = newContent[i][j];
	}
}

template<typename K>
Matrix<K>::~Matrix() {
	for (size_t i = 0; i < this->_rows; ++i)
		delete[] this->_content[i];
	delete[] this->_content;
}

template<typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& m) {
	size_t maxWidth = 0;
	for (size_t i = 0; i < m._rows; ++i) {
		for (size_t j = 0; j < m._cols; ++j) {
			std::ostringstream oss;
			oss << m._content[i][j];
			if (oss.str().size() > maxWidth)
				maxWidth = oss.str().size();
		}
	}

	os << RED << "Matrix:" << std::endl;
	for (size_t i = 0; i < m._rows; ++i) {
		os << GREEN << "[";
		for (size_t j = 0; j < m._cols; ++j) {
			std::ostringstream oss;
			oss << m._content[i][j];
			std::string val = oss.str();

			size_t totalPad = maxWidth - val.size();
			size_t padLeft  = totalPad / 2;
			size_t padRight = totalPad - padLeft;

			os << YELLOW << std::string(padLeft, ' ') << val << std::string(padRight, ' ');
			if (j + 1 < m._cols)
				os << GREEN << ", ";
		}
		os << GREEN << "]" << std::endl;
	}
	os << std::endl;
	return os;
}
