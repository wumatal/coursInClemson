

SHELL = bash

# ===============================================================

SRCS 	 	= basic/main.cpp \
		  basic/matrix.cpp \
		  basic/camera.cpp \
		  basic/glCanvas.cpp \
		  mesh/mesh.cpp \
		  mesh/edge.cpp

# ===============================================================

LIBS            = -lm -lGL -lGLU -lglut -L/usr/X11R6/lib
CC		= g++ -I/usr/X11R6/include -I/usr/local/include
EXE 	  	= adjacency
OBJS =  $(SRCS:.cpp=.o)

# ===============================================================
# targets

.PHONY: all depend clean

all: depend $(EXE)

depend:
	$(CC) -E -M $(SRCS) > Makefile.depend

clean:
	-rm -f */*~ */*bak */*.o  core.* Makefile.depend $(EXE)

# ===============================================================
# compilation rules

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.cpp.o:
	$(CC) -g3 $< -c -o $@

# ===============================================================

-include Makefile.depend
