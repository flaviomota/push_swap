NAME = push_swap
BNAME = checker
SOURCES = \
	push_swap.c libft_utils.c certify.c guidelines.c sort_out.c sort_out_utils.c \
	sort_out_utils_2.c
BSOURCES = \
	checker.c libft_utils.c certify.c guidelines.c sort_out_utils.c \
	get_next_line.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft
	gcc -o $@ $(OBJECTS) -Llibft -lft

bonus: $(BOBJECTS) libft
	gcc -o $(BNAME) $(BOBJECTS) -Llibft -lft

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

libft:
	make bonus -C libft

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BNAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re