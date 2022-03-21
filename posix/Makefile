CC=clang++
CFLAGS=-std=c++20 -O3 -march=native

UTILITIES=bin/basename bin/cat bin/false  bin/nohup bin/pwd bin/sleep bin/true

all: $(UTILITIES)

bin/%: %.cc 
	@echo "Building $(notdir $<)"
	@ mkdir -p bin
	@ $(CC) -o $@ $< $(CFLAGS)

clean:
	rm bin/*
