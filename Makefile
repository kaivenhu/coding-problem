include Makefile.inc

.PHONY: all $(SRC_DIR) $(LEETCODE_DIR) clean clean-$(SRC_DIR) clean-$(LEETCODE_DIR) \
	$(CPP_PRIMER) clean-$(CPP_PRIMER) $(ALGORITHM) clean-$(ALGORITHM)


all: $(SRC_DIR) $(LEETCODE_DIR) $(CPP_PRIMER)

clean: clean-$(SRC_DIR) clean-$(LEETCODE_DIR) clean-$(CPP_PRIMER)

$(SRC_DIR) $(CPP_PRIMER) $(ALGORITHM):
	$(MAKE) -C $@;

clean-$(SRC_DIR):
	$(MAKE) clean -C $(SRC_DIR);

$(LEETCODE_DIR):
	$(MAKE) -C $@ Dleetcode-problem=$(Dleetcode-problem);

clean-$(LEETCODE_DIR):
	$(MAKE) clean -C $(LEETCODE_DIR) Dleetcode-problem=$(Dleetcode-problem);

clean-$(CPP_PRIMER):
	$(MAKE) clean -C $(CPP_PRIMER);

clean-$(ALGORITHM):
	$(MAKE) clean -C $(ALGORITHM);

