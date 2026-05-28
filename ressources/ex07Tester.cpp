/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:14:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 15:31:49 by tchartie         ###   ########.fr       */
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

	PRINT RED " 4th Test " CENDL;

	PRINT MAGENTA "Compute product between Third matrix and 0.2" CENDL;
	PRINT YELLOW AND m3.mul_vec({0.2}) CENDL;
	NLINE;

	PRINT WHITE " Matrix Product " CENDL;
	
	Matrix	<double>m4({{2, 1}, {4, 2}});
	Matrix	<double>m5({{3, -5}, {6, 8}});
	Matrix	<double>m6({{5, -2}, {-1, 3}});
	Matrix	<double>m7({{4, 10, -1}, {-3, 2, 6}});

	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4 CENDL;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5 CENDL;

	PRINT RED " 1st Test " CENDL;

	PRINT MAGENTA "Compute product between First matrix and First matrix" CENDL;
	PRINT YELLOW AND m1.mul_mat(m1) CENDL;
	NLINE;

	PRINT RED " 2nd Test " CENDL;
	PRINT MAGENTA "Compute product between First matrix and Fourth matrix" CENDL;
	PRINT YELLOW AND m1.mul_mat(m4) CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	PRINT MAGENTA "Compute product between Fifth matrix and Fourth matrix" CENDL;
	PRINT YELLOW AND m5.mul_mat(m4) CENDL;
	NLINE;

	PRINT RED " 4th Test " CENDL;
	PRINT MAGENTA "Compute product between Six matrix and Seven matrix" CENDL;
	PRINT YELLOW AND m6.mul_mat(m7) CENDL;
	NLINE;

	PRINT RED " 5th Test " CENDL;
	PRINT MAGENTA "Compute product between Seven matrix and Six matrix" CENDL;
	PRINT YELLOW AND m7.mul_mat(m6) CENDL;
	NLINE;

	Vector	<std::complex<double>>vecBonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});

	Matrix<std::complex<double>> matBonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>> matBonusB = {
		{std::complex<double>(1,-1), std::complex<double>(0,2), std::complex<double>(-0.6)},
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-2,0), std::complex<double>(0,3)}
	};

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT MAGENTA "First Bonus Vector:" CENDL;
	PRINT vecBonusA CENDL;
	PRINT MAGENTA "First Bonus Matrix:" CENDL;
	PRINT matBonusA CENDL;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT matBonusB CENDL;

	PRINT MAGENTA "Compute product between First Bonus matrix and First Bonus vector" CENDL;
	PRINT YELLOW AND matBonusA.mul_vec(vecBonusA) CENDL;
	NLINE;
	PRINT MAGENTA "Compute product between First Bonus matrix and Second Bonus matrix" CENDL;
	PRINT YELLOW AND matBonusA.mul_mat(matBonusB) CENDL;
	NLINE;
}
