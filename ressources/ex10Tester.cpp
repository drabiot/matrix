/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:40:07 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 18:04:49 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	row_echelon_formTester() {
	Matrix	<double>m1({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	Matrix	<double>m2({{1, 2}, {3, 4}});
	Matrix	<double>m3({{1, 2}, {2, 4}});
	Matrix	<double>m4({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
	Matrix	<double>m5({{2.0, 3.0, 4.0}, {4.0, 6.0, 8.0}, {1.0, 3.0, 1.0}});
	Matrix	<double>m6({{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}});

	PRINT MAGENTA "First Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Row Echelon Form of the First Matrix" CENDL;
	PRINT CYAN AND m1.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Row Echelon Form of the Second Matrix" CENDL;
	PRINT CYAN AND m2.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Row Echelon Form of the Third Matrix" CENDL;
	PRINT CYAN AND m3.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4;
	PRINT BLUE "Row Echelon Form of the Fourth Matrix" CENDL;
	PRINT CYAN AND m4.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5;
	PRINT BLUE "Row Echelon Form of the Fifth Matrix" CENDL;
	PRINT CYAN AND m5.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Six Matrix:" CENDL;
	PRINT m6;
	PRINT BLUE "Row Echelon Form of the Six Matrix" CENDL;
	PRINT CYAN AND m6.row_echelon() CENDL;
	NLINE;

	PRINT WHITE "  -BONUS-  " CENDL;
	Matrix<std::complex<double>>bonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>>bonusB = {
		{std::complex<double>(128,-1), std::complex<double>(0,2), std::complex<double>(-0,6)},
		{std::complex<double>(-1,0), std::complex<double>(24,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-21,0), std::complex<double>(0,32)}
	};

	Matrix<std::complex<double>> bonusC = {
		{std::complex<double>(1, 1), std::complex<double>(2, 2)},
		{std::complex<double>(2, 2), std::complex<double>(4, 4)},
	};

	PRINT MAGENTA "First Bonus Matrix:" CENDL;
	PRINT bonusA;
	PRINT BLUE "Row Echelon Form of the First Matrix" CENDL;
	PRINT CYAN AND bonusA.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT bonusB;
	PRINT BLUE "Row Echelon Form of the Second Matrix" CENDL;
	PRINT CYAN AND bonusB.row_echelon() CENDL;
	NLINE;
	PRINT MAGENTA "Third Bonus Matrix:" CENDL;
	PRINT bonusC;
	PRINT BLUE "Row Echelon Form of the Second Matrix" CENDL;
	PRINT CYAN AND bonusC.row_echelon() CENDL;
	NLINE;
}
