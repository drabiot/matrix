/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:47:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester.hpp"

int	main(void) {
	PRINT WHITE " --VEC. MAT. INIT-- " CENDL;

	Vector	<double>a({1, 2, 3, 4});
	Vector	<double>b({-6.0, 2.6, -4.2, 8.1});

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;

	Matrix<double> m1 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	Matrix<double> m2 = {{2.5, 4.4, 2.9}, {-1.2, -5.0, 6.5}, {3.3, 4.2, -9.0}};

	PRINT RED "First Matrix:" CENDL;
	PRINT m1 CENDL;
	PRINT RED "Second Matrix:" CENDL;
	PRINT m2 CENDL;

	PRINT WHITE " --ADD TESTER-- " CENDL;
	addTesterVector(a, b);
	addTesterMatrix(m1, m2);

	PRINT WHITE " --SUB TESTER-- " CENDL;
	subTesterVector(a, b);
	subTesterMatrix(m1, m2);

	PRINT WHITE " --SCL TESTER-- " CENDL;
	sclTesterVector(a, 3);
	sclTesterMatrix(m1, 3);

	PRINT WHITE " --LINEAR COMBINATION TESTER-- " CENDL;
	PRINT linear_combination({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}, {10., -2., 0.5}) CENDL;
	PRINT linear_combination({{1., 2., 3.}, {0., 10., -100.}}, {10., -2.}) CENDL;

	return (0);
}
