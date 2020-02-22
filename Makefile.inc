MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(realpath $(patsubst %/,%,$(dir $(MKFILE_PATH))))
PROJ_PATH=$(CURRENT_DIR)

LIB_NAME=coding

INCLUDE_DIR=$(PROJ_PATH)/include
SRC_DIR := src
LEETCODE_DIR := leetcode
CPP_PRIMER := cpp-primer
SHLIB = lib$(LIB_NAME).so

UNITTEST_SUFFIX := unittest.cc

########### Compile Options #############

INCS_INNER = -I$(INCLUDE_DIR)
LIBS_INNER = -L$(PROJ_PATH)/src -l$(LIB_NAME)

LDFLAGS += $(LIBS_INNER) -Wl,-rpath,$(PROJ_PATH)/src

CXXFLAGS += -std=c++17 -g -Wall -W -Werror -fPIC $(INCS_INNER)
