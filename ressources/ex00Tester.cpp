/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:19:53 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 15:58:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Matrix.hpp"

void	addTesterVector(Vector <double>a, Vector <double>b) {
	PRINT MAGENTA "    -Vector-  " CENDL;

	NLINE;

	PRINT MAGENTA "Add First Vec. to the Second Vec." CENDL;
	b.add(a);
	PRINT b CENDL;

}

void	addTesterMatrix(Matrix <double>a, Matrix <double>b) {
	PRINT RED "    -Matrix-  " CENDL;

	NLINE;

	PRINT RED "Add First Mat. to the Second Mat." CENDL;
	b.add(a);
	PRINT b CENDL;

}

void	subTesterVector(Vector <double>a, Vector <double>b) {
	PRINT MAGENTA "    -Vector-  " CENDL;

	NLINE;

	PRINT MAGENTA "Subtract First Vec. to the Second Vec." CENDL;
	b.sub(a);
	PRINT b CENDL;

}

void	subTesterMatrix(Matrix <double>a, Matrix <double>b) {
	PRINT RED "    -Matrix-  " CENDL;

	NLINE;

	PRINT RED "Subtract First Mat. to the Second Mat." CENDL;
	b.sub(a);
	PRINT b CENDL;

}

void	sclTesterVector(Vector <double>a, int scaling) {
	PRINT MAGENTA "    -Vector-  " CENDL;

	NLINE;

	PRINT MAGENTA "Scaling First vec by " BLUE AND scaling CENDL;
	a.scl(scaling);
	PRINT a CENDL;

}

void	sclTesterMatrix(Matrix <double>a, int scaling) {
	PRINT RED "    -Matrix-  " CENDL;

	NLINE;

	PRINT RED "Scaling First mat by " YELLOW AND scaling CENDL;
	a.scl(scaling);
	PRINT a CENDL;

}
