NAME = libftprintf.a

CC = cc

CFLAGS = -Wextra -Wall -Werror

AR = ar -rc

SRC = ft_putstr.c ft_putnbr.c ft_putchar.c ft_printf.c ft_put_hexa.c ft_print_address.c ft_printnbr_unsigned.c

OBJCS = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJCS}
	${AR} ${NAME} ${OBJCS} 

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean : 
	rm -rf ${OBJCS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean