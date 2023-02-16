exec = SLlang.out
sources = $(wildcard src/*.c)
objects = $(sources: .c=.sll)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.sll: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./SLlang.out /usr/local/bin/SLlang

clean:
	-rm  *.out
	-rm *.o
	-rm src/*.o
