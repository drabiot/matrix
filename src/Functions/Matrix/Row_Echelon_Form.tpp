/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Row_Echelon_Form.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:28:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 18:02:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static K clean_value(K val) {
	double epsilon = 1e-14;

	if constexpr (is_complex<K>::value) {
		auto r = val.real();
		auto i = val.imag();
		
		double r_abs = (r < 0.0) ? -r : r;
		double i_abs = (i < 0.0) ? -i : i;
		
		return K(
			(r_abs < epsilon) ? 0.0 : r,
			(i_abs < epsilon) ? 0.0 : i
		);
	}
	else {
		double val_abs = (val < 0.0) ? -val : val;
		return (val_abs < epsilon) ? static_cast<K>(0) : val;
	}
}

// Time complexity:  O(nm²)
// Space complexity: O(nm)
template<typename K>
Matrix<K>   Matrix<K>::row_echelon() {
	Matrix<K> result(this->_content, this->_rows, this->_cols);
	size_t pivot_row = 0;
	
	for (size_t col = 0; col < result._cols && pivot_row < result._rows; ++col) {

		size_t found = result._rows;
		for (size_t row = pivot_row; row < result._rows; ++row) {
			if (clean_value(result._content[row][col]) != static_cast<K>(0)) {
				found = row;
				break;
			}
		}
		if (found == result._rows)
			continue;

		std::swap(result._content[pivot_row], result._content[found]);

		K scale = result._content[pivot_row][col];
		for (size_t j = 0; j < result._cols; ++j)
			result._content[pivot_row][j] = clean_value(result._content[pivot_row][j] / scale);

		for (size_t row = 0; row < result._rows; ++row) {
			if (row == pivot_row)
				continue;
			K factor = result._content[row][col];
			for (size_t j = 0; j < result._cols; ++j) {
				result._content[row][j] = clean_value(result._content[row][j] - factor * result._content[pivot_row][j]);
			}
		}
		++pivot_row;
	}
	return (result);
}
