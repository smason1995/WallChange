wallchange: source.o
	gcc -o wallchange source.o cli.c

source.o:
	gcc -o source.o wallchange.c -c

clean:
	rm *.o wallchange
