include ../Makefile.inc

SRC = $(wildcard ./*.cc)
OBJ = $(SRC:.cc=.o)

LDFLAGS += -lgtest -lgtest_main -lpthread

.PHONY: all clean

all: $(SHLIB)

$(SHLIB): $(OBJ)
	$(CXX) -shared -o $@ $^

$(OBJ): %.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(SHLIB)

