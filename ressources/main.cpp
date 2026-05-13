/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 19:25:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int	main(void) {
	Vector	a;

	int		values[] = {1, 2, 3, 4};
	Vector	b(values, 4);

	a.displayVector();
	b.displayVector();

	return (0);
}
