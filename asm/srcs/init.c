//
// Created by pbelo on 12.09.2020.
//
#include "../includes/asm.h"


void    ft_init_structs(t_header *header, t_body *body)
{
//    header->comment;
    header->magic = 0;
//    header->prog_name = 0;
    header->prog_size = 0;

//    body->champion_str = 0;
    body->file = NULL;
//    body->instr = 0;
    body->label = NULL;
    body->line_number = 0;
}
