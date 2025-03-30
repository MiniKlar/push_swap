NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I ./includes -I ./LIB_C
CLONE = git clone

RM = rm -f

LIB_C_GIT_URL = git@github.com:MiniKlar/LIB_C.git
LIB_C = LIB_C

SRC = ./main.c \
	./parsing.c \
	./init_a_to_b.c \
	./init_b_to_a.c \
	./stack_utils.c \
	./srcs/instructions/swap.c \
	./srcs/instructions/push.c \
	./srcs/instructions/rotate.c \
	./srcs/instructions/reverse_rotate.c \
	./srcs/algorithm/sorting.c \
	./srcs/utils/exit.c \
	./srcs/utils/free.c \
	./srcs/utils/utils.c \

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
