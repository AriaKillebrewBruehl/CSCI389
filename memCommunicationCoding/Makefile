CXX=g++-10
CXXFLAGS=-fsanitize=address -Wall -Wextra -pedantic  -std=c++17
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  bench_marking

bench_marking:part1.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o.cc: %.c %.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o bench_marking