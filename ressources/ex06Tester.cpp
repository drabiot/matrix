/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:14:57 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/21 17:38:27 by tchartie         ###   ########.fr       */
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
	PRINT YELLOW AND cross_product({1, 2}, {4, 5}) CENDL;
	NLINE;

	PRINT RED " Too many value Test " CENDL;

	PRINT MAGENTA "Cross Product between Second vector and Third vector" CENDL;
	PRINT YELLOW AND cross_product({1, 2, 3, 4}, {5, 6, 7, 8}) CENDL;
	NLINE;
}
