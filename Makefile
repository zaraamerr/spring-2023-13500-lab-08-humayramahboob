
main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h
main.o: main.cpp funcs.cpp funcs.h
funcs.o: funcs.cpp funcs.h imageio.h
imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o main.o funcs.o