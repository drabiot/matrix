/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substract.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 13:57:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = rows * cols
// Space complexity: O(1)
template<typename K>
void	Matrix<K>::sub(const Matrix<K>	&m) {
for (size_t i = 0; i < this->_rows; ++i) {
		for (size_t j = 0; j < this->_cols; ++j)
			this->_content[i][j] = this->_content[i][j] - m._content[i][j];
	}
}
