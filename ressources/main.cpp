/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:35 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/26 16:03:14 by tchartie         ###   ########.fr       */
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
		PRINT BLUE "Here all of the function:\n" CYAN "  - add\n  - sub\n  - scl\n  - linear_combination\n  - linear_interpolation\n  - dot_product\n  - cosine\n  - cross_product\n  - matrix_multiplication\n  - trace\n  - transpose\n  - row-echelon_form\n  - determinant\n  - inverse\n  - rank" CENDL;
		return (0);
	}

	try {
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
		if (all || (argc > 1 && str(argv[1]) == "norm")) {
			PRINT WHITE " --NORM TESTER-- " CENDL;
			normTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "cosine")) {
			PRINT WHITE " --COSINE TESTER-- " CENDL;
			cosineTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "cross_product")) {
			PRINT WHITE " --CROSS PRODUCT TESTER-- " CENDL;
			cross_productTester();
		}
		if (all || (argc > 1 && (str(argv[1]) == "matrix_multiplication" || str(argv[1]) == "linear_map"))) {
			PRINT WHITE " --MATRIX MULTIPLICATION TESTER-- " CENDL;
			matrix_multiplicationTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "trace")) {
			PRINT WHITE " --TRACE TESTER-- " CENDL;
			traceTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "transpose")) {
			PRINT WHITE " --TRANSPOSE TESTER-- " CENDL;
			transposeTester();
		}
		if (all || (argc > 1 && (str(argv[1]) == "row-echelon_form" || str(argv[1]) == "row_echelon_form"))) {
			PRINT WHITE " --ROW ECHELON FORM TESTER-- " CENDL;
			row_echelon_formTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "determinant")) {
			PRINT WHITE " --DETERMINANT TESTER-- " CENDL;
			determinantTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "inverse")) {
			PRINT WHITE " --INVERSE TESTER-- " CENDL;
			inverseTester();
		}
		if (all || (argc > 1 && str(argv[1]) == "rank")) {
			PRINT WHITE " --RANK TESTER-- " CENDL;
			rankTester();
		}
	} catch (const std::exception &e) {
		ERROR RED AND e.what() CENDL;
	}
	return (0);
}
