/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 20:16:14 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int	main(void) {
	double	valuesA[] = {1, 2, 3, 4};
	double	valuesB[] = {-6.0, 2.6, -4.2, 8.1};

	Vector	<double>a(valuesA, 4);
	Vector	<double>b(valuesB, 4);

	a.displayVector();
	b.displayVector();

	b.add(a);
	b.displayVector();

	b.sub(a);
	b.displayVector();

	b.scl(3);
	b.displayVector();

	return (0);
}
