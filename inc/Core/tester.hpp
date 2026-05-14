/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:27:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:29:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include "Vector.hpp"
# include "Matrix.hpp"

void	addTesterVector(Vector <double>a, Vector <double>b);
void	addTesterMatrix(Matrix <double>a, Matrix <double>b);
void	subTesterVector(Vector <double>a, Vector <double>b);
void	subTesterMatrix(Matrix <double>a, Matrix <double>b);
void	sclTesterVector(Vector <double>a, int scaling);
void	sclTesterMatrix(Matrix <double>a, int scaling);

void	linearCombinationTester(void);

#endif //TESTER_HPP
