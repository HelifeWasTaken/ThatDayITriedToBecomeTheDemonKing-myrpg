##
## EPITECH PROJECT, 2020
## IronGoat
## File description:
## Makefile
##

GREEN 			=	\x1b[32;01m
RED 			=	\x1b[31;01m
YELLOW 			=	\x1b[33;01m
WHITE 			=	\x1b[00;00m
CYAN 			=	\x1b[34;01m
DEFAULT 		= 	\x1b[36;01m

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

all: info ## Call build_lib
	@make -j -C ./lib
	@mv ./lib/libtgoat.a ../

clean:
	@make fclean -j -C ./lib

fclean: clean

re:
	@make re		-j -C ./lib
	@make all 	-j -C .

info:
	@printf "%50s\n" " " | tr ' ' '-'
	@printf "$(GREEN)[$(YELLOW)Info$(GREEN)] $(WHITE)Linking objects with:"
	@printf "\n\t$(CYAN)CC        $(WHITE)= $(GREEN)$(CC)"
	@printf "\n\t$(CYAN)CFLAGS    $(WHITE)= $(GREEN)$(CFLAGS)$(DEFAULT)"
	@printf "\n\t$(CYAN)AR        $(WHITE)= $(GREEN)$(AR)$(DEFAULT)"
	@printf "\n\t$(CYAN)SHELL     $(WHITE)= $(GREEN)$(SHELL)$(DEFAULT)\n"

expand:
	$(CC) $(SRC) $(CFLAGS) -E -o $(NAME)
