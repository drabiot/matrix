/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:15:10 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:39:11 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	determinantTester() {
	Matrix	<double>m1({{1, -1}, {-1, 1}});
	Matrix	<double>m2({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
	Matrix	<double>m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
	Matrix	<double>m4({{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}});
	Matrix	<double>m5({{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}});

	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Determinant of the First Matrix" CENDL;
	PRINT CYAN AND m1.determinant() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Determinant of the Second Matrix" CENDL;
	PRINT CYAN AND m2.determinant() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Determinant of the Third Matrix" CENDL;
	PRINT CYAN AND m3.determinant() CENDL;
	NLINE;
	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4;
	PRINT BLUE "Determinant of the Fourth Matrix" CENDL;
	PRINT CYAN AND m4.determinant() CENDL;
	NLINE;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5;
	PRINT BLUE "Determinant of the Fifth Matrix" CENDL;
	PRINT CYAN AND m5.determinant() CENDL;						//Error
	NLINE;
}
