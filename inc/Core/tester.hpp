/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:27:32 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:48:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include "Vector.hpp"
# include "Matrix.hpp"

//ex00
void	addTesterVector(Vector <double>a, Vector <double>b);
void	addTesterMatrix(Matrix <double>a, Matrix <double>b);
void	subTesterVector(Vector <double>a, Vector <double>b);
void	subTesterMatrix(Matrix <double>a, Matrix <double>b);
void	sclTesterVector(Vector <double>a, int scaling);
void	sclTesterMatrix(Matrix <double>a, int scaling);

#endif //TESTER_HPP
