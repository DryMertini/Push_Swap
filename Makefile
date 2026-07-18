# ****************************************************************************
# Makefile for push_swap
#
# Targets:
#   make        / make all  -> build the push_swap binary
#   make clean              -> remove object files
#   make fclean             -> remove object files + the binary
#   make re                 -> fclean + all
#
# Flags: -Wall -Wextra -Werror   (required by the 42 norm)
# ****************************************************************************

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  parser.c parser_utils.c ft_split.c \
			  stack_utils.c stack_utils2.c \
			  ops_swap.c ops_push.c ops_rotate.c ops_rev_rotate.c \
			  indexing.c sort_small.c sort_chunks.c

OBJS		= $(SRCS:.c=.o)

# Object files depend on the header — touching push_swap.h triggers a rebuild.
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
