CXX = gcc

SRCS = $(wildcard *.c)

asm: main.o
	gcc -no-pie -nostdlib -c main.s -o main.o
	gcc -no-pie -nostdlib -o main main.o

build: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS) $(CXXLIBS)

clean:
	rm -f build

.PHONY: clean