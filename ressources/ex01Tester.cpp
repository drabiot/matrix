/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:07:12 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:43:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Matrix.hpp"

void	linearCombinationTester(void) {
	Vector<double> e1({1., 0., 0.});
	Vector<double> e2({0., 1., 0.});
	Vector<double> e3({0., 0., 1.});
	Vector<double> v1({1., 2., 3.});
	Vector<double> v2({0., 10., -100.});

	

	PRINT linear_combination({e1, e2, e3}, {10., -2., 0.5}) CENDL;
	// [10.]
	// [-2.]
	// [0.5]

	PRINT linear_combination({v1, v2}, {10., -2.}) CENDL;
	// [10.]
	// [0.]
	// [230.]

}
