#include"include/draw.h"

void pixel_color(struct Pixel *p, unsigned char r,
		unsigned char g, unsigned char b) {
	p->r = r;
	p->g = g;
	p->b = b;
}

void plot_point(Frame grid, int x, int y, struct Pixel *p) {
	//printf("Plotting %d, %d (%d, %d)\n", x, IMG_HEIGHT-1-y, x, y);
	if (x > -1 && y > -1) {
		grid[IMG_HEIGHT-1-y][x] = *p;
	}
	//grid[y][x] = *p;	//if top left is (0, 0)
}

void draw_lines(Frame grid, struct Matrix *m, struct Pixel *p) {
	int x;
	for (x = 1; x < m->back; x+=2) {
		draw_line(grid, p,
				m->m[0][x-1], m->m[1][x-1],
				m->m[0][x], m->m[1][x]);
	}
}

void draw_line(Frame grid, struct Pixel *p, int x1, int y1, int x2, int y2) {
	//make sure x1 y1 is the left point
	if (x1 > x2) {
		int temp = x1;
		x1 = x2;
		x2 = temp;
		
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	int a = y2-y1;
	int b = -(x2-x1);
	int d;
	
	float m = ((float)a)/(-b);
	//printf("%d, %d %f\n", a, -b, m);
	
	//octant 1
	if (m >= 0 && m <= 1) {
		if (x1 > x2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
			
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		a = y2-y1;
		b = -(x2-x1);
		
		d = 2*a + b;
		//printf("1\n");
		
		while (x1 <= x2 && x1 < IMG_WIDTH) {
			plot_point(grid, x1, y1, p);
			
			if (d > 0) {
				y1++;
				d += 2*b;
			}
			
			x1++;
			d += 2*a;
		}
	}
	//octant 2
	else if (m > 1) {
		if (y1 > y2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
			
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		a = y2-y1;
		b = -(x2-x1);
		
		d = a + 2*b;
		//printf("2\n");
		
		while (y1 <= y2 && y1 < IMG_HEIGHT) {
			plot_point(grid, x1, y1, p);
			
			if (d < 0) {
				x1++;
				d += 2*a;
			}
			
			y1++;
			d += 2*b;
		}
	}
	//octant 8
	else if (m < 0 && m >= -1) {
		if (x1 > x2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
			
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		a = y2-y1;
		b = -(x2-x1);
		
		d = 2*a - b;
		//printf("8\n");
		
		while (x1 <= x2 && x1 < IMG_WIDTH) {
			plot_point(grid, x1, y1, p);
			
			if (d < 0) {
				y1--;
				d -= 2*b;
			}
			
			x1++;
			d += 2*a;
		}
	}
	//octant 7
	else if (m < -1) {
		if (y1 < y2) {
			int temp = x1;
			x1 = x2;
			x2 = temp;
			
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		a = y2-y1;
		b = -(x2-x1);
		
		d = a - 2*b;
		//printf("7\n");
		
		while (y1 >= y2 && y1 < IMG_HEIGHT) {
			plot_point(grid, x1, y1, p);
			
			if (d > 0) {
				x1++;
				d += 2*a;
			}
			
			y1--;
			d -= 2*b;
		}
	}
}


void draw_polygons(Frame f, struct Matrix *m, struct Pixel *p) {
	int x;
	for (x = 0; x < m->back; x+=3) {
		draw_line(f, p,
			m->m[0][x],
			m->m[1][x],
			m->m[0][(x+1)],
			m->m[1][(x+1)]
		);
		draw_line(f, p,
			m->m[0][(x+1)],
			m->m[1][(x+1)],
			m->m[0][(x+2)],
			m->m[1][(x+2)]
		);
		draw_line(f, p,
			m->m[0][(x+2)],
			m->m[1][(x+2)],
			m->m[0][x],
			m->m[1][x]
		);
	}
}


