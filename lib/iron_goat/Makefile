##
## EPITECH PROJECT, 2020
## IronGoat
## File description:
## Makefile
##

SHELL 	=	bash

CC 				=	gcc

LFLAGS 			=	-L./lib/ -ltgoat

IFLAGS 			=	-I./lib/include

WFLAGS 			=	-W -Wall -Wextra -Werror

POSIX_FLAGS 	=	-D_POSIX_C_SOURCE=200809L -D_GNU_SOURCE

STANDARD_FLAGS 	=	-std=c99

CFLAGS 			?=	 $(WFLAGS) $(POSIX_FLAGS) $(STANDARD_FLAGS) $(IFLAGS) $(LFLAGS)

DEBUG_FLAGS 	=	-g -ggdb -O0 -O2

DEBUG 			?=	0

ifeq ($(DEBUG),1)
	CFLAGS 	+=	$(DEBUG_FLAGS)
endif

all: ## Call build_lib
	make -j -C ./lib
	mv ./lib/libtgoat.a ../

clean:
	make fclean -j -C ./lib

fclean: clean

re:
	make re		-j -C ./lib
	make all 	-j -C .

expand:
	$(CC) $(SRC) $(CFLAGS) -E -o $(NAME)