/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:02:28 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 16:04:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	rankTester() {
	Matrix<double>	m1({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
	Matrix<double>	m2({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});
	Matrix<double>	m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}, {21., 18., 7.}});


	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Rank of the First Matrix" CENDL;
	PRINT CYAN AND m1.rank() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Rank of the Second Matrix" CENDL;
	PRINT CYAN AND m2.rank() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Rank of the Third Matrix" CENDL;
	PRINT CYAN AND m3.rank() CENDL;
	NLINE;
}
