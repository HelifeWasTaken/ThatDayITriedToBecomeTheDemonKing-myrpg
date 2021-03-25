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

SHELL 			=	bash

CC 				=	gcc

AR 				=	ar rc

NAME 			=	libtgoat.a

IFLAGS 			=	-I./include

DEBUG_FLAGS 	= 	-g3 -ggdb -O0 -O2

TEST_FLAGS 		= 	--coverage -lcriterion

WFLAGS 			=	-W -Wall -Wextra -Werror

POSIX_FLAGS 	=	-D_POSIX_C_SOURCE=200809L -D_GNU_SOURCE

STANDARD_FLAGS 	=	-std=c99

CFLAGS 			?=	 $(WFLAGS) $(POSIX_FLAGS) $(STANDARD_FLAGS) $(IFLAGS)

DEBUG 			?=	0

ifeq ($(DEBUG),1)
	CFLAGS 		+=	$(DEBUG_FLAGS)
endif

SRC_CTYPE_IS	=	./erty/lib/ectypes/is/eis_alpha.c 			\
					./erty/lib/ectypes/is/eis_lower.c 			\
					./erty/lib/ectypes/is/eis_upper.c 			\
					./erty/lib/ectypes/is/eis_num.c 				\
					./erty/lib/ectypes/is/eis_alphanum.c		 	\
					./erty/lib/ectypes/is/eis_space.c 			\
					./erty/lib/ectypes/is/eis_punct.c 			\
					./erty/lib/ectypes/is/eis_printable.c

SRC_CTYPE_TO	=	./erty/lib/ectypes/to/eto_lower.c 			\
					./erty/lib/ectypes/to/eto_upper.c


SRC_FD_BASIC	=	./erty/lib/efd/basic/edputchar.c 			\
					./erty/lib/efd/basic/edputs.c

SRC_FD_NUM 		= 	./erty/lib/efd/num/edputnbr.c 				\
					./erty/lib/efd/num/eduputnbr.c 				\
					./erty/lib/efd/num/edputfloat.c

SRC_EFILE_BASIC	=	./erty/lib/efile/basic/efputchar.c 			\
					./erty/lib/efile/basic/efputs.c

SRC_EFILE_NUM 	= 	./erty/lib/efile/num/efputnbr.c 				\
					./erty/lib/efile/num/efuputnbr.c 			\
					./erty/lib/efile/num/efputfloat.c

SRC_STDOUT 		=	./erty/lib/estdio/stdout/eputchar.c 			\
					./erty/lib/estdio/stdout/eputs.c

SRC_STDERR  	=	./erty/lib/estdio/stderr/e_errputchar.c 		\
					./erty/lib/estdio/stderr/e_errputs.c

SRC_STDLIB_MEM	=	./erty/lib/estdlib/mem/emalloc.c 			\
					./erty/lib/estdlib/mem/efree.c 				\
					./erty/lib/estdlib/mem/ecalloc.c 			\
					./erty/lib/estdlib/mem/erealloc.c

SRC_STDLIB_NUM	=	./erty/lib/estdlib/num/eatoi.c 				\
					./erty/lib/estdlib/num/eatol.c 				\
					./erty/lib/estdlib/num/euatoi.c 				\
					./erty/lib/estdlib/num/euatol.c 				\
					./erty/lib/estdlib/num/eitoa.c 				\
					./erty/lib/estdlib/num/eaitoa.c 				\
					./erty/lib/estdlib/num/euitoa.c 				\
					./erty/lib/estdlib/num/eauitoa.c 			\
					./erty/lib/estdlib/num/estrtol.c 			\
					./erty/lib/estdlib/num/estrtoll.c 			\
					./erty/lib/estdlib/num/eftoa.c 				\
					./erty/lib/estdlib/num/eaftoa.c


SRC_STDLIB_PTR	=	./erty/lib/estdlib/ptr/eswap.c 				\
					./erty/lib/estdlib/ptr/eptrswap.c 			\
					./erty/lib/estdlib/ptr/eshowptr.c

SRC_STDLIB_MISC	=	./erty/lib/estdlib/misc/eget_start_sign.c 	\
					./erty/lib/estdlib/misc/eis_valid_strtoll.c 	\
					./erty/lib/estdlib/misc/eget_float_decimals.c

