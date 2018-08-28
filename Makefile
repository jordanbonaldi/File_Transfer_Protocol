##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

CFLAGS += -W -Wextra -Wall -Werror -g3
CFLAGS += -I./include

NAME = server

SRCS =  main.c 					\
	src/elements/connection.c		\
	src/elements/client.c			\
	src/elements/data_connection.c		\
	src/elements/commands/auths_cmd.c	\
	src/elements/commands/misc_cmds.c	\
	src/elements/commands/directories_cmds.c\
	src/elements/commands/transfert_protocol_commands.c\
	src/elements/commands/file_cmds.c	\
	src/managers/connection_manager.c	\
	src/managers/messages_manager.c		\
	src/managers/errors_manager.c		\
	src/managers/client_manager.c		\
	src/managers/cmd_manager.c		\
	src/utils/register_cmd.c		\
	src/utils/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
