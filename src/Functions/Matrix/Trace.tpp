/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trace.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:43:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:34:46 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n)
// Space complexity: O(1)
template<typename K>
K	Matrix<K>::trace() {
	if (!this->isSquare())
		throw std::invalid_argument("Matrix must be square to get the trace");

	K result = 0;
	for (size_t i = 0; i < this->_rows; ++i)
		result += this->_content[i][i];
	return (result);
}
