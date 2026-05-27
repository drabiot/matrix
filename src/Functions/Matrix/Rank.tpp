/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rank.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:55:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 13:19:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(nm²)
// Space complexity: O(nm)
template<typename K>
size_t	Matrix<K>::rank() {
	Matrix<K>	tmp = this->row_echelon();
	size_t		res = 0;

	for (size_t	i = 0; i < tmp.getRows(); ++i) {
		for (size_t j = 0; j < tmp.getCols(); ++j) {
			if (tmp.getContent()[i][j] != 0) {
				res++;
				break;
			}
		}
	}
	return (res);
}
