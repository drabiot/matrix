/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Multiplication.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:07:40 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/20 14:26:11 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A ∈ R^(m×n), u ∈ R^n
// Time complexity:  O(nm) — double loop i∈[0,m) j∈[0,n)
// Space complexity: O(m)
template<typename K>
Vector<K> Matrix<K>::mul_vec(std::initializer_list<K> vec) {
    K result[this->_rows];

    for (size_t i = 0; i < this->_rows; ++i) {
        result[i] = 0;
        for (size_t j = 0; j < this->_cols; ++j)
            result[i] = std::fma(this->_content[i][j], vec.begin()[j], result[i]);
    }

    return (Vector<K>(result, this->_rows));
}

// A ∈ R^(m×n), u ∈ R^n
// Time complexity:  O(nm) — double loop i∈[0,m) j∈[0,n)
// Space complexity: O(m)
template<typename K>
Vector<K>	Matrix<K>::mul_vec(Vector<K> vec) {
    K result[this->_rows];

    for (size_t i = 0; i < this->_rows; ++i) {
        result[i] = 0;
        for (size_t j = 0; j < this->_cols; ++j)
            result[i] = std::fma(this->_content[i][j], vec[j], result[i]);
    }

    return (Vector<K>(result, this->_rows));
}


template<typename K>
Matrix<K>	Matrix<K>::mul_vec(Matrix<K> mat) {
	return (mat);
}
