/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:50:43 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 16:10:31 by tchartie         ###   ########.fr       */
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

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT c CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT d CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between First vector and Second vector" CENDL;
	PRINT YELLOW AND angle_cos(c, d) CENDL;
	NLINE;

	PRINT RED " 3rd Test " CENDL;
	const Vector	<double>e({1, 2, 3});
	const Vector	<double>f({4, 5, 6});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT e CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT f CENDL;
	NLINE;

	PRINT MAGENTA "Cos of the Angle between First vector and Second vector" CENDL;
	PRINT YELLOW AND angle_cos(e, f) CENDL;
	NLINE;

}
