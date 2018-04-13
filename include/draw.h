/* draw.h
 * 
 * Plotting pixels onto a frame
 * */

#ifndef DRAW_H
#define DRAW_H

#include<stdio.h>

#include"dimen.h"
#include"matrix.h"

struct Pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

typedef struct Pixel Frame[IMG_HEIGHT][IMG_WIDTH];

//writes a pixel value to a spot on the grid
//(0, 0) is the bottom left of the grid
void plot_point(Frame grid, int x, int y, struct Pixel *p);

//pixel is for custom colors
void draw_line(Frame grid, struct Pixel *p, int x1, int y1, int x2, int y2);

//p is the color, assumes length of m is even
void draw_lines(Frame grid, struct Matrix *m, struct Pixel *p);

void pixel_color(struct Pixel *p, unsigned char r, unsigned char g, unsigned char b);

//helper function to find the norm of two vectors
//p1, p2, p3 are indices
//goes counterclockwise starting at p1
void find_norm(struct Matrix *m, int p1, int p2, int p3,
		float *norm_out);

void draw_polygons(Frame f, struct Matrix *m, struct Pixel *p);

#endif

