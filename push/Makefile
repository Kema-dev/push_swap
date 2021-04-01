# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 10:55:11 by jjourdan          #+#    #+#              #
#    Updated: 2021/04/01 11:27:52 by jjourdan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# *******************************    POST-IT    ****************************** #
#                                                                              #
#			## $@ 	Le nom de la cible										   #
#			## $< 	Le nom de la première dépendance						   #
#			## $^ 	La liste des dépendances								   #
#			## $? 	La liste des dépendances plus récentes que la cible		   #
#			## $* 	Le nom du fichier sans suffixe							   #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-Wall -Wextra -fsanitize=address

DEBUG_OUT	=	debug.out

INCS_DIR	=	includes/

INCS		=	push_swap.h

INCS_FULL	=	$(addprefix $(INCS_DIR), $(INCS))

SRCS_DIR	=	sources/

SRCS		=	ft_push_main.c \
				ft_push_list_manip.c \
				ft_push_operation_s.c \
				ft_push_operation_p.c \
				ft_push_operation_r.c \
				ft_push_operation_rr.c \
				ft_push_get_commands.c \
				ft_push_sort_values.c \
				ft_push_3_val.c \
				ft_push_5_val.c \
				ft_push_100_val.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

MAKE_SUB	=	make -C

LIBS_DIR	=	../libs/

LIBS		=	libkema/

LIBS_FULL	=	$(addprefix $(LIBS_DIR), $(LIBS))

LIBS_FILES	=	../libs/libkema/libkema.a

all:			libraries $(NAME)
				@cp $(NAME) ..

%.o: 			%.c $(INCS_FULL)
				$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME): 		$(OBJS) $(LIBS_FILES)
				$(CC) -I $(INCS_DIR) $(OBJS) $(LIBS_FILES) -o $(NAME)

libraries:
				$(foreach lib,$(LIBS_FULL), $(MAKE_SUB) $(lib))

norme:			fclean
				@norminette $(SRCS_DIR)
				@norminette $(INCS_DIR)

norme_check:	fclean
				@norminette $(SRCS_DIR) | grep " KO!" | wc -l
				@norminette $(INCS_DIR) | grep " KO!" | wc -l

debug:			libraries $(OBJS)
				printf "\033c"
				$(CC) -I $(INCS_DIR) $(DEBUG_FLAGS) $(OBJS) $(LIBS_FILES) -o $(DEBUG_OUT)
				printf "\033c"
				ARG="1 2 3 4 5 6 7"; ./push_swap $$ARG

test:			libraries $(OBJS)
				$(CC) -I $(INCS_DIR) $(FLAGS) $(OBJS) $(LIBS_FILES) -o $(NAME)
				printf "\033c"
				ARG="1 2 3 4 5 6 7"; ./push_swap $$ARG

leaks:			all
				leaks --atExit -- ARG="1 2 3 4 5 6 7"; ./push_swap $$ARG

clean:
				@$(RM) $(OBJS)
				@$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) clean)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(DEBUG_OUT)
				@$(foreach lib_dir,$(LIBS_FULL), $(MAKE_SUB) $(lib_dir) fclean)

re:				fclean all

.PHONY: all, libs, norme, norme_check, debug, test, leaks, clean, fclean, re