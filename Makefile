# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 11:06:04 by jjourdan          #+#    #+#              #
#    Updated: 2021/04/07 12:11:52 by jjourdan         ###   ########lyon.fr    #
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

ARG			=	-4099 373 -8311 1137 -6512 -5345 -2498 -7319 -6679 3959 2804 4315 7611 153 2656 -2599 -4031 -5499 7411 -3507 5974 8458 1850 5357 -5186 -1406 -7872 7432 4249 -3362 -2242 2954 1242 7367 3789 -3995 -7856 -7748 149 5236 1093 -2835 6168 4364 -7413 5838 8481 5663 -4686 -3770 8261 -5705 -368 -6191 6659 -1222 -7667 109 -3996 -1529 3048 6945 -4458 749 -8540 2752 6749 -6563 4845 -4141 4153 -2400 -8394 184 7476 -6651 1995 6332 -4107 7727 7851 4001 -5911 -3712 -5772 8747 -644 -7954 -2947 -6388 4042 818 2262 -5119 -1029 5096 677 606 6394 -7507

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