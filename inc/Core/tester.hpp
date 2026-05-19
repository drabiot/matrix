/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:27:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 13:25:46 by tchartie         ###   ########.fr       */
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

#endif //TESTER_HPP
