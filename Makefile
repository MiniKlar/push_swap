NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I includes
CLONE = git clone
SRC = parsing.c \
	main.c \
	./utils/utils.c \
	./init_stack.c \
	./instructions/swap_a.c \
	./instructions/swap_b.c \
	./instructions/swap_a_and_b.c \
	./instructions/push_a.c \
	./instructions/push_b.c \
	./instructions/rotate_a.c \
	./instructions/rotate_b.c \
	./instructions/rotate_a_and_b.c \
	./instructions/reverse_rotate_a.c \
	./instructions/reverse_rotate_b.c \
	./instructions/reverse_rotate_a_and_b.c \
	./algorithm/sorting.c \
	./utils.c \
	./init_a_to_b.c \
	./init_b_to_a.c \
	./init_stack.c \
	./stack_utils.c \
	./srcs/exit.c \
	./srcs/free.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

LIB_C:
	$(CLONE) git@github.com:MiniKlar/LIB_C.git LIB_C; cd /home/lomont/42_miniklar/push_swap/LIB_C; make; make clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./LIB_C/LIB_C.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ -c $^

make: make all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) LIB_C

re: fclean LIB_C all

.PHONY : all clean fclean re
