compiler:compiler.o func.o
	g++ -o compiler compiler.o func.o -Wall

compiler.o:compiler.cc compiler.h
	g++ -c compiler.cc -Wall

func.o:func.cc compiler.h
	g++ -c func.cc -Wall

clean:
	rm compiler compiler.o func.o
