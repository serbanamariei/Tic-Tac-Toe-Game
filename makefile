main: main.o functii.o
	clang -Wall main.o functii.o -o main

main.o: main.c functii.h
	clang -c -Wall main.c

functii.o: functii.c functii.h
	clang -c -Wall functii.c

.PHONY: clean

clean:
	rm -f *.o
	rm -f main
