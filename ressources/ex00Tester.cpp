/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:19:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/18 19:20:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	addTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Add First Vector to the Second Vector" CENDL;
	b.add(a);
	PRINT b CENDL;
}

void	addTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	Matrix<double> b = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}, {3.3, 4.2, -9.0}};

	PRINT RED "First Matrix:" CENDL;
	PRINT a CENDL;
	PRINT RED "Second Matrix:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT RED "Add First Matrix to the Second Matrix" CENDL;
	a.add(a);
	PRINT b CENDL;
}

void	subTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Subtract First Vector to the Second Vector" CENDL;
	b.add(a);
	PRINT b CENDL;
}

void	subTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	Matrix<double> b = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}, {3.3, 4.2, -9.0}};

	PRINT RED "First Matrix:" CENDL;
	PRINT a CENDL;
	PRINT RED "Second Matrix:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT RED "Subtract First Matrix to the Second Matrix" CENDL;
	a.add(a);
	PRINT b CENDL;
}

void	sclTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});

	PRINT MAGENTA "Vector:" CENDL;
	PRINT a CENDL;
	NLINE;

	for (int i = 1; i <= 3; ++i) {
		PRINT MAGENTA "Scaling vector by " BLUE AND i CENDL;
		a.scl(i);
		PRINT a CENDL;
	}
}

void	sclTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

	PRINT RED "Matrix:" CENDL;
	PRINT a CENDL;
	NLINE;

	for (int i = 1; i <= 3; ++i) {
		PRINT RED "Scaling matrix by " YELLOW AND i CENDL;
		a.scl(i);
		PRINT a CENDL;
	}

}
