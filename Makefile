SOURCES = bsq_map.c ft_atoi.c ft_strcpy.c ft_strlen.c \
		  ft_putchar.c bsq_algorithm.c bsq_print.c bsq_stdin.c \
		  main.c
HEADERS = bsq.h ftlib.h
SRCS_PATH = srcs/
INCLUDES_PATH = includes/
SRCS = $(addprefix $(SRCS_PATH), $(SOURCES))
INCLUDES = $(addprefix $(INCLUDES_PATH), $(HEADERS))
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = bsq

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	$(CC) -c $(CFLAGS) $(SRCS) -I$(INCLUDES_PATH)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
