NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I ./includes -I ./LIB_C
CLONE = git clone

RM = rm -f

LIB_C_GIT_URL = git@github.com:MiniKlar/LIB_C.git
LIB_C = LIB_C

SRC = ./main.c \
	./parsing.c \
	./utils/utils.c \
	./init_stack.c \
	./srcs/instructions/swap_a.c \
	./srcs/instructions/swap_b.c \
	./srcs/instructions/swap_a_and_b.c \
	./srcs/instructions/push_a.c \
	./srcs/instructions/push_b.c \
	./srcs/instructions/rotate_a.c \
	./srcs/instructions/rotate_b.c \
	./srcs/instructions/rotate_a_and_b.c \
	./srcs/instructions/reverse_rotate_a.c \
	./srcs/instructions/reverse_rotate_b.c \
	./srcs/instructions/reverse_rotate_a_and_b.c \
	./srcs/algorithm/sorting.c \
	./utils.c \
	./init_a_to_b.c \
	./init_b_to_a.c \
	./init_stack.c \
	./stack_utils.c \
	./srcs/exit.c \
	./srcs/free.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB_C) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./LIB_C/LIB_C.a -o $(NAME)

$(LIB_C):
	git clone $(LIB_C_GIT_URL) $(LIB_C)
	$(MAKE) -C $(LIB_C)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

make: make all

clean:
	$(RM) -r $(LIB_C)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean LIB_C all

.PHONY : all clean fclean re
