/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:41:16 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 15:13:33 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
Matrix<K>::Matrix() : _rows(1), _cols(1) {
	this->_content = new K*[_rows];
	this->_content[0] = new K[_cols];
	this->_content[0][0] = 0;
}

template<typename K>
Matrix<K>::Matrix(size_t size) : _rows(size), _cols(size) {
	this->_content = new K*[_rows];
	for (size_t i = 0; i < this->_rows; ++i) {
		this->_content[i] = new K[_cols];
		for (size_t j = 0; j < this->_cols; ++j) {
			i == j ? this->_content[i][j] = 1 : this->_content[i][j] = 0;
		}
	}
}

template<typename K>
Matrix<K>::Matrix(size_t newRows, size_t newCols) : _rows(newRows), _cols(newCols) {
	this->_content = new K*[_rows];
	for (size_t i = 0; i < this->_rows; ++i) {
		this->_content[i] = new K[_cols];
		for (size_t j = 0; j < this->_cols; ++j)
			this->_content[i][j] = 0;
	}
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
Matrix<K>::Matrix(const Matrix<K>& other) : _rows(other._rows), _cols(other._cols) {
	this->_content = new K*[this->_rows];
	for (size_t i = 0; i < this->_rows; ++i) {
		this->_content[i] = new K[this->_cols];
		for (size_t j = 0; j < this->_cols; ++j)
			this->_content[i][j] = other._content[i][j];
	}
}

template<typename K>
Matrix<K>::Matrix(std::initializer_list<std::initializer_list<K>> list) {
	this->_rows = list.size();
	this->_cols = (this->_rows > 0) ? list.begin()->size() : 0;

	this->_content = new K*[_rows];

	size_t i = 0;
	for (const auto& row_list : list) {
		this->_content[i] = new K[this->_cols];
		std::copy(row_list.begin(), row_list.end(), this->_content[i]);
		i++;
	}
}

template<typename K>
Matrix<K>& Matrix<K>::operator=(const Matrix<K>& other) {
	if (this == &other)
		return (*this);
	for (size_t i = 0; i < this->_rows; ++i)
		delete[] this->_content[i];
	delete[] this->_content;
	this->_rows = other._rows;
	this->_cols = other._cols;
	this->_content = new K*[this->_rows];
	for (size_t i = 0; i < this->_rows; ++i) {
		this->_content[i] = new K[this->_cols];
		for (size_t j = 0; j < this->_cols; ++j)
			this->_content[i][j] = other._content[i][j];
	}
	return (*this);
}

template<typename K>
Matrix<K>::~Matrix() {
	for (size_t i = 0; i < this->_rows; ++i)
		delete[] this->_content[i];
	delete[] this->_content;
}

template<typename K>
bool	Matrix<K>::isSquare(void) {
	if (this->_rows == this->_cols)
		return (true);
	return (false);
}

template<typename K>
size_t	Matrix<K>::getRows(void) const {
	return (this->_rows);
}

template<typename K>
size_t	Matrix<K>::getCols(void) const {
	return (this->_cols);
}

template<typename K>
K**	Matrix<K>::getContent(void) const {
	return (this->_content);
}

template<typename K>
void	Matrix<K>::displayMatrix(void) {
	for (size_t i = 0; i < this->_rows; ++i) {
		for (size_t j = 0; j < this->_cols; ++j) {
			PRINT CYAN AND this->_content[i][j];
			if (j + 1 < this->_cols)
				PRINT BLUE ", ";
		}
		if (i + 1 < this->_rows)
				PRINT BLUE ", " CENDL;
	}
	NLINE;
}

template<typename K>
K*	Matrix<K>::operator[](size_t i) {
	return (this->_content[i]);
}

template<typename K>
const K*	Matrix<K>::operator[](size_t i) const {
	return (this->_content[i]);
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
