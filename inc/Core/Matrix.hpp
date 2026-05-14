/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:40 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/14 17:20:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "utils.hpp"

template<typename K>
class	Matrix {
private:
	size_t	_rows;
	size_t	_cols;
	K		**_content;

public:
	Matrix(void);
	Matrix(K **newContent, size_t newRows, size_t newCols);
	Matrix(const Matrix<K>& other);
	Matrix(std::initializer_list<std::initializer_list<K>> list);
	Matrix<K>& operator=(const Matrix<K>& other);
	~Matrix(void);

	//Utils
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);

	//Functions
	void	add(const Matrix<K>	&m);
	void	sub(const Matrix<K>	&m);
	void	scl(K a);
};

# include "../../src/Functions/Matrix/Add.tpp"
# include "../../src/Functions/Matrix/Substract.tpp"
# include "../../src/Functions/Matrix/Scale.tpp"

# include "../../src/Core/Matrix.tpp"

#endif //MATRIX_HPP
