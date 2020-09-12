//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"
#include "../includes/op.h"


void    ft_init_structs(t_header *header, t_body *body)
{
    header->comment = null;
    header->magic = 0;
    header->prog_name = null;
    header->prog_size = 0;

    body->champion_str = null;
    body->file = null;
    body->instr = null;
    body->label = null;
    body->line_number = 0;
}
