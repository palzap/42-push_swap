# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleal <pleal@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 08:46:18 by pealexan          #+#    #+#              #
#    Updated: 2023/02/01 09:18:11 by pleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
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

#--------COMMANDS--------#
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

OBJ = ${SRC:.c=.o}

#---------RULES---------#
.c.o:
		$(CC) $(CFLAGS) -c -I$(HEADERDIR) $< -o ${<:.c=.o}

all: 		$(NAME)

$(LIBFT):
		cd $(LIBFTDIR) && $(MAKE)
	
$(NAME): 	$(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) -o $(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)
		cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
		$(RM) $(NAME) $(LIBFT)
		cd $(LIBFTDIR) && $(MAKE) fclean
	
aclean: all clean

re: fclean all
