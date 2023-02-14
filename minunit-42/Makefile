################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ CONFIG	TESTS	##################
DIR				=			../srcs/
LSRCS			=			$(addprefix $(DIR)libft/, ft_calloc.c ft_memset.c ft_split.c ft_strjoin.c\
							ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
							ft_strncmp.c ft_strndup.c)
DIR_OUTS		=			./outs/
EXEC_OUTS		=			$(wildcard $(DIR_OUTS)*)
YOUR_FILES		=			$(addprefix $(DIR), err.c pids.c utils.c) # Add your files with the function you can test
TESTS			=			handle_cmd_test # Add your test names without .c
HEADERS_TEST 	= 			minunit.h
################ CONFIG YOUR PROJECT #############
FLAGS 			= 			-Wall -Werror -Wextra
################ RULES		######################

all: 		$(TESTS) $(EXEC_OUTS)
	@echo $(EXEC_OUTS)

$(TESTS): $(HEADERS)
	$(CC)	-g $(addsuffix .c, $@) $(YOUR_FILES) $(LSRCS) -o $(addprefix $(DIR_OUTS), $@)

$(EXEC_OUTS):
	@echo  "$(L_YELLOWB)$@:$(L_WHITE) " && $@

clean:
	@rm			-f $(SRCS:.c=.o)

fclean:			clean
	@rm 		-f $(EXEC_OUTS)
	@cd 		$(DIR) && $(MAKE) $@

re: fclean all

.PHONY: re fclean clean all $(TESTS) $(EXEC_OUTS)