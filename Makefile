include Makefile.inc

.PHONY: all $(SRC_DIR) $(LEETCODE_DIR) clean clean-$(SRC_DIR) clean-$(LEETCODE_DIR)

all: $(SRC_DIR) $(LEETCODE_DIR)

clean: clean-$(SRC_DIR) clean-$(LEETCODE_DIR)

$(SRC_DIR):
	$(MAKE) -C $@;

clean-$(SRC_DIR):
	$(MAKE) clean -C $(SRC_DIR);

$(LEETCODE_DIR):
	$(MAKE) -C $@ Dleetcode-problem=$(Dleetcode-problem);

clean-$(LEETCODE_DIR):
	$(MAKE) clean -C $(LEETCODE_DIR) Dleetcode-problem=$(Dleetcode-problem);

