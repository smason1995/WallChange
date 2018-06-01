wallchange: source.o
	gcc -o wallchange wallchange.o cli.c

source.o:
	gcc -o wallchange.o wallchange.c -c

clean:
	rm *.o wallchange
