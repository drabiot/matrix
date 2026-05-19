/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cosine.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:30:46 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 16:08:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
float	angle_cos(Vector<K> &u, Vector<K> &v) {
	return (u.dot(v) / (u.norm() * v.norm()));
}

template<typename K>
float	angle_cos(const Vector<K> &u, const Vector<K> &v) {
	return (u.dot(v) / (u.norm() * v.norm()));
}
