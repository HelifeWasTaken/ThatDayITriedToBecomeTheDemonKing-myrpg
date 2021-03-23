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

LFLAGS = -ldistract -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window -lm # -lmy

TEST_FLAGS = $(LFLAGS) -lcriterion --coverage

TARGET = my_rpg

TARGET_TEST = unit_tests

SRC = 	src/game.c \
        src/entities/player/player.c \
        src/scenes/play/lifecycle.c \
        src/scenes/menu/lifecycle.c \
        src/entities/menu/menu.c

TESTS =	\

all: build_lib build_all

build_lib:
	#${MAKE} -C ./lib/my/
	${MAKE} -C ./lib/distract/

re_lib:
	#${MAKE} re -C ./lib/my/
	${MAKE} re -C ./lib/distract/

build_all: ${TARGET}

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

fclean: clean
	rm -f ${LIB} *.gc* unit_tests

re: fclean all

.PHONY: all build_lib re_lib build_all tests_run clean_tests clean fclean re
