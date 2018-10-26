CC=g++
CFLAGS = -Wall `pkg-config --static --libs glfw3`
LIBS = `pkg-config --cflags glfw3` -lGL

PREQ = Plt.o Ax.o Win.o
MAIN = main.o
all: pltr

pltr: ${PREQ} ${MAIN}
	${CC} -o $@ ${CFLAGS} $^ ${LIBS}

#hhn: main.o HHn.o
#	${CC} -o $@ ${CFLAGS} $^ ${LIBS}

.cpp.p:
	${CC} -c $< ${CFlAGS} ${LIBS}

clean:
	rm -rf *.o

# cc `pkg-config --cflags glfw3` -o myprog myprog.c `pkg-config --static --libs glfw3`

