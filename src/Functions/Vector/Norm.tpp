/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:09:10 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 14:14:14 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static float	abs_wrapper(const K& x) {
	if constexpr (is_complex<K>::value)
		return (std::pow(x.real() * x.real() + x.imag() * x.imag(), 0.5f));
	else
		return (x < 0 ? -x : x);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_1(void) {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i)
		result += abs_wrapper(this->_content[i]);
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm(void) {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		float a = abs_wrapper(this->_content[i]);
		result = fma_wrapper(a, a, result);
	}
	return (std::pow(result, 0.5f));
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_inf(void) {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i)
		result = std::max(result, abs_wrapper(this->_content[i]));
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_1(void) const {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i)
		result += abs_wrapper(this->_content[i]);
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm(void) const {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		float a = abs_wrapper(this->_content[i]);
		result = fma_wrapper(a, a, result);
	}
	return (std::pow(result, 0.5f));
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_inf(void) const {
	float result = 0;

	for (size_t i = 0; i < this->_size; ++i)
		result = std::max(result, abs_wrapper(this->_content[i]));
	return (result);
}
