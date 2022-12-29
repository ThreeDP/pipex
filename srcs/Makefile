# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 15:00:16 by dapaulin          #+#    #+#              #
#    Updated: 2022/12/29 15:00:16 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################  COLORS	##################
L_RED			=			'\033[0;31m'
L_REDB			=			'\033[1;31m'
L_WHITE			=			'\033[0;37m'
L_WHITEB		=			'\033[1;37m'
L_YELLOW		=			'\033[0;33m'
L_YELLOWB		=			'\033[1;33m'
L_GREEN			=			'\033[0;32m'
L_GREENB		=			'\033[1;32m'
################ CONFIG		##################
FLAGS			=			-Wall -Wextra -Werror
################ SOURCE		##################
NAME			=			pipex
HEADERS			=			pipex.h minilibft.h
SRCS			=			pipex.c err.c minilibft.c
OBJS			=			$(SRCS:.C=.O)

all:	$(NAME)

%.o: %.c $(HEADERS)
	$(CC)	$(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo	"$(L_GREENB)[**** pipex created ****]$(L_WHITE)"

clean:
	@rm			-f *.o
	@echo	"$(L_GREENB)[**** objects removed ****]$(L_WHITE)"

fclean:
	@rm			-f $(NAME)
	@echo	"$(L_GREENB)[**** exec removed ****]$(L_WHITE)"

re: fclean all

.PHONY: all