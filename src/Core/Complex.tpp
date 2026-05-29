/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:59:19 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/29 15:12:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename K>
static K clean_zero(K val) {
	return (val == static_cast<K>(0)) ? static_cast<K>(0) : val;
}

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

template<typename K>
static double pivot_norm(const K& val) {
	if constexpr (is_complex_v<K>) {
		double r = static_cast<double>(val.real());
		double i = static_cast<double>(val.imag());
		return (r * r + i * i);
	} else {
		return (static_cast<double>(val < 0 ? -val : val));
	}
}
