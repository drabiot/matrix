/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:22:15 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/29 15:06:44 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static double pivot_norm(const K& val) {
	if constexpr (is_complex_v<K>) {
		double r = static_cast<double>(val.real());
		double i = static_cast<double>(val.imag());
		return (r * r + i * i);
	} else {
		return (static_cast<double>(val < 0 ? -val : val));
	}
}

template<typename K>
static K clean_zero(K val) {
	return (val == static_cast<K>(0)) ? static_cast<K>(0) : val;
}

// Time complexity:  O(n³)
// Space complexity: O(n²)
template<typename K>
Matrix<K>	Matrix<K>::inverse() {
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
		double best = 1e-12;
		for (size_t row = pivot_row; row < n; ++row) {
			double candidate = pivot_norm(aug[row][col]);
			if (candidate > best) {
				best = candidate;
				found = row;
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
			if (pivot_norm(aug[i][j] - expected) > 1e-9) {
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

	return (result);
}
