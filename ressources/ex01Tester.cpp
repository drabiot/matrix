/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:20:23 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 12:48:35 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	linear_combinationTester(void) {
	Vector	<double>a({1, 0, 0});
	Vector	<double>b({0, 1, 0});
	Vector	<double>c({0, 0, 1});

	Vector	<double>d({1, 2, 3});
	Vector	<double>e({0, 10, -100});

	Matrix<double> f = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix<double> g = {{1, 2, 3}, {0, 10, -100}};

	Vector	<double>coef({10, -2, 0.5});
	Vector	<double>coef2({10, -2});
	
	PRINT WHITE " --INITIALIZER LIST-- " CENDL;
	PRINT linear_combination({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}, {10., -2., 0.5}) CENDL;
	PRINT linear_combination({{1., 2., 3.}, {0., 10., -100.}}, {10., -2.}) CENDL;

	PRINT WHITE " --VECTOR-- " CENDL;
	PRINT linear_combination({a, b, c}, coef) CENDL;
	PRINT linear_combination({d, e}, {10., -2.}) CENDL;

	PRINT WHITE " --MATRIX-- " CENDL;
	PRINT linear_combination(f, coef) CENDL;
	PRINT linear_combination(g, {10., -2.}) CENDL;
}
