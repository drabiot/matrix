/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:47:09 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 16:13:11 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	traceTester() {
	Matrix	<double>m1({{1, 0}, {0, 1}});
	Matrix	<double>m2({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}});
	Matrix	<double>m3({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});
	Matrix	<double>m4({{-2, -8, 4}, {1, -23, 4}});
	Matrix	<double>m5({{-2, -8}, {1, -23}, {0, 6}});

	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND m1.trace() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND m2.trace() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND m3.trace() CENDL;
	NLINE;
	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND m4.trace() CENDL;
	NLINE;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND m5.trace() CENDL;
	NLINE;

	PRINT WHITE "  -BONUS-  " CENDL;
	Matrix<std::complex<double>>bonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>>bonusB = {
		{std::complex<double>(1,-1), std::complex<double>(0,2), std::complex<double>(-0.6)},
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-2,0), std::complex<double>(0,3)}
	};

	PRINT MAGENTA "Fist Bonus Matrix:" CENDL;
	PRINT bonusA;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND bonusA.trace() CENDL;
	NLINE;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT bonusB;
	PRINT BLUE "Trace" CENDL;
	PRINT CYAN AND bonusB.trace() CENDL;
	NLINE;
}
