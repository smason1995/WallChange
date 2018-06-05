wallchange: source.o
	gcc --std=gnu99 -o wallchange wallchange.o cli.c

source.o:
	gcc --std=gnu99 -o wallchange.o wallchange.c -c

clean:
	rm *.o wallchange