SRC_CSTRING_CMP	=	./erty/lib/ecstring/cmp/estrlen.c 			\
					./erty/lib/ecstring/cmp/estrchr.c 			\
					./erty/lib/ecstring/cmp/estrcmp.c 			\
					./erty/lib/ecstring/cmp/estrncmp.c 			\
					./erty/lib/ecstring/cmp/estrstr.c 			\
					./erty/lib/ecstring/cmp/ecount_occurences.c 	\
					./erty/lib/ecstring/cmp/estartswith.c 		\
					./erty/lib/ecstring/cmp/eendswith.c 			\
					./erty/lib/ecstring/cmp/ecount_tab.c

SRC_CSTRING_CPY	=	./erty/lib/ecstring/cpy/estrcpy.c 			\
					./erty/lib/ecstring/cpy/estrncpy.c 			\
					./erty/lib/ecstring/cpy/estrdup.c 			\
					./erty/lib/ecstring/cpy/estrndup.c 			\
					./erty/lib/ecstring/cpy/estrcat.c 			\
					./erty/lib/ecstring/cpy/esplit.c 			\
					./erty/lib/ecstring/cpy/eappend_tab.c 		\
					./erty/lib/ecstring/cpy/ecopy_tab.c 			\
					./erty/lib/ecstring/cpy/econcat.c 			\
					./erty/lib/ecstring/cpy/earrconcat.c 		\
					./erty/lib/ecstring/cpy/egetsubstr.c

SRC_CSTRING_IS	=	./erty/lib/ecstring/is/estr_isalpha.c 		\
					./erty/lib/ecstring/is/estr_isalphanum.c 		\
					./erty/lib/ecstring/is/estr_islower.c 		\
					./erty/lib/ecstring/is/estr_isnum.c 			\
					./erty/lib/ecstring/is/estr_isprintable.c 	\
					./erty/lib/ecstring/is/estr_isupper.c

SRC_CSTRING_MEM	=	./erty/lib/ecstring/mem/ememcpy.c 			\
					./erty/lib/ecstring/mem/ememset.c 			\
					./erty/lib/ecstring/mem/ememcmp.c 			\
					./erty/lib/ecstring/mem/ebzero.c 				\

SRC_CSTRING_NUM	=	./erty/lib/ecstring/num/enblen.c 				\
					./erty/lib/ecstring/num/enb_baselen.c 		\
					./erty/lib/ecstring/num/eunblen.c 			\
					./erty/lib/ecstring/num/eunb_baselen.c

SRC_CSTRING_MISC	=	./erty/lib/ecstring/misc/erevstr.c 			\
						./erty/lib/ecstring/misc/estr_capitalize.c

SRC_WSTRING		=	./erty/lib/wstring/ewcslen.c 				\
					./erty/lib/wstring/ewcsputs.c 				\
					./erty/lib/wstring/convert_ewcslen.c 		\
					./erty/lib/wstring/convert_wchr_to_chr.c 	\
					./erty/lib/wstring/ewcstombs.c

SRC_EBUFF 		=	./erty/lib/ebuff/ecreate_buff.c				\
					./erty/lib/ebuff/eappend_buff.c 				\
					./erty/lib/ebuff/ebuff_flush.c				\
					./erty/lib/ebuff/efree_buff.c 				\
					./erty/lib/ebuff/eget_buff.c 				\
					./erty/lib/ebuff/erealloc_buff.c 			\
					./erty/lib/ebuff/ereset_buff.c

SRC_EPRINTF_STD	=	./erty/lib/eprintf/standard/eprintf.c 		\
					./erty/lib/eprintf/standard/easprintf.c 		\
					./erty/lib/eprintf/standard/edprintf.c 		\
					./erty/lib/eprintf/standard/efprintf.c

SRC_EPRINTF_VAR =	./erty/lib/eprintf/variadic/evprintf.c 		\
					./erty/lib/eprintf/variadic/evasprintf.c 	\
					./erty/lib/eprintf/variadic/evdprintf.c 		\
					./erty/lib/eprintf/variadic/evfprintf.c

EPRINTF_GBL_ARG		= ./erty/lib/eprintf/parser/get_arg/

SRC_EPRINTF_ARG	=	$(EPRINTF_GBL_ARG)/eprintf_get_arg.c 	\
					$(EPRINTF_GBL_ARG)/get_eprintf_ptr.c

EPRINTF_MOD 	= 	./erty/lib/eprintf/parser/modif

SRC_EPRINTF_MOD	=	$(EPRINTF_MOD)/get_eprintf_flag_modifiers.c		\
					$(EPRINTF_MOD)/get_eprintf_len_flag.c 			\
					$(EPRINTF_MOD)/get_eprintf_modifications.c

