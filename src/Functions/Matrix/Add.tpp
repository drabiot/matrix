/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:45 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:23:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = rows * cols
// Space complexity: O(1)
template<typename K>
void	Matrix<K>::add(Matrix<K> &m) {
	for (size_t i = 0; i < this->_rows && i < m.getRows(); ++i) {
		for (size_t j = 0; j < this->_cols && i < m.getCols(); ++j)
			this->_content[i][j] = this->_content[i][j] + m._content[i][j];
	}
}

// Time complexity:  O(n) where n = rows * cols
// Space complexity: O(1)
template<typename K>
void	Matrix<K>::add(const Matrix<K> &m) {
	for (size_t i = 0; i < this->_rows && i < m.getRows(); ++i) {
		for (size_t j = 0; j < this->_cols && i < m.getCols(); ++j)
			this->_content[i][j] = this->_content[i][j] + m._content[i][j];
	}
}
