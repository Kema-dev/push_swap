# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 11:06:04 by jjourdan          #+#    #+#              #
#    Updated: 2021/03/31 17:04:21 by jjourdan         ###   ########lyon.fr    #
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

RM			=	rm -f

MAKE_SUB	=	-make -C

ARG			=	3 1 5 4 2

all:
				@$(MAKE_SUB) check
				@$(MAKE_SUB) push

norme:
				printf "\033c"
				@norminette libs
				@$(MAKE_SUB) check norme
				@$(MAKE_SUB) push norme

norme_check:
				printf "\033c"
				@norminette libs
				@$(MAKE_SUB) check norme_check
				@$(MAKE_SUB) push norme_check

test:			all
				ARG="$(ARG)"; ./push/push_swap $$ARG | ./check/checker $$ARG

count:			all
				ARG="$(ARG)"; ./push/push_swap $$ARG | wc -l

leaks:			all
				printf "\033c"
				ARG="$(ARG)"; leaks --atExit -- ./push/push_swap $$ARG | leaks --atExit -- ./check/checker $$ARG

push:			all
				ARG="$(ARG)"; ./push/push_swap $$ARG

clean:
				@$(MAKE_SUB) check clean
				@$(MAKE_SUB) push clean

fclean:
				@$(MAKE_SUB) check fclean
				@$(MAKE_SUB) push fclean
				@$(RM) checker
				@$(RM) push_swap

re:				fclean all

.PHONY: all, libs, norme, norme_check, test, count, leaks, clean, fclean, re