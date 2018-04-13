#ifndef PARSER_H
#define PARSER_H

#include<stdio.h>
#include<string.h>

#include"draw.h"
#include"matrix.h"
#include"output.h"
#include"shapes.h"

void parse_instructions(char *filename, struct Matrix *t,
			struct Matrix *e, Frame f);

#endif
