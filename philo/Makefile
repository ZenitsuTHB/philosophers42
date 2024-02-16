# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 19:48:00 by avolcy            #+#    #+#              #
#    Updated: 2024/02/16 21:01:01 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
RM = rm -rf
HEADER = philo.h
HEADER1 = struct.h
HEADER2 = macros.h
FLAG = -Wall -Wextra -Werror -fsanitize=thread

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
	@printf  "philo compiled successfuly ! ✅\n"

.PHONY: all clean fclean re

#====|_COMPILING_FUNCTION_|====#
define display_compiling
	@printf  " Compiling .\r"
	@sleep 1
	@printf  " Compiling . .\r"
	@sleep 1
	@printf  " Compiling . . .\r"
	@sleep 1
endef
#======|_DELETING_FUNCTION_|===#
define display_deleting
	@printf  " deleting .\r"
	@sleep 1
	@printf  " deleting . .\r"
	@sleep 1
	@printf  " deleting . . .\r"
	@sleep 1
endef
#=========|_CLEAN_UP_|========#s
clean :
	@$(RM) $(OBJDIR)
	@$(call display_deleting)
	@printf "Objects are deleted ! ✅\n"
fclean : clean
	@$(RM) $(NAME)
	@$(call display_deleting)
	@printf "Executable are deleted ! ✅\n"
re : fclean all
