/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Row_Echelon_Form.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:28:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 15:55:27 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static K clean_zero(K val) {
	return (val == static_cast<K>(0)) ? static_cast<K>(0) : val;
}

// Time complexity:  O(nm²)
// Space complexity: O(nm)
template<typename K>
Matrix<K>	Matrix<K>::row_echelon() {
	Matrix<K> result(this->_content, this->_rows, this->_cols);

	size_t pivot_row = 0;
	for (size_t col = 0; col < result._cols && pivot_row < result._rows; ++col) {

		size_t found = result._rows;
		for (size_t row = pivot_row; row < result._rows; ++row) {
			if (result._content[row][col] != static_cast<K>(0)) {
				found = row;
				break;
			}
		}
		if (found == result._rows)
			continue;

		std::swap(result._content[pivot_row], result._content[found]);

		K scale = result._content[pivot_row][col];
		for (size_t j = 0; j < result._cols; ++j)
			result._content[pivot_row][j] = clean_zero(result._content[pivot_row][j] / scale);

		for (size_t row = 0; row < result._rows; ++row) {
			if (row == pivot_row)
				continue;
			K factor = result._content[row][col];
			for (size_t j = 0; j < result._cols; ++j)
				result._content[row][j] = clean_zero(result._content[row][j] - factor * result._content[pivot_row][j]);
		}

		++pivot_row;
	}
	return (result);
}
