/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:02:28 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/29 15:12:57 by tchartie         ###   ########.fr       */
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

	PRINT MAGENTA "Fist Bonus Matrix:" CENDL;
	PRINT bonusA;
	PRINT BLUE "Rank of the First Bonus Matrix" CENDL;
	PRINT CYAN AND bonusA.rank() CENDL;
	NLINE;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT bonusB;
	PRINT BLUE "Rank of the Second Bonus Matrix" CENDL;
	PRINT CYAN AND bonusB.rank() CENDL;
	NLINE;
	PRINT MAGENTA "Third Bonus Matrix:" CENDL;
	PRINT bonusC;
	PRINT BLUE "Rank of the Third Bonus Matrix" CENDL;
	PRINT CYAN AND bonusC.rank() CENDL;
	NLINE;
}
