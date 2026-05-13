/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:37 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/13 20:15:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils.hpp"

template<typename K>
class	Vector {
private:
	size_t	_size;
	K		*_content;

public:
	Vector(void);
	Vector(K *newContent, size_t newSize);
	~Vector(void);

	//Utils
	void	displayVector(void);

	//Functions
	void	add(const Vector<K>	&v);
	void	sub(const Vector<K>	&v);
	void	scl(K a);
};

# include "../../src/Core/Vector.tpp"

# include "../../src/Functions/Add.tpp"
# include "../../src/Functions/Substract.tpp"
# include "../../src/Functions/Scale.tpp"

#endif //VECTOR_HPP
