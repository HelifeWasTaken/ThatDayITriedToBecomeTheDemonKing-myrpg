##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## Makefile
##

CC = gcc

CFLAGS = -W -Wall -Werror -I./include -L./lib

ifeq ($(EPIDEBUG), 1)
	CFLAGS += -Wno-error=init-self -Winit-self
	CFLAGS += -Wno-error=shadow -Wshadow
	CFLAGS += -Wno-error=pointer-arith -Wpointer-arith
	CFLAGS += -Wno-error=duplicated-cond -Wduplicated-cond
	CFLAGS += -Wno-error=switch-enum -Wswitch-enum
	CFLAGS += -Wno-error=declaration-after-statement -Wdeclaration-after-statement
	CFLAGS += -Wno-error=float-equal -Wfloat-equal
	CFLAGS += -Wno-error=tautological-compare -Wtautological-compare
	CFLAGS += -Wno-error=array-bounds -Warray-bounds
	CFLAGS += -Wno-error=alloc-zero -Walloc-zero
	CFLAGS += -Wno-error=cast-qual -Wcast-qual
	CFLAGS += -Wno-error=extra -Wextra
	CFLAGS += -fno-builtin
	CFLAGS += -ftrapv -ggdb -g3
endif

LFLAGS = -ldistract -ltgoat -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window -lm # -lmy

TEST_FLAGS = $(LFLAGS) -lcriterion --coverage

TARGET = my_rpg

TARGET_TEST = unit_tests

SRC_MAP =	src/entities/map_loader/checks_tileset_layer.c \
			src/entities/map_loader/draw_vertex_array.c \
			src/entities/map_loader/get_tile_id_and_rotation.c \
			src/entities/map_loader/load_vertex_array_map.c \
			src/entities/map_loader/load_vertex_array.c \
			src/entities/map_loader/load_texture_coords_rot.c

SRC = 	src/game.c \
		src/entities/player/player.c \
		src/entities/scroll_bar/scroll_bar.c    \
		src/scenes/play/lifecycle.c \
		src/scenes/menu/lifecycle.c     \
		src/scenes/key_config/lifecycle.c \
		src/entities/menu/menu.c \
		src/entities/menu/create_menu.c \
		src/entities/ath/ath.c \
		$(SRC_MAP)

TESTS =	\

all:
	${MAKE} -j build_all -C .
	${MAKE} -j build_lib -C .

build_lib:
	${MAKE} -j -C ./lib/distract/
	${MAKE} -j -C ./lib/iron_goat/

re_lib:
	${MAKE} re -j -C ./lib/distract/
	${MAKE} re -j -C ./lib/iron_goat/

build_all:
	rm -rf ${TARGET}
	${MAKE} build_lib -j  -C .
	${MAKE} ${TARGET} -j  -C .

tests_run: clean_tests build_lib
	${CC} ${CFLAGS} ${TEST_FLAGS} -o ${TARGET_TEST} ${SRC} ${TESTS} ${LFLAGS}
	./${TARGET_TEST} --verbose

coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

clean_tests:
	rm -rf ${TARGET_TEST}

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} src/main.c ${LFLAGS}

clean:
	rm -f ${TARGET}
	${MAKE} clean -j -C ./lib/distract/
	${MAKE} clean -j -C ./lib/iron_goat/


fclean: clean
	rm -f ${LIB} *.gc* unit_tests
	${MAKE} fclean -C ./lib/iron_goat/
	${MAKE} fclean -C ./lib/distract/

re: fclean all

.PHONY: all build_lib re_lib build_all tests_run clean_tests clean fclean re
