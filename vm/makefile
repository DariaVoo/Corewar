.PHONY: all clean fclean re

# COLORS
BLUE = "\e[38;5;69m"
EOC = "\e[0m"

# COMPILER SETTINGS
CC := clang
CFLAGS := -Wall -Wextra -Werror

# LIB (LIBFT, GET_NEXT_LINE, PRINTF)
L_DIR := ../lib/
L_NAME = lib.a
L_RULE := $(addsuffix .lib, $(L_DIR))

# PROGRAM NAME
PROG_NAME := corewar

# HEADER DIR
H_DIR := include/

# HEADER NAME
H_NAME = vm op parse_args
H_NAME := $(addprefix $(H_DIR), $(addsuffix .h, $(H_NAME)))

# SOURCES DIR
SRC_DIR := src/

SRC_PARSE_DIR = parse/
SRC_PARSE_DIR := $(addprefix $(SRC_DIR), $(SRC_PARSE_DIR))

SRC_LOGIC_DIR = logic/
SRC_LOGIC_DIR := $(addprefix $(SRC_DIR), $(SRC_LOGIC_DIR))

SRC_LOGIC_OP_DIR = operation/
SRC_LOGIC_OP_DIR := $(addprefix $(SRC_LOGIC_DIR), $(SRC_LOGIC_OP_DIR))

SRC_EXTRA_DIR = extra/
SRC_EXTRA_DIR := $(addprefix $(SRC_DIR), $(SRC_EXTRA_DIR))

SRC_DEBUG_DIR = debug/
SRC_DEBUG_DIR := $(addprefix $(SRC_DIR), $(SRC_DEBUG_DIR))

# SOURCES
SRC_MAIN =  main \
			game \
			champ \
			carriage \
			vm
SRC_MAIN := $(addsuffix .c, $(SRC_MAIN))

SRC_PARSE = parse_args \
			parse_args_flags \
			parse_files
SRC_PARSE := $(addsuffix .c, $(SRC_PARSE))

SRC_LOGIC = operation \
			op \
			arg \
			calc \
			exec_oper \
			check

SRC_LOGIC := $(addsuffix .c, $(SRC_LOGIC))

SRC_LOGIC_OP = ld \
				live \
				st \
				add \
				sub \
				and \
				or \
				xor \
				zjmp \
				ldi \
				sti \
				fork \
				lld \
				lldi \
				lfork \
				aff
				
SRC_LOGIC_OP := $(addsuffix .c, $(SRC_LOGIC_OP))

SRC_EXTRA = extra
SRC_EXTRA := $(addsuffix .c, $(SRC_EXTRA))

SRC_VISUAL = visual
SRC_VISUAL := $(addsuffix .c, $(SRC_VISUAL))

SRC_DEBUG = debug
SRC_DEBUG := $(addsuffix .c, $(SRC_DEBUG))


# FILE PATH TO LIB, PROGRAM SRC/OBJ FILES
PROG_SRC := $(addprefix $(SRC_DIR), $(SRC_MAIN)) \
			$(addprefix $(SRC_DIR), $(SRC_VISUAL)) \
			$(addprefix $(SRC_PARSE_DIR), $(SRC_PARSE)) \
			$(addprefix $(SRC_LOGIC_DIR), $(SRC_LOGIC)) \
			$(addprefix $(SRC_LOGIC_OP_DIR), $(SRC_LOGIC_OP)) \
			$(addprefix $(SRC_EXTRA_DIR), $(SRC_EXTRA)) \
			$(addprefix $(SRC_DEBUG_DIR), $(SRC_DEBUG))
L_NAME := $(addprefix $(L_DIR), $(L_NAME))

all: $(L_RULE) $(PROG_NAME)

%.lib:
	@$(MAKE) -sC $(L_DIR)

$(PROG_NAME) : $(PROG_SRC) $(H_NAME) $(L_NAME)
	@$(CC) $(CFLAGS) $(PROG_SRC) $(L_NAME) -o $(PROG_NAME) -I $(H_DIR) -lncurses
	@echo $(BLUE)"COREWAR COMPILED"$(EOC)

clean:
	@$(MAKE) -sC $(L_DIR) clean

fclean: clean
	@$(MAKE) -sC $(L_DIR) fclean
	@rm -f $(PROG_NAME)

re: fclean all

# main: producer.o consumer.o AddRemove.o
#    $(COMPILER) -pthread $(CCFLAGS) -o producer.o consumer.o AddRemove.o
# неправильный. Он говорит, чтобы создать файл с именем producer.o, но вы хотите
# создать файл с именем main . Пожалуйста, извините за крик, но всегда
# используйте $@ для ссылки на цель :

# main: producer.o consumer.o AddRemove.o
#    $(COMPILER) -pthread $(CCFLAGS) -o $@ producer.o consumer.o AddRemove.o