/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trace.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:43:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 16:00:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n)
// Space complexity: O(1)
template<typename K>
K Matrix<K>::trace() {
	K result = 0;
	for (size_t i = 0; i < this->_rows; ++i)
		result += this->_content[i][i];
	return (result);
}
