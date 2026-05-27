/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matlib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:51:03 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/27 18:20:17 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATLIB_HPP
# define MATLIB_HPP

# include <cmath>
# include <complex>
# include <type_traits>

template<typename A, typename B, typename C>
inline auto fma_wrapper(const A& a, const B& b, const C& c) {
	using T = std::common_type_t<A, B, C>;

	if constexpr (std::is_floating_point_v<T>)
		return std::fma(
			static_cast<T>(a),
			static_cast<T>(b),
			static_cast<T>(c)
		);
	else
		return (static_cast<T>(a) * static_cast<T>(b) + static_cast<T>(c));
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
