CC = gcc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = get_next_line.c\
			get_next_line_utils.c

BONUS = ft_lstadd_back.c\

MAN_OBJS = $(MANDATORY:.c=.o)
BON_OBJS = $(BONUS:.c=.o)
NAME = get_next_line.a

ifdef WITH_BONUS
MAN_OBJS += $(BON_OBJS)
endif

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)

bonus:
	make all WITH_BONUS=1

clean:
	rm -f $(MAN_OBJS) $(BON_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus