# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 23:22:35 by rnubia            #+#    #+#              #
#    Updated: 2022/06/03 05:15:53 by rnubia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BNAME		=	checker

HEADER		=	push_swap.h

BHEADER		=	checker_bonus.h		push_swap.h\
				get_next_line.h

SRCS		=	push_swap.c 		args_parser.c\
				stack_data.c		pre_sort.c\
				index_data.c		fine_sort.c\
				cmd_data.c			sort_utils.c\
				ft_split.c			error_utils.c\
									print_prog.c

BSRCS		=	checker_bonus.c		swap_push_bonus.c\
				cmd_exec_bonus.c	rot_revrot_bonus.c\
				check_prog_bonus.c	args_parser.c\
				get_next_line.c		stack_data.c\
				error_utils.c		index_data.c\
				sort_utils.c		cmd_data.c\
				ft_split.c

OBJ			=	$(SRCS:%.c=%.o)

BOBJ		=	$(BSRCS:%.c=%.o)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

RM			=	rm -f

.PHONY		:	all bonus clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

bonus		:	$(BNAME)

$(BNAME)	:	$(BOBJ) $(BHEADER)
				$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

%.o			:	%.c $(BHEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJ) $(BOBJ)

fclean		:	clean
				$(RM) $(NAME) $(BNAME)

re			:	fclean all

# > Steki ya kruchu-verchu, dannie otsortirovat` hochu!

# ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
