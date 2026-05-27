/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14Tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:28:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 15:23:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matlib.hpp"

void	projectionTester() {
	PRINT RED "90, 1, 0.1, 100" CENDL;
	projection(90, 1, 0.1, 100).displayMatrix();
	NLINE;

	PRINT RED "45, 1, 0.1, 100" CENDL;
	projection(45, 1, 0.1, 100).displayMatrix();
	NLINE;

	PRINT RED "120, 1, 0.1, 100" CENDL;
	projection(120, 1, 0.1, 100).displayMatrix();
	NLINE;

	PRINT RED "45, 5, 0.1, 100" CENDL;
	projection(45, 5, 0.1, 100).displayMatrix();
	NLINE;

	PRINT RED "45, 1, 0.1, 2" CENDL;
	projection(45, 1, 0.1, 2).displayMatrix();
	NLINE;
}
