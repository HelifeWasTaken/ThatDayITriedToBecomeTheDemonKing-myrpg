##
## EPITECH PROJECT, 2020
## IronGoat
## File description:
## Makefile
##

SHELL 			=	bash

CC 				=	gcc

AR 				=	ar rc

NAME 			=	libtgoat.a

IFLAGS 			=	-I./erty/include -I./iron_goat/include

TEST_FLAGS 		= 	--coverage -lcriterion

WFLAGS 			=	-W -Wall -Wextra -Werror

POSIX_FLAGS 	=	-D_POSIX_C_SOURCE=200809L -D_GNU_SOURCE

STANDARD_FLAGS 	=	-std=c99

CFLAGS 			?=	 $(WFLAGS) $(POSIX_FLAGS) $(STANDARD_FLAGS) $(IFLAGS)

DEBUG 			?=	0

ifeq ($(DEBUG),1)
	CFLAGS += -g3 -ggdb
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
	CFLAGS += -Wno-error=extra -Wextra -Wnonnull
	CFLAGS += -fno-builtin
	CFLAGS += -ftrapv -ggdb -g3
endif

SRC_CTYPE_IS	=	./erty/ectypes/is/eis_alpha.c 			\
			./erty/ectypes/is/eis_lower.c 			\
			./erty/ectypes/is/eis_upper.c 			\
			./erty/ectypes/is/eis_num.c 				\
			./erty/ectypes/is/eis_alphanum.c		 	\
			./erty/ectypes/is/eis_space.c 			\
			./erty/ectypes/is/eis_punct.c 			\
			./erty/ectypes/is/eis_printable.c

SRC_CTYPE_TO	=	./erty/ectypes/to/eto_lower.c 			\
			./erty/ectypes/to/eto_upper.c


SRC_FD_BASIC	=	./erty/efd/basic/edputchar.c 			\
			./erty/efd/basic/edputs.c

SRC_FD_NUM 		= 	./erty/efd/num/edputnbr.c 				\
				./erty/efd/num/eduputnbr.c 				\
				./erty/efd/num/edputfloat.c

SRC_EFILE_BASIC	=	./erty/efile/basic/efputchar.c 			\
			./erty/efile/basic/efputs.c

SRC_EFILE_NUM 	= 	./erty/efile/num/efputnbr.c 				\
			./erty/efile/num/efuputnbr.c 			\
			./erty/efile/num/efputfloat.c

SRC_STDOUT 		=	./erty/estdio/stdout/eputchar.c 			\
				./erty/estdio/stdout/eputs.c

SRC_STDERR  	=	./erty/estdio/stderr/e_errputchar.c 		\
			./erty/estdio/stderr/e_errputs.c

SRC_STDLIB_MEM	=	./erty/estdlib/mem/emalloc.c 			\
			./erty/estdlib/mem/efree.c 				\
			./erty/estdlib/mem/ecalloc.c 			\
			./erty/estdlib/mem/erealloc.c

SRC_STDLIB_NUM	=	./erty/estdlib/num/eatoi.c 				\
			./erty/estdlib/num/eatol.c 				\
			./erty/estdlib/num/euatoi.c 				\
			./erty/estdlib/num/euatol.c 				\
			./erty/estdlib/num/eitoa.c 				\
			./erty/estdlib/num/eaitoa.c 				\
			./erty/estdlib/num/euitoa.c 				\
			./erty/estdlib/num/eauitoa.c 			\
			./erty/estdlib/num/estrtol.c 			\
			./erty/estdlib/num/estrtoll.c 			\
			./erty/estdlib/num/eftoa.c 				\
			./erty/estdlib/num/eaftoa.c


SRC_STDLIB_PTR	=	./erty/estdlib/ptr/eswap.c 				\
			./erty/estdlib/ptr/eptrswap.c 			\
			./erty/estdlib/ptr/eshowptr.c

SRC_STDLIB_MISC	=	./erty/estdlib/misc/eget_start_sign.c 	\
			./erty/estdlib/misc/eis_valid_strtoll.c 	\
			./erty/estdlib/misc/eget_float_decimals.c