EPRINTF_LCL		=	./erty/lib/eprintf/parser/local

SRC_EPRINTF_LCL	=	$(EPRINTF_LCL)/eprintf_append_padding.c 		\
					$(EPRINTF_LCL)/eprintf_local_char.c	 			\
					$(EPRINTF_LCL)/eprintf_local_getsize.c 			\
					$(EPRINTF_LCL)/eprintf_local_int.c 				\
					$(EPRINTF_LCL)/eprintf_local_str.c 				\
					$(EPRINTF_LCL)/eprintf_local_uint.c 			\
					$(EPRINTF_LCL)/eprintf_local_oct.c 				\
					$(EPRINTF_LCL)/eprintf_local_hex.c 				\
					$(EPRINTF_LCL)/eprintf_local_ptr.c 				\
					$(EPRINTF_LCL)/eprintf_local_double.c 			\
					$(EPRINTF_LCL)/get_conversion_padding.c

SRC_EPRINTF_MSC =	./erty/lib/eprintf/misc/check_eprintf_format.c 		\
					./erty/lib/eprintf/misc/eprintf_failure.c

SRC_EPRINTF_PRS	=	$(SRC_EPRINTF_LCL) 						\
					$(SRC_EPRINTF_MOD)						\
					$(SRC_EPRINTF_ARG) 						\
					./erty/lib/eprintf/parser/eprintf_parser.c

SRC_EPRINTF_BUF =	./erty/lib/eprintf/buffer/eprintf_global_buff.c 		\
					./erty/lib/eprintf/buffer/eprintf_buffer_reset.c 	\
					./erty/lib/eprintf/buffer/eprintf_free_buff.c 		\
					./erty/lib/eprintf/buffer/eformat.c

SRC_EWRITE		=	./erty/lib/ewrite/ewrite.c 					\
					./erty/lib/ewrite/efwrite.c

SRC_SSTR		=	./erty/lib/esstring/init.c 				\
					./erty/lib/esstring/append.c 			\
					./erty/lib/esstring/append_n.c 			\
					./erty/lib/esstring/assign.c 			\
					./erty/lib/esstring/assign_n.c			\
					./erty/lib/esstring/at.c 				\
					./erty/lib/esstring/compare.c 			\
					./erty/lib/esstring/ncompare.c 			\
					./erty/lib/esstring/print.c 				\
					./erty/lib/esstring/to_buf.c 			\
					./erty/lib/esstring/free.c

SRC_EREGEX 		=	./erty/lib/eregex/eregex.c 				\
					./erty/lib/eregex/eregex_utilities.c

SRC_JSON_GET 	=	./erty/lib/json/getter/get_array.c \
					./erty/lib/json/getter/get_object.c \
					./erty/lib/json/getter/getter.c

SRC_JSON_PARSE 	=	./erty/lib/json/parser/get_buff.c \
					./erty/lib/json/parser/array.c \
					./erty/lib/json/parser/init.c \
					./erty/lib/json/parser/value.c \
					./erty/lib/json/parser/withespace.c \
					./erty/lib/json/parser/bool.c \
					./erty/lib/json/parser/null.c \
					./erty/lib/json/parser/number.c \
					./erty/lib/json/parser/object.c \
					./erty/lib/json/parser/string.c

SRC_JSON_VEC 	=	./erty/lib/json/vector/at.c \
					./erty/lib/json/vector/clear.c \
					./erty/lib/json/vector/insert.c

SRC_JSON_LIST	=	./erty/lib/json/list/at.c \
					./erty/lib/json/list/create.c \
					./erty/lib/json/list/pop.c \
					./erty/lib/json/list/push.c

SRC_JSON_HASH 	=	./erty/lib/json/hashmap/clear.c \
					./erty/lib/json/hashmap/getter.c \
					./erty/lib/json/hashmap/insert.c \
					./erty/lib/json/hashmap/resize.c

SRC_JSON 		=	$(SRC_JSON_LIST) \
					$(SRC_JSON_HASH) \
					$(SRC_JSON_VEC) \
					$(SRC_JSON_PARSE) \
					$(SRC_JSON_GET)

SRC_ESTDIO		=	$(SRC_ESTDOUT) 							\
					$(SRC_ESTDERR)

SRC_CTYPE		= 	$(SRC_CTYPE_IS)							\
					$(SRC_CTYPE_TO)

SRC_FD 			= 	$(SRC_FD_BASIC)							\
					$(SRC_FD_NUM) 							\

