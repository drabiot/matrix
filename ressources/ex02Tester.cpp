/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:11 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 13:32:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	linear_interpolationTester(void) {
PRINT MAGENTA AND lerp(0., 1., 0.) CENDL;
PRINT MAGENTA AND lerp(0., 1., 1.) CENDL;
PRINT MAGENTA AND lerp(0., 1., 0.5) CENDL;
PRINT MAGENTA AND lerp(21., 42., 0.3) CENDL;
NLINE;

Vector<double> u1({2., 1.});
Vector<double> v1({4., 2.});

PRINT BLUE AND lerp(u1, v1, 0.3) CENDL;

Matrix<double> m1({{2., 1.}, {3., 4.}});
Matrix<double> m2({{20., 10.}, {30., 40.}});

PRINT GREEN AND lerp(m1, m2, 0.5) CENDL;
}
