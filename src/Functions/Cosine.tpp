/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cosine.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:30:46 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 16:11:39 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(n) where n = size of both vectors
// Space complexity: O(1)
template<typename K>
float	angle_cos(Vector<K> &u, Vector<K> &v) {
	return (u.dot(v) / (u.norm() * v.norm()));
}

// Time complexity:  O(n) where n = size of both vectors
// Space complexity: O(1)
template<typename K>
float	angle_cos(const Vector<K> &u, const Vector<K> &v) {
	return (u.dot(v) / (u.norm() * v.norm()));
}
