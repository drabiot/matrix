/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:19:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 17:25:27 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	addTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});
	Vector	<double>c({1, 0});

	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>bonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	PRINT MAGENTA "Third Vector:" CENDL;
	PRINT c CENDL;
	NLINE;

	PRINT MAGENTA "Add First Vector to the Second Vector" CENDL;
	b.add(a);
	PRINT b CENDL;

	PRINT MAGENTA "Add First Vector to the Third Vector" CENDL;
	c.add(a);
	PRINT c CENDL;

	PRINT MAGENTA "Add Third Vector to the Second Vector" CENDL;
	b.add(c);
	PRINT c CENDL;


	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT RED "First Bonus Vector:" CENDL;
	PRINT bonusA CENDL;
	PRINT RED "Second Bonus Vector:" CENDL;
	PRINT bonusB CENDL;

	PRINT RED "Add First Bonus Vector to the Second Bonus Vector" CENDL;
	bonusB.add(bonusA);
	PRINT bonusB CENDL;
}

void	addTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	Matrix<double> b = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}, {3.3, 4.2, -9.0}};
	Matrix<double> c = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}};
	Matrix<double> d = {{-1.2, -5.0, 6.5, 4.2}};

	Matrix<std::complex<double>> bonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>> bonusB = {
		{std::complex<double>(1,-1), std::complex<double>(0,2)},
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-2,0), std::complex<double>(0,3)}
	};

	PRINT RED "First Matrix:" CENDL;
	PRINT a CENDL;
	PRINT RED "Second Matrix:" CENDL;
	PRINT b CENDL;
	PRINT RED "Third Matrix:" CENDL;
	PRINT c CENDL;
	PRINT RED "Fourth Matrix:" CENDL;
	PRINT d CENDL;
	NLINE;

	PRINT RED "Add First Matrix to the Second Matrix" CENDL;
	b.add(a);
	PRINT b CENDL;
	PRINT RED "Add Fourth Matrix to the Third Matrix" CENDL;
	c.add(d);
	PRINT c CENDL;

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT MAGENTA "First Bonus Matrix:" CENDL;
	PRINT bonusA CENDL;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT bonusB CENDL;

	PRINT MAGENTA "Add First Bonus Matrix to the Second Bonus Matrix" CENDL;
	bonusB.add(bonusA);
	PRINT bonusB CENDL;
}

void	subTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});

	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});
	Vector	<std::complex<double>>bonusB({std::complex<double>(2,-1), std::complex<double>(0,3), std::complex<double>(4,0)});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT MAGENTA "Subtract First Vector to the Second Vector" CENDL;
	b.sub(a);
	PRINT b CENDL;

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT RED "First Bonus Vector:" CENDL;
	PRINT bonusA CENDL;
	PRINT RED "Second Bonus Vector:" CENDL;
	PRINT bonusB CENDL;

	PRINT RED "Subtract First Bonus Vector to the Second Bonus Vector" CENDL;
	bonusB.sub(bonusA);
	PRINT bonusB CENDL;
}

void	subTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	Matrix<double> b = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}, {3.3, 4.2, -9.0}};

	Matrix<std::complex<double>> bonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	Matrix<std::complex<double>> bonusB = {
		{std::complex<double>(1,-1), std::complex<double>(0,2)},
		{std::complex<double>(-1,0), std::complex<double>(2,1),  std::complex<double>(1,-1)},
		{std::complex<double>(4,1),  std::complex<double>(-2,0), std::complex<double>(0,3)}
	};

	PRINT RED "First Matrix:" CENDL;
	PRINT a CENDL;
	PRINT RED "Second Matrix:" CENDL;
	PRINT b CENDL;
	NLINE;

	PRINT RED "Subtract First Matrix to the Second Matrix" CENDL;
	b.sub(a);
	PRINT b CENDL;

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT MAGENTA "First Bonus Matrix:" CENDL;
	PRINT bonusA CENDL;
	PRINT MAGENTA "Second Bonus Matrix:" CENDL;
	PRINT bonusB CENDL;

	PRINT MAGENTA "Subtract First Bonus Matrix to the Second Bonus Matrix" CENDL;
	bonusB.sub(bonusA);
	PRINT bonusB CENDL;
}

void	sclTesterVector() {
	PRINT WHITE " --VECTOR-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});

	Vector	<std::complex<double>>bonusA({std::complex<double>(1,2), std::complex<double>(3,4), std::complex<double>(5,6)});

	PRINT MAGENTA "Vector:" CENDL;
	PRINT a CENDL;
	NLINE;

	for (int i = 1; i <= 3; ++i) {
		PRINT MAGENTA "Scaling Vector by " BLUE AND i CENDL;
		a.scl(i);
		PRINT a CENDL;
	}

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT RED "Bonus Vector:" CENDL;
	PRINT bonusA CENDL;

	PRINT RED "Scale Bonus Vector by 4.2" CENDL;
	bonusA.scl(4.2);
	PRINT bonusA CENDL;
}

void	sclTesterMatrix() {
	PRINT WHITE " --MATRIX-- " CENDL;

	Matrix<double> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

	Matrix<std::complex<double>> bonusA = {
		{std::complex<double>(1,2),  std::complex<double>(3,-1), std::complex<double>(0,4)},
		{std::complex<double>(-1,1), std::complex<double>(2,0),  std::complex<double>(1,-3)},
		{std::complex<double>(0,-2), std::complex<double>(4,1),  std::complex<double>(2,2)}
	};

	PRINT RED "Matrix:" CENDL;
	PRINT a CENDL;
	NLINE;

	for (int i = 1; i <= 3; ++i) {
		PRINT RED "Scaling matrix by " YELLOW AND i CENDL;
		a.scl(i);
		PRINT a CENDL;
	}

	PRINT WHITE "  -BONUS-  " CENDL;
	PRINT RED "Bonus Matrix:" CENDL;
	PRINT bonusA CENDL;

	PRINT RED "Scale Bonus Matrix by 4.2" CENDL;
	bonusA.scl(4.2);
	PRINT bonusA CENDL;
}
