NAME := my_lib.a
SUBDIRS := libft string

AR := ar
ARFLAGS := rcs
TMP_DIR := .build

all: $(NAME)

$(NAME):
	@mkdir -p $(TMP_DIR)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done
	@echo "→ Collecting object files into $(NAME)..."
	@cp libft/libft.a $(TMP_DIR)/
	@cp string/string.a $(TMP_DIR)/
	@cd $(TMP_DIR) && ar x libft.a && ar x string.a
	@$(AR) $(ARFLAGS) $(NAME) $(TMP_DIR)/*.o
	@rm -rf $(TMP_DIR)
	@echo "✓ Done: $(NAME)"

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	@rm -rf $(TMP_DIR)

fclean: clean
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