SRC_STDLIB 		= 	$(SRC_STDLIB_MEM)						\
					$(SRC_STDLIB_NUM) 						\
					$(SRC_STDLIB_PTR)						\
					$(SRC_STDLIB_MISC)

SRC_CSTRING		=	$(SRC_CSTRING_CMP)						\
					$(SRC_CSTRING_CPY) 						\
					$(SRC_CSTRING_IS)						\
					$(SRC_CSTRING_MISC) 						\
					$(SRC_CSTRING_NUM)						\
					$(SRC_CSTRING_MEM)

SRC_EPRINTF	 	=	$(SRC_EPRINTF_STD) 						\
					$(SRC_EPRINTF_VAR)						\
					$(SRC_EPRINTF_PRS)						\
					$(SRC_EPRINTF_BUF)						\
					$(SRC_EPRINTF_MSC)

SRC_EFILE 		=	$(SRC_EFILE_BASIC)						\
					$(SRC_EFILE_NUM)

SRC_STDIO 		= 	$(SRC_STDOUT) 							\
					$(SRC_STDERR)

SRC_ERTY		=	$(SRC_EWRITE) 							\
					$(SRC_CTYPE) 							\
					$(SRC_FD)								\
					$(SRC_STRING)							\
					$(SRC_STDLIB)							\
					$(SRC_EBUFF)							\
					$(SRC_WSTRING)							\
					$(SRC_EPRINTF) 							\
					$(SRC_EFILE)							\
					$(SRC_STDIO) 							\
					$(SRC_CSTRING) 							\
					$(SRC_SSTR) 							\
					$(SRC_EREGEX)							\
					$(SRC_JSON)

SRC_IG 	=	./iron_goat/lib/src/chunk.c \
			./iron_goat/lib/src/frame.c \
			./iron_goat/lib/src/layer.c \
			./iron_goat/lib/src/map.c \
			./iron_goat/lib/src/object.c \
			./iron_goat/lib/src/point.c \
			./iron_goat/lib/src/property.c \
			./iron_goat/lib/src/terrain.c \
			./iron_goat/lib/src/text.c \
			./iron_goat/lib/src/tile_terrain.c \
			./iron_goat/lib/src/tile.c \
			./iron_goat/lib/src/tileoffset.c \
			./iron_goat/lib/src/tileset.c \
			./iron_goat/lib/src/wangcolor.c \
			./iron_goat/lib/src/wangset.c \
			./iron_goat/lib/src/wangtile.c \
			./iron_goat/lib/src/grid.c \
			./iron_goat/lib/src/get_string.c \
			./iron_goat/lib/src/hexatoint.c

SRC 	=	$(SRC_ERTY) \
			$(SRC_IG)

OBJ 	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): info ## Call build_lib
	@make -j -C . build_lib --silent
	@make -j -C . copy --silent

copy:
	@mkdir -p ./include
	@ln -rsf ./iron_goat/lib/include/iron_goat ./include
	@ln -rsf ./erty/lib/include/erty ./include

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)[$(YELLOW)Linked$(GREEN)]$(WHITE) % 43s\n$(DEFAULT)" $@ | tr ' ' '.'

build_lib: $(OBJ) ## Build The other one
	$(AR) $(NAME) $(OBJ)
	@printf "$(GREEN)[$(YELLOW)Linked$(GREEN)]$(WHITE) % 43s$(DEFAULT)\n" $(NAME) | tr ' ' '.'
	@printf "$(GREEN)[$(CYAN)Linked all TileGoat files$(GREEN)]\n$(WHITE)"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

fclean: clean

re:
	@make  clean 		-j -C . --silent
	@make  all			-j -C . --silent

info:
	@printf "%50s\n" " " | tr ' ' '-'
	@printf "$(GREEN)[$(YELLOW)Info$(GREEN)] $(WHITE)Linking libraries with:"
	@printf "\n\t$(CYAN)CC        $(WHITE)= $(GREEN)$(CC)"
	@printf "\n\t$(CYAN)AR        $(WHITE)= $(GREEN)$(AR)$(DEFAULT)"
	@printf "\n\t$(CYAN)CFLAGS    $(WHITE)= $(GREEN)$(CFLAGS)$(DEFAULT)"
	@printf "\n\t$(CYAN)SHELL     $(WHITE)= $(GREEN)$(SHELL)$(DEFAULT)\n"

expand:
	$(CC) $(SRC) $(CFLAGS) -E -o $(NAME)
