/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:22:15 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 14:58:01 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n³)
// Space complexity: O(n²)
template<typename K>
Matrix<K> Matrix<K>::inverse() {
	if (!this->isSquare())
		throw std::invalid_argument("Matrix must be square to inverse the matrix");

	size_t n = this->_rows;

	K **aug = new K*[n];
	for (size_t i = 0; i < n; ++i) {
		aug[i] = new K[2 * n]();
		for (size_t j = 0; j < n; ++j)
			aug[i][j] = this->_content[i][j];
		aug[i][n + i] = static_cast<K>(1);
	}

	size_t pivot_row = 0;
	for (size_t col = 0; col < n && pivot_row < n; ++col) {
		size_t found = n;
		for (size_t row = pivot_row; row < n; ++row) {
			if (aug[row][col] != static_cast<K>(0)) {
				found = row;
				break;
			}
		}
		if (found == n)
			continue;

		K *tmp = aug[pivot_row];
		aug[pivot_row] = aug[found];
		aug[found] = tmp;

		K scale = aug[pivot_row][col];
		for (size_t j = 0; j < 2 * n; ++j)
			aug[pivot_row][j] = clean_zero(aug[pivot_row][j] / scale);

		for (size_t row = 0; row < n; ++row) {
			if (row == pivot_row)
				continue;
			K factor = aug[row][col];
			for (size_t j = 0; j < 2 * n; ++j)
				aug[row][j] = clean_zero(aug[row][j] - factor * aug[pivot_row][j]);
		}

		++pivot_row;
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			K expected = (i == j) ? static_cast<K>(1) : static_cast<K>(0);
			if (aug[i][j] != expected) {
				for (size_t k = 0; k < n; ++k)
					delete[] aug[k];
				delete[] aug;
				throw std::invalid_argument("Singular Matrix (not invertible)");
			}
		}
	}

	Matrix<K> result(n, n);
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
			result._content[i][j] = aug[i][n + j];

	for (size_t i = 0; i < n; ++i)
		delete[] aug[i];
	delete[] aug;

	return result;
}
