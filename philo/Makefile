# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 19:48:00 by avolcy            #+#    #+#              #
#    Updated: 2024/02/17 22:45:59 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
RM = rm -rf
HEADER = philo.h
HEADER1 = struct.h
HEADER2 = macros.h
FLAG = -Wall -Wextra -Werror

#========|_PATH_|=========#
INC = ./inc/$(HEADER)
INC += ./inc/$(HEADER1)
INC += ./inc/$(HEADER2)

SRCDIR = ./srcs/
OBJDIR = ./obj/

SRC = $(SRCDIR)philo.c $(SRCDIR)utils.c $(SRCDIR)init.c $(SRCDIR)dinner.c\
	  $(SRCDIR)actions.c $(SRCDIR)getters.c $(SRCDIR)setters.c

OBJ = $(addprefix $(OBJDIR), $(SRC:$(SRCDIR)%.c=%.o))

#=========|_TARGETS_|=======#

all : $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@$(CC) $(FLAG) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME) : $(OBJ) $(INC) Makefile 
	@$(CC) $(FLAG) $(OBJ) -o $@
	@$(call display_compiling)
	@printf "\033[1;32mphilo compiled successfuly ! ✅\n\033[m"
	@sleep 2

.PHONY: all clean fclean re

#====|_COMPILING_FUNCTION_|====#
define display_compiling
	@printf "\033[1;36mCompiling .\r"
	@sleep 1
	@printf "Compiling . .\r"
	@sleep 1
	@printf "Compiling . . .\r\033[m"
	@sleep 2
endef
#======|_DELETING_FUNCTION_|===#
define display_deleting
	@printf  " \033[1;33mdeleting .\r"
	@sleep 1
	@printf  " deleting . .\r"
	@sleep 1
	@printf  " deleting . . .\r\033[m"
	@sleep 1
endef
#=========|_COLORS_|========#s

D = \033[m
R = \033[1;31m
G = \033[1;32m
Y = \033[1;33m
B = \033[1;34m
T = \033[1;35m
C = \033[1;36m
O = \033[38;5;208m

#=========|_CLEAN_UP_|========#
clean :
	@$(RM) $(OBJDIR)
	@$(call display_deleting)
	@sleep 1
	@printf "\033[1;36mObjects are deleted ! ✅\n\033[m"
fclean : clean
	@$(RM) $(NAME)
	@$(call display_deleting)
	@sleep 1
	@printf "\033[38;5;208mExecutable are deleted ! ✅\n\033[m"
re : fclean all
