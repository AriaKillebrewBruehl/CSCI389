CXX=gcc
CXXFLAGS=-fsanitize=address -Wall -Wextra -pedantic -Werror -std=c11 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  update_locations

update_locations: update_locations.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o.cc: %.c %.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o update_locations