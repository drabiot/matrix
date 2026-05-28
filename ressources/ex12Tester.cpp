/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:30:52 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:40:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	inverseTester() {
	Matrix<double>	m1({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
	Matrix<double>	m2({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
	Matrix<double>	m3({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
	Matrix<double>	m4({{8, 5}, {4, 7}, {7, 6}});
	Matrix<double>	m5({{0., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
	Matrix<double>	m6({{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}});

	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Inverse of the First Matrix" CENDL;
	PRINT CYAN AND m1.inverse() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Inverse of the Second Matrix" CENDL;
	PRINT CYAN AND m2.inverse() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Inverse of the Third Matrix" CENDL;
	PRINT CYAN AND m3.inverse() CENDL;
	NLINE;
	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4;
	PRINT BLUE "Inverse of the Fourth Matrix" CENDL;
	PRINT CYAN AND m4.inverse() CENDL;						//Error
	NLINE;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5;
	PRINT BLUE "Inverse of the Fifth Matrix" CENDL;
	PRINT CYAN AND m5.inverse() CENDL;						//Error
	NLINE;
	PRINT MAGENTA "Six Matrix:" CENDL;
	PRINT m6;
	PRINT BLUE "Inverse of the Six Matrix" CENDL;
	PRINT CYAN AND m6.inverse() CENDL;						//Error
	NLINE;
}
