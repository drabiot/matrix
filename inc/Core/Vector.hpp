/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:37 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 15:42:51 by tchartie         ###   ########.fr       */
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
	Vector(const Vector<K>& other);
	Vector<K>& operator=(const Vector<K>& other);
	~Vector(void);

	//Utils
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Vector<U>& v);

	//Functions
	void	add(const Vector<K>	&v);
	void	sub(const Vector<K>	&v);
	void	scl(K a);
};

# include "../../src/Core/Vector.tpp"

# include "../../src/Functions/Vector/Add.tpp"
# include "../../src/Functions/Vector/Substract.tpp"
# include "../../src/Functions/Vector/Scale.tpp"

#endif //VECTOR_HPP
