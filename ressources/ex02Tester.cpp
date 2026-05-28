/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:42:11 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:59:22 by tchartie         ###   ########.fr       */
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

	Vector	<std::complex<double>>vecBonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>vecBonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)});

	PRINT BLUE AND lerp(u1, v1, 0.3) CENDL;
	PRINT BLUE AND lerp({1.0}, v1, 0.3) CENDL;
	PRINT BLUE AND lerp(u1, {1.0, 2.0, 3.0, 4.0, 5.0}, 0.3) CENDL;

	Matrix<double> m1({{2., 1.}, {3., 4.}});
	Matrix<double> m2({{20., 10.}, {30., 40.}});

	Matrix<std::complex<double>> matBonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>> matBonusB = {
		{std::complex<double>(1,-1), std::complex<double>(0,2), std::complex<double>(-0,6)},
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-2,0), std::complex<double>(0,3)}
	};

	PRINT GREEN AND lerp(m1, m2, 0.5) CENDL;
	PRINT GREEN AND lerp(m1, {{20., 10.}}, 0.5) CENDL;
	PRINT GREEN AND lerp({{20., 10.}}, m2, 0.5) CENDL;

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT lerp(vecBonusA, vecBonusB, 0.5) CENDL;
	PRINT lerp(vecBonusA, {std::complex<double>(2,-1), std::complex<double>(0,3)}, 0.5) CENDL;
	PRINT lerp(matBonusA, matBonusB, 0.2) CENDL;
	PRINT lerp(matBonusA, {{std::complex<double>(1,-1), std::complex<double>(0,2), std::complex<double>(-0.6)}, \
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)}}, 0.2) CENDL;
}
