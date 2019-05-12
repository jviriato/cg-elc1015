CC=g++
LIBS = -lGL -lGLU -lglut -lm
CFLAGS = -g -Wall
HEADERS = $(wildcard *.h)

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

default: demo

demo: main_cpp.o $(OBJECTS)
	$(CC) $(CFLAGS) -o demo main_cpp.o gl_canvas2d.o Piece.o auxFunc.o Wheel.o Pedal.o $(LIBS)

clean: 
	$(RM) demo *.o 
