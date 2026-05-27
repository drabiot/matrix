/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot_Product.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:17:26 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 18:15:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = size of both vectors
// Space complexity: O(1)
template<typename K>
K	Vector<K>::dot(Vector<K> &v) {
	K result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		result = fma_wrapper(this->_content[i], v._content[i], result);
	}
	return (result);
}

// Time complexity:  O(n) where n = size of both vectors
// Space complexity: O(1)
template<typename K>
K	Vector<K>::dot(const Vector<K> &v) const {
	K result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		result = fma_wrapper(this->_content[i], v._content[i], result);
	}
	return (result);
}
