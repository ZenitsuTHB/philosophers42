# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 19:48:00 by avolcy            #+#    #+#              #
#    Updated: 2023/12/27 20:37:30 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
EXEC = philo
NAME = philo.a
HEADER = philo.h
BUILT_LIB = ar rc
FLAG = -Wall -Wextra -Werror

#========|_PATH_|=========#
INC = ./inc/$(HEADER)
SRCD = srcs/
OBJD = .temp/
#_________________________#

SRC = $(SRCD)philo.c $(SRCD)utils.c

OBJ = $(addprefix $(OBJD), $(SRC:$(SRCD)%.c=%.o))

#=========|_TARGETS_|=======#

all : $(EXEC)

.temp :
	@mkdir -p .temp
#__________________________#

$(OBJD)%.o: $(SRCD)%.c $(INC) | .temp
	@$(CC) $(FLAG) -c -o $@ $<


$(EXEC) : $(NAME) $(INC) 
	$(CC) $(FLAG) $^ -o $@
	
$(NAME) : $(OBJD) $(INC) Makefile
	@$(BUILT_LIB) $@ $^

.PHONY: all clean fclean re

#=========|_CLEAN_UP_|========#
clean :
	@$(RM) $(OBJD)

fclean : clean
	@$(RM) $(EXEC) $(NAME)

re : fclean all
#_______________________________________#
