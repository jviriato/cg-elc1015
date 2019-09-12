CC=g++
LIBS = -lGL -lGLU -lglut -lm
CFLAGS = -g -Wall
HEADERS = $(wildcard *.h)

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

default: demo

demo: main_cpp.o $(OBJECTS)
	$(CC) $(CFLAGS) -o demo main_cpp.o Car.o Spline.o CtrlPoint.o Point.o auxFunc.o $(LIBS)

clean: 
	$(RM) demo *.o 
