NAMEC = client
NAMES = server
NAMECB = client_bonus
NAMESB = server_bonus
SRCS_C = client.c
SRCS_S = server.c
SRCS_CB = client_bonus.c
SRCS_SB = server_bonus.c
OBJS_C = ${SRCS_C:.c=.o}
OBJS_S = ${SRCS_S:.c=.o}
OBJS_CB = ${SRCS_CB:.c=.o}
OBJS_SB = ${SRCS_SB:.c=.o}
PRINTF = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAMEC} ${NAMES}

bonus: ${NAMECB} ${NAMESB}

${NAMEC}: ${OBJS_C}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_C) $(PRINTF) -o $(NAMEC)

${NAMES}: ${OBJS_S}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_S) $(PRINTF) -o $(NAMES)

${NAMECB}: ${OBJS_CB}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_CB) $(PRINTF) -o $(NAMECB)

${NAMESB}: ${OBJS_SB}
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_SB) $(PRINTF) -o $(NAMESB)

clean:
	make clean -C ft_printf
	rm -rf $(OBJS_S)
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_SB)
	rm -rf $(OBJS_CB)

fclean: clean
	make fclean -C ft_printf
	rm -rf server
	rm -rf client
	rm -rf server_bonus
	rm -rf client_bonus

re: fclean all

.PHONY: all re fclean clean
