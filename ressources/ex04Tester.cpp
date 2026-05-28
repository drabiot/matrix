/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:21:37 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 14:15:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	normTester(void) {
	PRINT RED " 1st Test " CENDL;
	Vector	<double>a({0, 0, 0, 0});

	PRINT MAGENTA "Vector:" CENDL;
	PRINT a CENDL;
	NLINE;

	PRINT MAGENTA "Norm:" CENDL;
	PRINT BLUE AND a.norm_1() AND "\t //Manhattan norm" CENDL;
	PRINT YELLOW AND a.norm() AND "\t //Euclidean norm" CENDL;
	PRINT GREEN AND a.norm_inf() AND "\t //supremum norm" CENDL;
	NLINE;

	PRINT RED " 2nd Test " CENDL;
	Vector	<double>b({1, 2, 3});

	PRINT MAGENTA "Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Norm:" CENDL;
	PRINT BLUE AND b.norm_1() CENDL;
	PRINT YELLOW AND b.norm() CENDL;
	PRINT GREEN AND b.norm_inf() CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	Vector	<double>c({-1, -2});

	PRINT MAGENTA "Vector:" CENDL;
	PRINT c CENDL;
	NLINE;

	PRINT MAGENTA "Norm:" CENDL;
	PRINT BLUE AND c.norm_1() CENDL;
	PRINT YELLOW AND c.norm() CENDL;
	PRINT GREEN AND c.norm_inf() CENDL;
	NLINE;

	PRINT WHITE "  -BONUS-  " CENDL;
	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>bonusB({std::complex<double>(2,-1), std::complex<double>(0,3)});

	PRINT MAGENTA "Norm:" CENDL;
	PRINT BLUE AND bonusA.norm_1() CENDL;
	PRINT YELLOW AND bonusA.norm() CENDL;
	PRINT GREEN AND bonusA.norm_inf() CENDL;
	NLINE;

	PRINT MAGENTA "Norm:" CENDL;
	PRINT BLUE AND bonusB.norm_1() CENDL;
	PRINT YELLOW AND bonusB.norm() CENDL;
	PRINT GREEN AND bonusB.norm_inf() CENDL;
	NLINE;

}
