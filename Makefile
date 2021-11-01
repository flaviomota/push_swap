# --- push swap --- #
NAME	=	push_swap
SRC_A	=	push_swap.c \
			libft_utils.c \
			certify.c \
			guidelines.c \
			sort_out.c \
			sort_out_utils.c \
			sort_out_utils_2.c \

# --- checker --- #
CHECKER	=	checker
SRC_B	=	checker.c \
			libft_utils.c \
			certify.c \
			guidelines.c \
			sort_out.c \
			sort_out_utils.c \
			sort_out_utils_2.c \
			get_next_line.c

# --- libft --- #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# --- INC --- #
INC		=	-Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/stack \
			-I$(LIBFT_DIR)/get_next_line

# --- compiling --- #
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

# -- colors --- #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

# --- debugger --- #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

# --- fsanitize --- #
ifeq ($(SANITIZE), 1)
D_FLAG	=	-fsanitize=address -g
endif

mandatory:	$(NAME)
bonus:		$(CHECKER)

$(NAME):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_A) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) push_swap ready.\n"

all:		$(NAME) $(CHECKER)

$(CHECKER):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_B) $(INC) $(LIBFT) -o $(CHECKER)
	@printf "$(_SUCCESS) checker ready.\n"

clean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)

fclean:
	@ $(RM) $(NAME) $(CHECKER)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@printf "$(_INFO) push_swap and checker.\n"

re: fclean all

PHONY: all clean fclean re mandatory bonus