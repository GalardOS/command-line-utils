CC=clang++
CFLAGS=-std=c++20
LDFLAGS=

UTILITIES=bin/basename bin/cat bin/false  bin/nohup bin/pwd bin/sleep bin/true

all: $(UTILITIES)

bin/%: %.cc $(DEPS)
	mkdir -p bin
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm bin/*