SRC_CSTRING_CMP	=	./erty/ecstring/cmp/estrlen.c 			\
			./erty/ecstring/cmp/estrchr.c 			\
			./erty/ecstring/cmp/estrcmp.c 			\
			./erty/ecstring/cmp/estrncmp.c 			\
			./erty/ecstring/cmp/estrstr.c 			\
			./erty/ecstring/cmp/ecount_occurences.c 	\
			./erty/ecstring/cmp/estartswith.c 		\
			./erty/ecstring/cmp/eendswith.c 			\
			./erty/ecstring/cmp/ecount_tab.c

SRC_CSTRING_CPY	=	./erty/ecstring/cpy/estrcpy.c 			\
			./erty/ecstring/cpy/estrncpy.c 			\
			./erty/ecstring/cpy/estrdup.c 			\
			./erty/ecstring/cpy/estrndup.c 			\
			./erty/ecstring/cpy/estrcat.c 			\
			./erty/ecstring/cpy/esplit.c 			\
			./erty/ecstring/cpy/eappend_tab.c 		\
			./erty/ecstring/cpy/ecopy_tab.c 			\
			./erty/ecstring/cpy/econcat.c 			\
			./erty/ecstring/cpy/earrconcat.c 		\
			./erty/ecstring/cpy/egetsubstr.c

SRC_CSTRING_IS	=	./erty/ecstring/is/estr_isalpha.c 		\
			./erty/ecstring/is/estr_isalphanum.c 		\
			./erty/ecstring/is/estr_islower.c 		\
			./erty/ecstring/is/estr_isnum.c 			\
			./erty/ecstring/is/estr_isprintable.c 	\
			./erty/ecstring/is/estr_isupper.c

SRC_CSTRING_MEM	=	./erty/ecstring/mem/ememcpy.c 			\
			./erty/ecstring/mem/ememset.c 			\
			./erty/ecstring/mem/ememcmp.c 			\
			./erty/ecstring/mem/ebzero.c 				\

SRC_CSTRING_NUM	=	./erty/ecstring/num/enblen.c 				\
			./erty/ecstring/num/enb_baselen.c 		\
			./erty/ecstring/num/eunblen.c 			\
			./erty/ecstring/num/eunb_baselen.c

SRC_CSTRING_MISC	=	./erty/ecstring/misc/erevstr.c 			\
				./erty/ecstring/misc/estr_capitalize.c

SRC_WSTRING		=	./erty/wstring/ewcslen.c 				\
				./erty/wstring/ewcsputs.c 				\
				./erty/wstring/convert_ewcslen.c 		\
				./erty/wstring/convert_wchr_to_chr.c 	\
				./erty/wstring/ewcstombs.c

SRC_EBUFF 		=	./erty/ebuff/ecreate_buff.c				\
				./erty/ebuff/eappend_buff.c 				\
				./erty/ebuff/ebuff_flush.c				\
				./erty/ebuff/efree_buff.c 				\
				./erty/ebuff/eget_buff.c 				\
				./erty/ebuff/erealloc_buff.c 			\
				./erty/ebuff/ereset_buff.c

SRC_EPRINTF_STD	=	./erty/eprintf/standard/eprintf.c 		\
			./erty/eprintf/standard/easprintf.c 		\
			./erty/eprintf/standard/edprintf.c 		\
			./erty/eprintf/standard/efprintf.c

SRC_EPRINTF_VAR =	./erty/eprintf/variadic/evprintf.c 		\
			./erty/eprintf/variadic/evasprintf.c 	\
			./erty/eprintf/variadic/evdprintf.c 		\
			./erty/eprintf/variadic/evfprintf.c

EPRINTF_GBL_ARG		= ./erty/eprintf/parser/get_arg/

SRC_EPRINTF_ARG	=	$(EPRINTF_GBL_ARG)/eprintf_get_arg.c 	\
			$(EPRINTF_GBL_ARG)/get_eprintf_ptr.c

EPRINTF_MOD 	= 	./erty/eprintf/parser/modif

SRC_EPRINTF_MOD	=	$(EPRINTF_MOD)/get_eprintf_flag_modifiers.c		\
			$(EPRINTF_MOD)/get_eprintf_len_flag.c 			\
			$(EPRINTF_MOD)/get_eprintf_modifications.c

EPRINTF_LCL		=	./erty/eprintf/parser/local

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

SRC_EPRINTF_MSC =	./erty/eprintf/misc/check_eprintf_format.c 		\
			./erty/eprintf/misc/eprintf_failure.c

