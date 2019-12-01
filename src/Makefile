include ../Makefile.inc

SRC = $(wildcard ./*.cc)
OBJ = $(SRC:.cc=.o)

.PHONY: all clean

all: $(SHLIB)

$(SHLIB): $(OBJ)
	$(CXX) -shared -o $@ $^

$(OBJ): %.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(SHLIB)

