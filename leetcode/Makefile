include ../Makefile.inc

TAG_DIR=stack

.PHONY: all clean $(TAG_DIR)

all: $(TAG_DIR)

clean: $(TAG_DIR)

$(TAG_DIR):
	$(MAKE) -C $@ $(MAKECMDGOALS) Dleetcode-problem=$(Dleetcode-problem);
