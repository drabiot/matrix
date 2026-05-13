/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scale.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:39 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 20:15:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

template<typename K>
void	Vector<K>::scl(K a) {
	for (size_t i = 0; i < this->_size; ++i) {
		this->_content[i] = this->_content[i] * a;
	}
}
