/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matlib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:51:03 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/15 16:54:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATLIB_HPP
# define MATLIB_HPP

# include "Vector.hpp"
# include "Matrix.hpp"

template<typename K>
Vector<K>	linear_combination(std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs);

# include "../../src/Functions/Linear_Combination.tpp"

#endif //MATLIB_HPP
