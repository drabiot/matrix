/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transpose.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:23:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 16:40:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n*m)
// Space complexity: O(n*m)
template<typename K>
Matrix<K>	Matrix<K>::transpose() {
	Matrix<K>	result(this->_cols, this->_rows);

	for (size_t i = 0; i < this->_rows; ++i)
			for (size_t j = 0; j < this->_cols; ++j)
				result._content[j][i] = this->_content[i][j];

	return (result);
}
