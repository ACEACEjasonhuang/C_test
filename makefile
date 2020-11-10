.PHONY: clean
all: main.o c_test/test.o
	gcc  main.o c_test/test.o -o ./bin/c_testing
main.o: main.c c_test/test.h
	gcc  -I./ -c main.c
c_test/test.o: c_test/test.c c_test/test.h c_test/linklist.h
	gcc  -I./ -c c_test/test.c -o c_test/test.o
clean:
	rm -rf ./bin/c_testing main.o c_test/test.o

