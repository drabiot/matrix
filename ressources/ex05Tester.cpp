/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:50:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:32:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	cosineTester() {
	PRINT RED " 1st Test " CENDL;
	const Vector	<double>a({1, 0});
	const Vector	<double>b({0, 1});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between First vector and Second vector" CENDL;
	PRINT YELLOW AND angle_cos(a, b) CENDL;
	NLINE;

	PRINT RED " 2nd Test " CENDL;
	Vector	<double>c({2, 1});
	Vector	<double>d({4, 2});

	PRINT MAGENTA "Third Vector:" CENDL;
	PRINT c CENDL;
	PRINT MAGENTA "Fourth Vector:" CENDL;
	PRINT d CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between Third vector and Fourth vector" CENDL;
	PRINT YELLOW AND angle_cos(c, d) CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	const Vector	<double>e({1, 2, 3, 4});
	const Vector	<double>f({4, 5, 6, 2});

	PRINT MAGENTA "Fifth Vector:" CENDL;
	PRINT e CENDL;
	PRINT MAGENTA "Six Vector:" CENDL;
	PRINT f CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between Fifth vector and Six vector" CENDL;
	PRINT YELLOW AND angle_cos(e, f) CENDL;
	NLINE;

	PRINT WHITE "  -BONUS-  " CENDL;
	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>bonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)});

	PRINT MAGENTA "First Bonus Vector:" CENDL;
	PRINT bonusA CENDL;
	PRINT MAGENTA "Second Bonus Vector:" CENDL;
	PRINT bonusB CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between First Bonus Vector and Second Bonus Vector" CENDL;
	PRINT YELLOW AND angle_cos(bonusA, bonusB) CENDL;
	NLINE;
}
