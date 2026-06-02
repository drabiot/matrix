/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:14:57 by tchartie          #+#    #+#             */
/*   Updated: 2026/06/02 13:13:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	cross_productTester() {
	PRINT RED " 1st Test " CENDL;
	const Vector	<double>a({0, 0, 1});
	const Vector	<double>b({1, 0, 0});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Cross Product between First vector and Second vector" CENDL;
	PRINT YELLOW AND cross_product(a, b) CENDL;
	NLINE;

	PRINT RED " 2nd Test " CENDL;

	PRINT MAGENTA "Cross Product between Second vector and Third vector" CENDL;
	PRINT YELLOW AND cross_product({1, 2, 3}, {4, 5, 6}) CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	const Vector	<double>e({4, 2, -3});
	const Vector	<double>f({-2, -5, 16});

	PRINT MAGENTA "Fourth Vector:" CENDL;
	PRINT e CENDL;
	PRINT MAGENTA "Fifth Vector:" CENDL;
	PRINT f CENDL;
	NLINE;

	PRINT MAGENTA "Cross Product between Fourth vector and Fifth vector" CENDL;
	PRINT YELLOW AND cross_product(e, f) CENDL;
	NLINE;

	PRINT RED " Few value Test " CENDL;

	PRINT MAGENTA "Cross Product between Second vector and Third vector" CENDL;
	PRINT YELLOW AND cross_product({1}, {4}) CENDL;
	NLINE;

	PRINT RED " Too many value Test " CENDL;

	PRINT MAGENTA "Cross Product between Second vector and Third vector" CENDL;
	PRINT YELLOW AND cross_product({1, 2, 3, 4}, {5, 6}) CENDL;
	NLINE;

	PRINT WHITE "  -BONUS-  " CENDL;
	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>bonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,2)});

	PRINT MAGENTA "First Bonus Vector:" CENDL;
	PRINT bonusA CENDL;
	PRINT MAGENTA "Second Bonus Vector:" CENDL;
	PRINT bonusB CENDL;
	NLINE;

	PRINT MAGENTA "Cross Product between Second vector and Third vector" CENDL;
	PRINT YELLOW AND cross_product(bonusA, bonusB) CENDL;
	NLINE;
}
