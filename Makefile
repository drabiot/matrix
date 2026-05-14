# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 19:56:04 by tchartie          #+#    #+#              #
#    Updated: 2026/05/14 17:28:50 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME				=	tester

#========= COMPILATOR =========#

CC					=	c++

#=========== FLAGS ============#

CFLAGS				=	-Wall -Wextra -Werror -g -std=c++17

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
						./inc/Functions/

INC_DIR				:=	$(addprefix -I, $(INC_DIR))

DIR					=	ressources/
NAMES				=	main.cpp \
						ex00Tester.cpp \
						ex01Tester.cpp

TEST				=	$(addprefix $(DIR), $(NAMES))

OBJ_DIR 			= 	obj/
OBJ_NAME			=	$(NAMES:.cpp=.o)
OBJ					=	$(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))


all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Tester successfully compiled! $(BASE_COLOR)"

$(OBJ_DIR)%.o:$(DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)Objects files cleaned! $(BASE_COLOR)"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(CYAN)Tester cleaned! $(BASE_COLOR)"

re: fclean all

.PHONY:		all clean fclean re