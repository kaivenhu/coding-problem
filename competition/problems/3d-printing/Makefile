include ../../../Makefile.inc

SRC = $(wildcard ./*.cc)
OBJ = $(SRC:.cc=.o)
EXE = $(patsubst %.cc,%.exe, $(wildcard ./*.cc))

CXXFLAGS += -Wno-unused

.PHONY: all clean $(EXE) $(OBJ)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	./${EXE} < 3d_printing_sample_ts1_input.txt > out.txt
	diff out.txt 3d_printing_sample_ts1_output.txt

$(OBJ): %.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE)
