include ../../../Makefile.inc

SRC = $(wildcard ./*.cc)
OBJ = $(SRC:.cc=.o)
EXE = $(patsubst %.cc,%.exe, $(wildcard ./*$(UNITTEST_SUFFIX)))

LDFLAGS += -lgtest -lgtest_main -lpthread

.PHONY: all clean $(EXE) $(OBJ)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ): %.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE)
