# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 15:00:16 by dapaulin          #+#    #+#              #
#    Updated: 2023/01/25 19:16:05 by dapaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG		##################
FLAGS			=			-Wall -Wextra -Werror
################ SOURCE		##################
NAME			=			pipex
DMLIB			=			./libft/
HEADERS			=			pipex.h $(addprefix $(DMLIB), minilibft.h)
LSRCS			=			ft_calloc.c ft_memset.c ft_split.c ft_strjoin.c\
							ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
							ft_strncmp.c ft_strndup.c
SRCS			=			pipex.c err.c 
OBJS			=			$(addprefix $(DMLIB), $(LSRCS:.c=.o)) $(SRCS:.c=.o)

all:	$(NAME)

%.o: %.c $(HEADERS)
	$(CC)	 -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) 	-g $(OBJS) -o $(NAME)
	@echo	"$(L_GREENB)[**** pipex created ****]$(L_WHITE)"

clean:
	@rm			-f $(OBJS)
	@echo	"$(L_GREENB)[**** objects removed ****]$(L_WHITE)"

fclean: clean
	@rm			-f $(NAME)
	@echo	"$(L_GREENB)[**** exec removed ****]$(L_WHITE)"

re: fclean all

.PHONY: all