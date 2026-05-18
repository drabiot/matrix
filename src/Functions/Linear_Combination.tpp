/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linear_Combination.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:30:54 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/18 21:32:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// L = number of vectors, D = dimension of vectors
// Time complexity:  O(n) where n = L * D
// Space complexity: O(D)
template<typename K>
Vector<K>	linear_combination(std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs) {
	Vector<K>	result(u.begin()->size());
	size_t		i = 0;

	for (const Vector<K>& vec : u) {
		for (size_t j = 0; j < vec.size(); ++j)
			result[j] = std::fma(coefs.begin()[i], vec[j], result[j]);
		++i;
	}
	return (result);
}

// L = number of vectors, D = dimension of vectors
// Time complexity:  O(n) where n = L * D
// Space complexity: O(D)
template<typename K>
Vector<K>	linear_combination(std::initializer_list<Vector<K>> u, Vector<K> coefs) {
	Vector<K>	result(u.begin()->size());
	size_t		i = 0;

	for (const Vector<K>& vec : u) {
		for (size_t j = 0; j < vec.size(); ++j)
			result[j] = std::fma(coefs[i], vec[j], result[j]);
		++i;
	}
	return (result);
}

// L = number of vectors, D = dimension of vectors
// Time complexity:  O(n) where n = L * D
// Space complexity: O(D)
template<typename K>
Vector<K> linear_combination(Matrix<K> u, std::initializer_list<K> coefs) {
	Vector<K>	result(u.getCols());

	for (size_t i = 0; i < u.getRows(); ++i)
		for (size_t j = 0; j < u.getCols(); ++j)
			result[j] = std::fma(coefs.begin()[i], u[i][j], result[j]);
	return (result);
}

// L = number of vectors, D = dimension of vectors
// Time complexity:  O(n) where n = L * D
// Space complexity: O(D)
template<typename K>
Vector<K> linear_combination(Matrix<K> u, Vector<K> coefs) {
	Vector<K>	result(u.getCols());

	for (size_t i = 0; i < u.getRows(); ++i)
		for (size_t j = 0; j < u.getCols(); ++j)
			result[j] = std::fma(coefs[i], u[i][j], result[j]);
	return (result);
}
