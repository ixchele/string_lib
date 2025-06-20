GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m
CLEAR		= \033[K\r
NAME		= string.a
INCLUDES	= -I./headers/
CC			= cc -c -Wall -Wextra -Werror -I./headers/ -I../libft/headers/
AR			= ar rcs
SRC			= src/string1.c \
			  src/string2.c \
			  src/string3.c \
			  src/string5.c \
			  src/string6.c \
			  src/string7.c
OBJ			= $(patsubst src/%.c, obj/%.o, $(SRC))
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CLEAR)$(GREEN)$(BOLD)String.a done!$(RESET)"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $< -o $@
	@echo -n "$(YELLOW)	inserting $@...$(RESET)$(CLEAR)"
	@$(AR) $(NAME) $@

clean :
	@echo "$(RED)Cleaning $(OBJ_DIR)...$(RESET)"
	@${RM} obj

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@${RM} $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
