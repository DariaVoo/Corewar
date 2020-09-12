//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"


void    ft_init_structs(t_header *header, t_body *body)
{
//    ft_printf("\nHERE init\n");
    ft_bzero(header->comment, PROG_NAME_LENGTH + 1);
    header->magic = COREWAR_EXEC_MAGIC;
    ft_bzero(header->prog_name, 129);
    header->prog_size = 0;

//    body->champion_str = 0;
    body->file = NULL;
//    body->instr = 0;
    body->label = NULL;
    body->line_number = 0;
}
