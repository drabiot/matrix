/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:20:23 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 18:24:45 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	linear_combinationTester(void) {
	Vector	<double>a({1, 0, 0});
	Vector	<double>b({0, 1, 0});
	Vector	<double>c({0, 0, 1});

	Vector	<double>d({1, 2, 3});
	Vector	<double>e({0, 10, -100});

	Vector	<std::complex<double>>vecBonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>vecBonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)});

	Matrix<double> f = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix<double> g = {{1, 2, 3}, {0, 10, -100}};

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

	Vector	<double>coef({10, -2, 0.5});
	Vector	<double>coef2({10, -2});
	
	PRINT WHITE " --INITIALIZER LIST-- " CENDL;
	PRINT linear_combination({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}, {10., -2., 0.5}) CENDL;
	PRINT linear_combination({{1, 2, 3}, {0, 10, -100}}, {10, -2}) CENDL;
	PRINT linear_combination({{1, 2, 3}, {0, 10, -100}}, {10, -2, 6}) CENDL;
	PRINT linear_combination({{1, 2, 3}, {0, 10, -100}}, {10}) CENDL;

	PRINT WHITE " --VECTOR-- " CENDL;
	PRINT linear_combination({a, b, c}, coef) CENDL;
	PRINT linear_combination({d, e}, {10., -2.}) CENDL;

	PRINT WHITE " --MATRIX-- " CENDL;
	PRINT linear_combination(f, coef) CENDL;
	PRINT linear_combination(g, {10., -2.}) CENDL;

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT linear_combination(matBonusA, vecBonusA) CENDL;
	PRINT linear_combination(matBonusB, {std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)}) CENDL;
}
