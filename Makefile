CXX=gcc
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c11 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  randomMean

randomMean: randomMean.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o.cc: %.c %.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o randomMean