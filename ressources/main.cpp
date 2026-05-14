/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 15:58:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "tester.hpp"

int	main(void) {
	PRINT WHITE " --VEC. MAT. INIT-- " CENDL;

	double	vecA[] = {1, 2, 3, 4};
	double	vecB[] = {-6.0, 2.6, -4.2, 8.1};

	Vector	<double>a(vecA, 4);
	Vector	<double>b(vecB, 4);

	PRINT MAGENTA "First Vector:" CENDL;
	PRINT a CENDL;
	PRINT MAGENTA "Second Vector:" CENDL;
	PRINT b CENDL;

	double	row0A[] = {1.0, 2.0, 3.0};
	double	row1A[] = {4.0, 5.0, 6.0};
	double	row2A[] = {7.0, 8.0, 9.0};
	double	*matA[] = {row0A, row1A, row2A};

	double	row0B[] = {2.5, 4.4, 2.9};
	double	row1B[] = {-1.2, -5.0, 6.5};
	double	row2B[] = {3.3, 4.2, -9.0};
	double	*matB[] = {row0B, row1B, row2B};

	Matrix<double> m1(matA, 3, 3);
	Matrix<double> m2(matB, 3, 3);
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

	return (0);
}
