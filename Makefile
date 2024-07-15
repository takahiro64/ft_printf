NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr.c ft_putchr.c ft_putstr.c ft_putpointa.c\
	   ft_puthex_upper.c ft_puthex_lower.c

CC = cc

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
