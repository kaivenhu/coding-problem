include ../../Makefile.inc

ifeq ($(Dleetcode-problem),)
	EXE_DIR = $(sort $(dir $(wildcard ./*/*$(UNITTEST_SUFFIX))))
else
	EXE_DIR = $(Dleetcode-problem)
endif

.PHONY: all clean $(EXE_DIR)

all: $(EXE_DIR)

clean: $(EXE_DIR)

$(EXE_DIR):
	$(MAKE) -C $@ $(MAKECMDGOALS);
