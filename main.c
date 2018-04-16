#include"include/draw.h"
#include"include/output.h"
#include"include/parser.h"
#include"include/rcs.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Please state an input file\n");
		exit(1);
	}
	struct Matrix *edges = new_matrix(4, 1);
	struct Matrix *poly = new_matrix(4, 1);
	struct Matrix *transform = new_matrix(4, 4);
	struct Rcs_stack *s = new_rcs_stack(4);
	Frame f;
	memset(f, 0, sizeof(f));
	
	struct Pixel p;
	pixel_color(&p, 255, 235, 205);
	
	parse_instructions(argv[1], transform, edges, poly, f);

	/*
	print_stack(s);
	//print_matrix(peek(s));
	printf("%d\n", s->capacity);
	
	move(peek(s), 2, 4, 6);
	print_matrix(peek(s));
	push_rcs(s);
	printf("%d\n", s->capacity);
	
	scale(peek(s), 1, 2, 3);
	print_matrix(peek(s));
	push_rcs(s);
	printf("%d\n", s->capacity);
	
	printf("%d\n", s->top);
	print_stack(s);
	
	printf("popping\n");
	pop_rcs(s);
	print_matrix(peek(s));
	printf("%d\n", s->top);
	
	pop_rcs(s);
	print_matrix(peek(s));
	printf("%d\n", s->top);
	
	pop_rcs(s);
	print_matrix(peek(s));
	printf("%d\n", s->top);
	*/

	free_stack(s);
	
	free_matrix(edges);
	free_matrix(poly);
	free_matrix(transform);
	
	return 0;
}

