/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linear_Combination.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:30:54 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:40:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <cmath>

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