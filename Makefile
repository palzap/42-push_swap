# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:26:28 by pealexan          #+#    #+#              #
#    Updated: 2023/02/02 12:26:30 by pealexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker
LIBFT		= libft.a

#----------DIRS----------#
SRCDIR = ./src/
LIBFTDIR = ./libft/
HEADERDIR = ./headers/

SRC = 	src/best_move.c \
	src/do_move.c \
	src/get_stack.c \
	src/get_values.c \
	src/indexing.c \
	src/push.c \
	src/push_swap.c \
	src/reverse_rotate.c \
	src/rotate.c \
	src/sort.c \
	src/swap.c \
	src/utils.c \
		
CHECKER_SRC = 	checker_src/checker.c \
		checker_src/get_stack.c \
		checker_src/push.c \
		checker_src/reverse_rotate.c \
		checker_src/rotate.c \
		checker_src/swap.c \
		checker_src/utils.c \

#--------COMMANDS--------#
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

OBJ = ${SRC:.c=.o}
OBJ_CHECKER = ${CHECKER_SRC:.c=.o}

#---------RULES---------#
.c.o:
		$(CC) $(CFLAGS) -c -I$(HEADERDIR) $< -o ${<:.c=.o}

all: 		$(NAME)

$(LIBFT):
		cd $(LIBFTDIR) && $(MAKE)
	
$(NAME): 	$(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) -o $(NAME)

bonus:		$(OBJ_CHECKER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFTDIR)$(LIBFT) -o $(BONUS)

clean:
		@$(RM) $(OBJ) $(OBJ_CHECKER)
		@cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
		@$(RM) $(NAME) $(BONUS) $(LIBFT)
		@cd $(LIBFTDIR) && $(MAKE) fclean
	
aclean: all clean

re: fclean all
