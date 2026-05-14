/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:37 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:42:07 by tchartie         ###   ########.fr       */
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
	Vector(size_t newSize);
	Vector(K *newContent, size_t newSize);
	Vector(std::initializer_list<K> list);
	Vector(const Vector<K>& other);
	Vector<K>& operator=(const Vector<K>& other);
	~Vector(void);

	//Utils
	size_t  size(void) const;
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Vector<U>& v);
	
	K&      	operator[](size_t i);
	const K&	operator[](size_t i) const; 

	//Functions
	void		add(const Vector<K>	&v);
	void		sub(const Vector<K>	&v);
	void		scl(K a);
};

template<typename K>
Vector<K>	linear_combination(std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs);

# include "../../src/Core/Vector.tpp"

# include "../../src/Functions/Vector/Add.tpp"
# include "../../src/Functions/Vector/Substract.tpp"
# include "../../src/Functions/Vector/Scale.tpp"

# include "../../src/Functions/Vector/Linear_Combination.tpp"

#endif //VECTOR_HPP
