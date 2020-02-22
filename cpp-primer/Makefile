include ../Makefile.inc

EXE_DIR = $(sort $(dir $(wildcard ./*/*$(UNITTEST_SUFFIX))))

.PHONY: all clean $(EXE_DIR)

all: $(EXE_DIR)

clean: $(EXE_DIR)

$(EXE_DIR):
	$(MAKE) -C $@ $(MAKECMDGOALS);
