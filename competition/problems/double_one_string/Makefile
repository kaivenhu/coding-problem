include ../../../Makefile.inc

SRC = $(wildcard ./*.cc)
OBJ = $(SRC:.cc=.o)
EXE = $(patsubst %.cc,%.exe, $(wildcard ./*.cc))

CXXFLAGS += -Wno-unused -g

.PHONY: all clean $(EXE) $(OBJ)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	./${EXE} < double_or_one_thing_sample_ts1_input.txt > out.txt
	diff out.txt double_or_one_thing_sample_ts1_output.txt

$(OBJ): %.o:%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE)
