.PHONY: all clean fclean re lib

DIR_ASM := asm/
DIR_VM := vm/

all:
	# @$(MAKE) -sC $(DIR_ASM)
	@$(MAKE) -sC $(DIR_VM)

clean:
	# @$(MAKE) -sC $(DIR_ASM) clean
	@$(MAKE) -sC $(DIR_VM) clean

fclean: clean
	# @$(MAKE) -sC $(DIR_ASM) fclean
	@$(MAKE) -sC $(DIR_VM) fclean

re: fclean all
