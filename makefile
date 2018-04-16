OBJS = draw.o output.o matrix.o parser.o shapes.o rcs.o main.o
OUTPUT = picture.ppm
EXEC = exec
MATH_LIB = -lm
SCRIPT=test

all: $(OBJS)
	gcc -o $(EXEC) $(OBJS) $(MATH_LIB)
	./$(EXEC) $(SCRIPT)

main.o:
	gcc $(DBG) -Wall -c main.c include/draw.h include/output.h include/rcs.h

draw.o:
	gcc $(DBG) -Wall -c draw.c include/draw.h

output.o:
	gcc $(DBG) -Wall -c output.c include/output.h

matrix.o:
	gcc $(DBG) -Wall -c matrix.c include/matrix.h

parser.o:
	gcc $(DBG) -Wall -c parser.c include/parser.h 

shapes.o:
	gcc $(DBG) -Wall -c shapes.c include/shapes.h

rcs.o:
	gcc $(DBG) -Wall -c rcs.c include/rcs.h

clean:
	rm -rf *.o $(OUTPUT)

