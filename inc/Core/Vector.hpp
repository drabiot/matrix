/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:37 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 19:25:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils.hpp"

class	Vector {
private:
	size_t	_size;
	int		*_content;

public:
	Vector(void);
	Vector(int *newContent, size_t newSize);
	~Vector(void);

	void	displayVector(void);
};

#endif //VECTOR_HPP
