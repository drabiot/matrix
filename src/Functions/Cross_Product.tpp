/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cross_Product.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:57:21 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 18:14:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(1) - cross product always performs exactly 6 multiplications and 3 additions
// Space complexity: O(1) - result vector is always size 3
template<typename K>
Vector<K>	cross_product(std::initializer_list<K> u, std::initializer_list<K> v) {
	Vector<K>	result({static_cast<K>(fma_wrapper(u.begin()[1], v.begin()[2], -u.begin()[2] * v.begin()[1])), \
						static_cast<K>(fma_wrapper(u.begin()[2], v.begin()[0], -u.begin()[0] * v.begin()[2])), \
						static_cast<K>(fma_wrapper(u.begin()[0], v.begin()[1], -u.begin()[1] * v.begin()[0]))});
	return (result);
}

// Time complexity:  O(1) - cross product always performs exactly 6 multiplications and 3 additions
// Space complexity: O(1) - result vector is always size 3
template<typename K>
Vector<K>	cross_product(Vector<K> u, Vector<K> v) {
	Vector<K>	result({static_cast<K>(fma_wrapper(u[1], v[2], -u[2] * v[1])), \
						static_cast<K>(fma_wrapper(u[2], v[0], -u[0] * v[2])), \
						static_cast<K>(fma_wrapper(u[0], v[1], -u[1] * v[0]))});
	return (result);
}