SRC_EPRINTF_PRS	=	$(SRC_EPRINTF_LCL) 						\
			$(SRC_EPRINTF_MOD)						\
			$(SRC_EPRINTF_ARG) 						\
			./erty/eprintf/parser/eprintf_parser.c

SRC_EPRINTF_BUF =	./erty/eprintf/buffer/eprintf_global_buff.c 		\
			./erty/eprintf/buffer/eprintf_buffer_reset.c 	\
			./erty/eprintf/buffer/eprintf_free_buff.c 		\
			./erty/eprintf/buffer/eformat.c

SRC_EWRITE		=	./erty/ewrite/ewrite.c 					\
				./erty/ewrite/efwrite.c

SRC_SSTR		=	./erty/esstring/init.c 				\
				./erty/esstring/append.c 			\
				./erty/esstring/append_n.c 			\
				./erty/esstring/assign.c 			\
				./erty/esstring/assign_n.c			\
				./erty/esstring/at.c 				\
				./erty/esstring/compare.c 			\
				./erty/esstring/ncompare.c 			\
				./erty/esstring/print.c 				\
				./erty/esstring/to_buf.c 			\
				./erty/esstring/free.c

SRC_EREGEX 		=	./erty/eregex/eregex.c 				\
				./erty/eregex/eregex_utilities.c

SRC_JSON_GET 	=	./erty/json/getter/get_array.c \
			./erty/json/getter/get_object.c \
			./erty/json/getter/getter.c

SRC_JSON_PARSE 	=	./erty/json/parser/get_buff.c \
			./erty/json/parser/array.c \
			./erty/json/parser/init.c \
			./erty/json/parser/value.c \
			./erty/json/parser/withespace.c \
			./erty/json/parser/bool.c \
			./erty/json/parser/null.c \
			./erty/json/parser/number.c \
			./erty/json/parser/object.c \
			./erty/json/parser/string.c

SRC_JSON_VEC 	=	./erty/json/vector/at.c \
			./erty/json/vector/clear.c \
			./erty/json/vector/insert.c

SRC_JSON_LIST	=	./erty/json/list/at.c \
			./erty/json/list/create.c \
			./erty/json/list/pop.c \
			./erty/json/list/push.c

SRC_JSON_HASH 	=	./erty/json/hashmap/clear.c \
			./erty/json/hashmap/getter.c \
			./erty/json/hashmap/insert.c \
			./erty/json/hashmap/resize.c

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

PATH_PRIV_IG  	=	./iron_goat/priv

SRC_IG_PRIV 	=	$(PATH_PRIV_IG)/tile/load_tile.c \
			$(PATH_PRIV_IG)/grid/load_grid.c \
			$(PATH_PRIV_IG)/layer/load_layer.c \
			$(PATH_PRIV_IG)/map/load_map.c \
			$(PATH_PRIV_IG)/property/load_property.c \
			$(PATH_PRIV_IG)/tile/load_tile.c \
			$(PATH_PRIV_IG)/wangset/load_wangset.c \
			$(PATH_PRIV_IG)/text/load_text.c \
			$(PATH_PRIV_IG)/tileset/load_tileset.c

SRC_IG 		=	./iron_goat/chunk.c \
			./iron_goat/frame.c \
			./iron_goat/layer.c \
			./iron_goat/map.c \
			./iron_goat/object.c \
			./iron_goat/point.c \
			./iron_goat/property.c \
			./iron_goat/terrain.c \
			./iron_goat/text.c \
			./iron_goat/tile_terrain.c \
			./iron_goat/tile.c \
			./iron_goat/tileoffset.c \
			./iron_goat/tileset.c \
			./iron_goat/wangcolor.c \
			./iron_goat/wangset.c \
			./iron_goat/wangtile.c \
			./iron_goat/grid.c \
			./iron_goat/get_string.c \
			./iron_goat/hexatoint.c \
			$(SRC_IG_PRIV)

SRC 	=	$(SRC_ERTY) \
		$(SRC_IG)

OBJ 	=	$(SRC:.c=.o)

all:
	make  -C . $(NAME)
	cp $(NAME) ../
	cp -r erty/include/erty/ iron_goat/include/iron_goat/ ../../include/

$(NAME): ## Call build_lib
	make  -C . build_lib

build_lib: $(OBJ) ## Build The other one
	$(AR) $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean

re:
	make  clean 		 -C .
	make  all			 -C .

expand:
	$(CC) $(SRC) $(CFLAGS) -E -o $(NAME)
