/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Multiplication.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:07:40 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 15:55:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A ∈ R^(m×n), u ∈ R^n
// Time complexity:  O(nm) double loop i∈[0,m) j∈[0,n)
// Space complexity: O(m)
template<typename K>
Vector<K>	Matrix<K>::mul_vec(std::initializer_list<K> vec) {
	K result[this->_rows];

	for (size_t i = 0; i < this->_rows; ++i) {
		result[i] = 0;
		for (size_t j = 0; j < this->_cols; ++j)
			result[i] = std::fma(this->_content[i][j], vec.begin()[j], result[i]);
	}

	return (Vector<K>(result, this->_rows));
}

// A ∈ R^(m×n), u ∈ R^n
// Time complexity:  O(nm) double loop i∈[0,m) j∈[0,n)
// Space complexity: O(m)
template<typename K>
Vector<K>	Matrix<K>::mul_vec(Vector<K> vec) {
	K result[this->_rows];

	for (size_t i = 0; i < this->_rows; ++i) {
		result[i] = 0;
		for (size_t j = 0; j < this->_cols; ++j)
			result[i] = std::fma(this->_content[i][j], vec[j], result[i]);
	}

	return (Vector<K>(result, this->_rows));
}

// A ∈ R^(m×n), B ∈ R^(n×p)
// Time complexity:  O(nmp) triple loop i∈[0,m) j∈[0,p) k∈[0,n)
// Space complexity: O(mp)
template<typename K>
Matrix<K>	Matrix<K>::mul_mat(Matrix<K> mat) {
	Matrix<K>	result(this->_rows, mat._cols);

	for (size_t i = 0; i < this->_rows; ++i)
		for (size_t j = 0; j < mat._cols; ++j)
			for (size_t k = 0; k < this->_cols; ++k)
				result._content[i][j] = std::fma(this->_content[i][k], mat._content[k][j], result._content[i][j]);

	return (result);
}
