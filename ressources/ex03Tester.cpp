/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:25:07 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 13:38:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	dot_productTester(void) {
	PRINT RED " 1st Test " CENDL;
	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Dot product between First Vector & Second Vector" CENDL;
	PRINT YELLOW AND a.dot(b) CENDL;
	NLINE;

	PRINT GREEN "Test Vector integrity" CENDL;
	PRINT a CENDL;

	PRINT RED " 2nd Test " CENDL;
	Vector	<double>c({0, 0});
	Vector	<double>d({1, 1});

	PRINT MAGENTA "Third Vector:" CENDL;
	PRINT c CENDL;
	PRINT MAGENTA "Fourth Vector:" CENDL;
	PRINT d CENDL;
	NLINE;

	PRINT MAGENTA "Dot product between Third Vector & Fourth Vector" CENDL;
	PRINT YELLOW AND c.dot(d) CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	Vector	<double>e({1, 1});
	Vector	<double>f({1, 1});

	PRINT MAGENTA "Fifth Vector:" CENDL;
	PRINT e CENDL;
	PRINT MAGENTA "Six Vector:" CENDL;
	PRINT f CENDL;
	NLINE;

	PRINT MAGENTA "Dot product between Fifth Vector & Six Vector" CENDL;
	PRINT YELLOW AND e.dot(f) CENDL;
	NLINE;

	PRINT RED " 4th Test " CENDL;
	Vector	<double>g({-1, 6});
	Vector	<double>h({3, 2});

	PRINT MAGENTA "Seven Vector:" CENDL;
	PRINT g CENDL;
	PRINT MAGENTA "Eight Vector:" CENDL;
	PRINT h CENDL;
	NLINE;

	PRINT MAGENTA "Dot product between Seven Vector & Eight Vector" CENDL;
	PRINT YELLOW AND g.dot(h) CENDL;
	NLINE;
}
