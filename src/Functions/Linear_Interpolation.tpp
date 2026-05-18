/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linear_Interpolation.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:32:00 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/18 21:55:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Time complexity:  O(1)
// Space complexity: O(1)
template<typename V>
V lerp(V u, V v, float t) {
    return std::fma(v - u, t, u);
}

// D = dimension of vectors
// Time complexity:  O(D)
// Space complexity: O(D)
template<typename V>
Vector<V> lerp(Vector<V> u, Vector<V> v, float t) {
    Vector<V> result(u.size());
    for (size_t i = 0; i < u.size(); ++i)
        result[i] = std::fma(v[i] - u[i], t, u[i]);
    return result;
}

// R = rows, C = cols
// Time complexity:  O(n) where n = R * C
// Space complexity: O(n) where n = R * C
template<typename V>
Matrix<V> lerp(Matrix<V> u, Matrix<V> v, float t) {
    Matrix<V> result(u.getRows(), u.getCols());
    for (size_t i = 0; i < u.getRows(); ++i)
        for (size_t j = 0; j < u.getCols(); ++j)
            result[i][j] = std::fma(v[i][j] - u[i][j], t, u[i][j]);
    return result;
}
