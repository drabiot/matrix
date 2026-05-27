/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scale.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:39 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 17:54:34 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
void	Vector<K>::scl(K a) {
	for (size_t i = 0; i < this->_size; ++i) {
		this->_content[i] *= a;
	}
}
