/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:14:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 14:30:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	matrix_multiplicationTester() {
	PRINT WHITE " Vector Product " CENDL;
	PRINT RED " 1st Test " CENDL;
	Vector	<double>v1({4., 2.});
	Matrix	<double>m1({{1, 0}, {0, 1}});
	Matrix	<double>m2({{2, 0}, {0, 2}});
	Matrix	<double>m3({{2, -2}, {-2, 2}});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT v1 CENDL;
	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1 CENDL;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2 CENDL;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3 CENDL;
	NLINE;

	PRINT MAGENTA "Compute product between First matrix and First vector" CENDL;
	PRINT YELLOW AND m1.mul_vec(v1) CENDL;
	NLINE;

	PRINT RED " 2nd Test " CENDL;

	PRINT MAGENTA "Compute product between Second matrix and First vector" CENDL;
	PRINT YELLOW AND m2.mul_vec({4., 2.}) CENDL;
	NLINE;

		PRINT RED " 3rd Test " CENDL;

	PRINT MAGENTA "Compute product between Third matrix and First vector" CENDL;
	PRINT YELLOW AND m3.mul_vec(v1) CENDL;
	NLINE;

	PRINT WHITE " Matrix Product " CENDL;
}
