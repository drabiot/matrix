/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cross_Product.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:57:21 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:13:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(1) - cross product always performs exactly 6 multiplications and 3 additions
// Space complexity: O(1) - result vector is always size 3
template<typename K>
Vector<K>	cross_product(std::initializer_list<K> u, std::initializer_list<K> v) {
	Vector<K> result(3);
	auto u_ptr = u.begin();
	auto v_ptr = v.begin();

	if (u.size() != 3 || v.size() != 3)
		return (result);

	if constexpr (is_complex<K>::value) {
		result[0] = fma_wrapper(std::conj(u_ptr[1]), v_ptr[2], -std::conj(u_ptr[2]) * v_ptr[1]);
		result[1] = fma_wrapper(std::conj(u_ptr[2]), v_ptr[0], -std::conj(u_ptr[0]) * v_ptr[2]);
		result[2] = fma_wrapper(std::conj(u_ptr[0]), v_ptr[1], -std::conj(u_ptr[1]) * v_ptr[0]);
	}
	else {
		result[0] = fma_wrapper(u_ptr[1], v_ptr[2], -u_ptr[2] * v_ptr[1]);
		result[1] = fma_wrapper(u_ptr[2], v_ptr[0], -u_ptr[0] * v_ptr[2]);
		result[2] = fma_wrapper(u_ptr[0], v_ptr[1], -u_ptr[1] * v_ptr[0]);
	}

	return (result);
}

// Time complexity:  O(1) - cross product always performs exactly 6 multiplications and 3 additions
// Space complexity: O(1) - result vector is always size 3
template<typename K>
Vector<K>	cross_product(const Vector<K> &u, const Vector<K> &v) {
	Vector<K> result(3);
	if (u.size() != 3 || v.size() != 3)
		return (result);

	if constexpr (is_complex<K>::value) {
		result[0] = fma_wrapper(std::conj(u[1]), v[2], -std::conj(u[2]) * v[1]);
		result[1] = fma_wrapper(std::conj(u[2]), v[0], -std::conj(u[0]) * v[2]);
		result[2] = fma_wrapper(std::conj(u[0]), v[1], -std::conj(u[1]) * v[0]);
	}
	else {
		result[0] = fma_wrapper(u[1], v[2], -u[2] * v[1]);
		result[1] = fma_wrapper(u[2], v[0], -u[0] * v[2]);
		result[2] = fma_wrapper(u[0], v[1], -u[1] * v[0]);
	}

	return (result);
}
