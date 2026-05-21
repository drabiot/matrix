/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:04:26 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/21 18:38:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static Matrix<K>	submatrix(Matrix<K> mat, size_t skip_row, size_t skip_col) {
	size_t new_rows = mat.getRows() - 1;
	size_t new_cols = mat.getCols() - 1;

	K **sub = new K*[new_rows];
	for (size_t i = 0; i < new_rows; ++i)
		sub[i] = new K[new_cols];

	size_t ri = 0;
	for (size_t row = 0; row < mat.getRows(); ++row) {
		if (row == skip_row)
			continue;
		size_t ci = 0;
		for (size_t col = 0; col < mat.getCols(); ++col) {
			if (col == skip_col)
				continue;
			sub[ri][ci++] = mat.getContent()[row][col];
		}
		++ri;
	}

	Matrix<K> result(sub, new_rows, new_cols);
	for (size_t i = 0; i < new_rows; ++i)
		delete[] sub[i];
	delete[] sub;
	return (result);
}


// Time complexity:  O(n³)
// Space complexity: O(n²)
template<typename K>
K Matrix<K>::determinant() {
	if (!this->isSquare())
		return (0);

	if (this->_cols == 1)
		return (this->_content[0][0]);

	if (this->_cols == 2)
		return (std::fma(this->_content[0][0], this->_content[1][1], -this->_content[0][1] * this->_content[1][0]));

	K	det = static_cast<K>(0);
	K	sign = static_cast<K>(1);

	for (size_t col = 0; col < this->_cols; ++col) {
		Matrix<K> sub = submatrix(*this, 0, col);
		det = std::fma(sign * this->_content[0][col], sub.determinant(), det);
		sign = -sign;
	}
	return (det);
}
