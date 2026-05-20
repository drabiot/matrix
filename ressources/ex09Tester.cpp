/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:27:06 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 16:27:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	transposeTester() {
	Matrix	<double>m1({{1, 0}, {0, 1}});
	Matrix	<double>m2({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}});
	Matrix	<double>m3({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});
	Matrix	<double>m4({{-2, -8, 4}, {1, -23, 4}});
	Matrix	<double>m5({{-2, -8}, {1, -23}, {0, 6}});

	PRINT MAGENTA "Fist Matrix:" CENDL;
	PRINT m1;
	PRINT BLUE "Transpose" CENDL;
	PRINT CYAN AND m1.transpose() CENDL;
	NLINE;
	PRINT MAGENTA "Second Matrix:" CENDL;
	PRINT m2;
	PRINT BLUE "Transpose" CENDL;
	PRINT CYAN AND m2.transpose() CENDL;
	NLINE;
	PRINT MAGENTA "Third Matrix:" CENDL;
	PRINT m3;
	PRINT BLUE "Transpose" CENDL;
	PRINT CYAN AND m3.transpose() CENDL;
	NLINE;
	PRINT MAGENTA "Fourth Matrix:" CENDL;
	PRINT m4;
	PRINT BLUE "Transpose" CENDL;
	PRINT CYAN AND m4.transpose() CENDL;
	NLINE;
	PRINT MAGENTA "Fifth Matrix:" CENDL;
	PRINT m5;
	PRINT BLUE "Transpose" CENDL;
	PRINT CYAN AND m5.transpose() CENDL;
	NLINE;
}
