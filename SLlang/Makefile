exec = SLlang.out
sources = $(wildcard src/*.c)
objects = $(sources: .c=.sll)
flags = -g
PREFIX := /usr/local

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.sll: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./SLlang.out $(PREFIX)/bin/sllang

clean:
	rm  *.out -f
