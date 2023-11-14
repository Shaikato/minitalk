NAMEC = client
NAMES = server
SRCS_C = client.c
SRCS_S = server.c
OBJS_C = ${SRCS_C:.c=.o}
OBJS_S = ${SRCS_S:.c=.o}
PRINTF = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAMEC} ${NAMES}

${NAMEC}: ${OBJS_C}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF) -o $(NAMEC)

${NAMES}: ${OBJS_S}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF) -o $(NAMES)

clean:
	make clean -C ft_printf
	rm -rf $(OBJS_S)
	rm -rf $(OBJS_C)

fclean: clean
	make fclean -C ft_printf
	rm -rf server
	rm -rf client

re: fclean all

.PHONY: all re fclean clean $(NAMEC) ${NAMEC}
