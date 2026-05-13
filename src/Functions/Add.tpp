/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:11:45 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 20:12:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

template<typename K>
void	Vector<K>::add(const Vector<K>	&v) {
	if (this->_size != v._size)
		return;

	for (size_t i = 0; i < this->_size; ++i) {
		this->_content[i] = this->_content[i] + v._content[i];
	}
}
