CC=clang
CFLAGS=-Wall -Wpedantic -m64 -march=native -O3 

UTILITIES=bin/true bin/false

all: $(UTILITIES)

bin/%: %.c $(DEPS)
	mkdir -p bin
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -rf bin
