/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:09:10 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 15:59:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_1(void) {
	float	result = 0;
	int		abs = 1;

	for (size_t i = 0; i < this->_size; ++i) {
		abs = (this->_content[i] < 0) ? -1 : 1;
		result = std::fma(this->_content[i], abs, result);
	}
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm(void) {
	float	result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		result = std::fma(this->_content[i], this->_content[i], result);
	}
	return (std::pow(result, 0.5));
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_inf(void) {
	float	result = 0;
	int		abs = 1;

	for (size_t i = 0; i < this->_size; ++i) {
		abs = (this->_content[i] < 0) ? -1 : 1;
		float	candidate = this->_content[i] * abs;
		result = std::max(candidate, result);
	}
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_1(void) const {
	float	result = 0;
	int		abs = 1;

	for (size_t i = 0; i < this->_size; ++i) {
		abs = (this->_content[i] < 0) ? -1 : 1;
		result = std::fma(this->_content[i], abs, result);
	}
	return (result);
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm(void) const {
	float	result = 0;

	for (size_t i = 0; i < this->_size; ++i) {
		result = std::fma(this->_content[i], this->_content[i], result);
	}
	return (std::pow(result, 0.5));
}

// Time complexity:  O(n) where n = size of the vector
// Space complexity: O(1)
template<typename K>
float	Vector<K>::norm_inf(void) const {
	float	result = 0;
	int		abs = 1;

	for (size_t i = 0; i < this->_size; ++i) {
		abs = (this->_content[i] < 0) ? -1 : 1;
		float	candidate = this->_content[i] * abs;
		result = std::max(candidate, result);
	}
	return (result);
}
