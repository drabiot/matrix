/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/19 13:24:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "matlib.hpp"
#include "tester.hpp"

int	main(int argc, char **argv) {
	bool	all = (argc == 1) ? true : false;

	if (argc > 1 && str(argv[1]) == "help") {
		NLINE;
		PRINT MAGENTA "If you want to test everything at once type " RED "./tester" MAGENTA " without argument" CENDL;
		NLINE;
		PRINT GREEN "If you want to one specific function type " YELLOW "./tester <name_of_your_function>" CENDL;
		PRINT BLUE "Here all of the function:\n" CYAN "  - add\n  - sub\n  - scl\n  - linear_combination\n  - linear_interpolation\n  - dot_product" CENDL;
		return (0);
	}

	if (all || (argc > 1 && str(argv[1]) == "add")) {
		PRINT WHITE " --ADD TESTER-- " CENDL;
		addTesterVector();
		addTesterMatrix();
	}
	if (all || (argc > 1 && str(argv[1]) == "sub")) {
		PRINT WHITE " --SUBTRACT TESTER-- " CENDL;
		subTesterVector();
		subTesterMatrix();
	}
	if (all || (argc > 1 && str(argv[1]) == "scl")) {
		PRINT WHITE " --SCALE TESTER-- " CENDL;
		sclTesterVector();
		sclTesterMatrix();
	}
	if (all || (argc > 1 && str(argv[1]) == "linear_combination")) {
		PRINT WHITE " --LINEAR COMBINATION TESTER-- " CENDL;
		linear_combinationTester();
	}
	if (all || (argc > 1 && str(argv[1]) == "linear_interpolation")) {
		PRINT WHITE " --LINEAR INTERPOLATION TESTER-- " CENDL;
		linear_interpolationTester();
	}
	if (all || (argc > 1 && str(argv[1]) == "dot_product")) {
		PRINT WHITE " --DOT PRODUCT TESTER-- " CENDL;
		dot_productTester();
	}
	return (0);
}
