GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m
CLEAR		= \033[K\r
NAME		= string.a
INCLUDES	= -I../headers
CC			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
SRC			= src/ \
OBJ			= $(patsubst src/%.c, obj/%.o, $(SRC))
RM			= rm -rf

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(CLEAR)$(GREEN)$(BOLD)String.a done!$(RESET)"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $< $(INCLUDES) -o $@
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
