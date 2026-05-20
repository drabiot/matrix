/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:27:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 15:48:00 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include "Vector.hpp"
# include "Matrix.hpp"

// ex00
void	addTesterVector(void);
void	addTesterMatrix(void);
void	subTesterVector(void);
void	subTesterMatrix(void);
void	sclTesterVector(void);
void	sclTesterMatrix(void);

// ex01
void	linear_combinationTester(void);

// ex02
void	linear_interpolationTester(void);

// ex03
void	dot_productTester(void);

// ex04
void	normTester(void);

// ex05
void	cosineTester(void);

// ex06
void	cross_productTester(void);

// ex07
void	matrix_multiplicationTester(void);

// ex08
void	traceTester(void);

#endif //TESTER_HPP
