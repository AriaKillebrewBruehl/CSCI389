CXX=gcc
CXX_FLAGS=-Wall -Wextra -pedantic -std=c11 -O3
C++_FLAGS=-Wall -Wextra -pedantic -std=c++11 -O3
.PHONY: all clean
TARGETS=benchmarking barriers

all: $(TARGETS)

benchmarking.o: part1.h
benchmarking.o: part1.c
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

benchmarking: benchmarking.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

barriers.o: barriers.hh
barriers.o: barriers.cc
	g++ $(C++_FLAGS) -c -o $@ $<

barriers: barriers.o
	g++ $(C++_FLAGS) -o $@ $^

clean:
	rm -f *~ *.o $(TARGETS)
