CC=g++
LIBS = -lGL -lGLU -lglut -lm
CFLAGS = -g -Wall
HEADERS = $(wildcard *.h)

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

default: demo

demo: main_cpp.o $(OBJECTS)
	$(CC) $(CFLAGS) -o demo main_cpp.o gl_canvas2d.o auxFunc.o Point.o CtrlPoint.o Bezier.o Object3D.o Scene.o Slider.o Interface.o Button.o $(LIBS)

clean: 
	$(RM) demo *.o 
