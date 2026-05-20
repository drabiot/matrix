/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substract.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 15:44:38 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
void	Vector<K>::sub(const Vector<K>	&v) {
	for (size_t i = 0; i < this->_size; ++i) {
		this->_content[i] = this->_content[i] - v._content[i];
	}
}
