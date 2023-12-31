# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 19:48:00 by avolcy            #+#    #+#              #
#    Updated: 2023/12/31 17:15:35 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
RM = rm -rf
HEADER = philo.h
FLAG = -Wall -Wextra -Werror

#========|_PATH_|=========#
INC = ./inc/$(HEADER)

SRCDIR = ./srcs/
OBJDIR = ./obj/

SRC = $(SRCDIR)philo.c $(SRCDIR)utils.c
OBJ = $(addprefix $(OBJDIR), $(SRC:$(SRCDIR)%.c=%.o))

#=========|_TARGETS_|=======#

all : $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@$(CC) $(FLAG) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME) : $(OBJ) $(INC)
	$(CC) $(FLAG) $(OBJ) -o $@ 

.PHONY: all clean fclean re

#=========|_CLEAN_UP_|========#
clean :
	@$(RM) $(OBJDIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

#CC = cc
#NAME = philo
#RM = rm -rf
#HEADER = philo.h
#FLAG = -Wall -Wextra -Werror
#
##========|_PATH_|=========#
#INC = ./inc/$(HEADER)
#
#SRC = philo.c utils.c
#
#OBJ = $(SRC:.c=.o)
#
##=========|_TARGETS_|=======#
#
#all : $(NAME)
#
#
#%.o: %.c $(INC) 
#	@$(CC) $(FLAG) -c $< -o $@ 
#
#$(NAME) : $(OBJ) $(INC) 
#	$(CC) $(FLAG) -o $@ $^
#
#.PHONY: all clean fclean re
#
##=========|_CLEAN_UP_|========#
#clean :
#	@$(RM) $(OBJ) 
#
#fclean : clean
#	@$(RM) $(NAME) 
#
#re : fclean all
##_______________________________________#
