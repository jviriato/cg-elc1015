CC=g++
LIBS = -lGL -lGLU -lglut -lm
CFLAGS = -g -Wall
HEADERS = $(wildcard *.h)

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

default: demo

demo: main_cpp.o $(OBJECTS)
	$(CC) $(CFLAGS) -o demo main_cpp.o gl_canvas2d.o auxFunc.o Wheel.o Frame.o Pedal.o Bicycle.o  $(LIBS)

clean: 
	$(RM) demo *.o 
