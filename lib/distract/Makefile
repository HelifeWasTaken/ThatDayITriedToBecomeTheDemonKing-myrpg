##
## EPITECH PROJECT, 2020
## libmy_sfml
## File description:
## My CSFML library
##

CC = gcc

AR = ar rc

CFLAGS = -W -Wall -Werror -I./include -I../my/include -L..

CFLAGS_TEST = ${CFLAGS} -Wno-stringop-truncation --coverage

LFLAGS = -lcsfml-system -lcsfml-graphics -lcsfml-window -lmy

LFLAGS_TEST = ${LFLAGS} -lcriterion

TESTDIR = ../../tests/lib/my

SRC =	src/debug/print_error.c \
		src/entities/add_to_entities.c \
		src/entities/create_entity.c \
		src/entities/entity.c \
		src/entities/get_entity_info.c \
		src/entities/register_entity.c \
		src/entities/move_entity_towards.c \
		src/collision/point.c \
		src/collision/raycast.c \
		src/collision/screenbounds.c \
		src/game/game.c \
		src/game/close_game.c \
		src/game/timer.c \
		src/graphics/align_text_bottom.c \
		src/graphics/align_text_right.c \
		src/graphics/center_text_x.c \
		src/graphics/center_text_y.c \
		src/graphics/create_sprite.c \
		src/math/add.c \
		src/math/lerp.c \
		src/math/magnitude.c \
		src/math/normalize.c \
		src/math/mulf.c \
		src/math/distance.c \
		src/math/sub.c \
		src/resources/resource.c \
		src/resources/texture.c \
		src/resources/font.c \
		src/resources/sound.c \
		src/scene/destroy_scene.c \
		src/scene/draw_scene.c \
		src/scene/update_scene.c \
		src/scene/register_scene.c \
		src/scene/load_pending_scene.c \
		src/scene/has_pending_scene.c \
		src/scene/is_scene_updated.c \
		src/scene/switch_to_scene.c \
		src/scene/set_pending_scene.c \
		src/scene/get_scene_info.c \
		src/scene/load_pending_scene.c \
		src/scene/transmit_event_to_scene.c \
		src/window/create_standard_window.c \
		src/strutil.c

TEST_FILES = 	\

OBJ = ${SRC:.c=.o}

TARGET = libdistract.a

all: build_all clean

build_all: ${OBJ}
	${AR} ${TARGET} ${OBJ}
	cp ${TARGET} ../
	mkdir -p ../../include
	mkdir -p ../../include/distract
	ln -rsf ./include/distract/*.h ../../include/distract

coverage: test
	gcovr

clean:
	rm -f *.gc* unit_test

fclean: clean
	rm -f ${TARGET} ${OBJ}

re: fclean all
