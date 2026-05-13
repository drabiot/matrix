# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 18:34:44 by tchartie          #+#    #+#              #
#    Updated: 2026/05/13 19:16:54 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME				= 	libmatrix.a

NAME_TEST			=	tester

#========= COMPILATOR =========#

CC					=	c++

#=========== FLAGS ============#

CFLAGS				=	-Wall -Wextra -Werror -g -std=c++98

#=========== COLOR ============#

BASE_COLOR 			=	\033[0;39m
GRAY 				=	\033[0;90m
RED 				=	\033[0;91m
GREEN 				=	\033[0;92m
YELLOW 				=	\033[0;93m
BLUE 				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN 				=	\033[0;96m
WHITE				=	\033[0;97m

#========== SOURCES ===========#

INC_DIR				= 	./inc/ \
						./inc/Core/ \
						./inc/Functions	/

INC_DIR				:=	$(addprefix -I, $(INC_DIR))

SRC_DIR 			=	src/
SRC_NAMES 			=	Core/Vector.cpp

TEST_DIR			=	ressources/
TEST_NAMES			=	main.cpp

SRC 				=	$(addprefix $(SRC_DIR), $(SRC_NAMES))

TEST				=	$(addprefix $(TEST_DIR), $(TEST_NAMES))

OBJ_DIR 			= 	obj/
OBJ_NAME 			= 	$(SRC_NAMES:.cpp=.o)
OBJ_NAME_B			=	$(SRC_NAMES_B:.cpp=.o)
OBJ_NAME_T			=	$(TEST_NAMES:.cpp=.o)
OBJ 				= 	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
OBJ_TEST			=	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME_T))


all:		$(NAME)

$(NAME):	$(OBJ)
	@ar -rcs $(NAME) $(OBJ) 
	@echo "$(GREEN)matrix successfully compiled! $(BASE_COLOR)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	@echo "$(MAGENTA)Compiling: $< $(BASE_COLOR)"

$(OBJ_DIR)%.o:$(TEST_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"

tester:		all $(OBJ_TEST)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_TEST) -L. -lmatrix -o $(NAME_TEST) 
	@echo "$(GREEN)Tester successfully compiled! $(BASE_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)matrix objects files cleanned! $(BASE_COLOR)"

fclean:		clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(NAME_TEST)
	@echo "$(CYAN)matrix executable file$(BLUE)" $(NAME) "$(CYAN)&$(BLUE) "$(NAME_BONUS)" $(CYAN)cleanned!$(BASE_COLOR)"
	@echo "$(MAGENTA)Tester objects files cleanned! $(BASE_COLOR)"

re: fclean all 

.PHONY :	all test clean fclean re