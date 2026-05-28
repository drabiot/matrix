/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matlib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:51:03 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/28 13:50:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATLIB_HPP
# define MATLIB_HPP

# include <cmath>
# include <complex>
# include <type_traits>

// Complex Numbers

template<typename T>
struct is_complex : std::false_type {};

template<typename T>
struct is_complex<std::complex<T>> : std::true_type {};

template<typename T>
inline constexpr bool is_complex_v = is_complex<T>::value;

template<typename A, typename B, typename C>
inline auto fma_wrapper(const A& a, const B& b, const C& c) {
	using T = std::common_type_t<A, C>;

	if constexpr (std::is_floating_point_v<T>)
		return (std::fma(static_cast<T>(a), static_cast<T>(b), static_cast<T>(c)));
	else if constexpr (std::is_integral_v<T>)
		return (static_cast<T>(a) * static_cast<T>(b) + static_cast<T>(c));
	else if constexpr (is_complex_v<T>) {
		if constexpr (is_complex_v<B>)
			return (a * b + c);
		else
			return (a * static_cast<typename T::value_type>(b) + c);
	}
	else
		return (a * static_cast<A>(b) + c);
}

# include "Vector.hpp"
# include "Matrix.hpp"

# include "../../src/Functions/Linear_Combination.tpp"
# include "../../src/Functions/Linear_Interpolation.tpp"
# include "../../src/Functions/Cosine.tpp"
# include "../../src/Functions/Cross_Product.tpp"


inline Matrix<float> projection(float fov, float ratio, float near, float far) {
	Matrix<float>	ret(4);
	float			scale;

	scale = 1.0f / tan(fmaf(fov, 0.5f * M_PI / 180.0f, 0.0f));

	ret[0][0] = scale / ratio;
	ret[1][1] = scale;
	ret[2][2] = -far / (far - near);
	ret[2][3] = -1.0f;
	ret[3][2] = -(far * near) / (far - near);
	ret[3][3] = 0.0f;

	return (ret);
}

#endif //MATLIB_HPP
