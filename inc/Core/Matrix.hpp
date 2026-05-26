/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:16:40 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 15:58:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "utils.hpp"
# include "Vector.hpp"

template<typename K>
class	Matrix {
private:
	size_t	_rows;
	size_t	_cols;
	K		**_content;

public:
	Matrix(void);
	Matrix(size_t size);
	Matrix(size_t newRows, size_t newCols);
	Matrix(K **newContent, size_t newRows, size_t newCols);
	Matrix(const Matrix<K>& other);
	Matrix(std::initializer_list<std::initializer_list<K>> list);
	Matrix<K>& operator=(const Matrix<K>& other);
	~Matrix(void);

	//Utils
	size_t		getRows(void) const;
	size_t		getCols(void) const;
	K**			getContent(void) const;
	bool		isSquare(void);
	K*			operator[](size_t i);
	const K*	operator[](size_t i) const;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);

	//Functions
	void		add(const Matrix<K>	&m);
	void		sub(const Matrix<K>	&m);
	void		scl(K a);

	Vector<K>	mul_vec(std::initializer_list<K> vec);
	Vector<K>	mul_vec(Vector<K> vec);
	Matrix<K>	mul_mat(Matrix<K> mat);

	K			trace(void);
	Matrix<K>	transpose(void);
	Matrix<K>	row_echelon(void);
	K			determinant(void);
	Matrix<K>	inverse(void);
	size_t		rank(void);
};

# include "../../src/Functions/Matrix/Add.tpp"
# include "../../src/Functions/Matrix/Substract.tpp"
# include "../../src/Functions/Matrix/Scale.tpp"

# include "../../src/Functions/Matrix/Matrix_Multiplication.tpp"

# include "../../src/Functions/Matrix/Trace.tpp"

# include "../../src/Functions/Matrix/Transpose.tpp"

# include "../../src/Functions/Matrix/Row_Echelon_Form.tpp"

# include "../../src/Functions/Matrix/Determinant.tpp"

# include "../../src/Functions/Matrix/Inverse.tpp"

# include "../../src/Functions/Matrix/Rank.tpp"

# include "../../src/Core/Matrix.tpp"

#endif //MATRIX_HPP
