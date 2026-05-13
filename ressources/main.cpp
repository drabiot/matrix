/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 21:13:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Matrix.hpp"

int	main(void) {
	double	vecA[] = {1, 2, 3, 4};
	double	vecB[] = {-6.0, 2.6, -4.2, 8.1};

	Vector	<double>a(vecA, 4);
	Vector	<double>b(vecB, 4);

	PRINT a CENDL;
	PRINT b CENDL;

	b.add(a);
	PRINT b CENDL;

	b.sub(a);
	PRINT b CENDL;

	b.scl(3);
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
	PRINT m1 CENDL;
	PRINT m2 CENDL;

	m1.add(m2);
	PRINT m1 CENDL;

	m1.sub(m2);
	PRINT m1 CENDL;

	m1.scl(2);
	PRINT m1 CENDL;

	return (0);
}
