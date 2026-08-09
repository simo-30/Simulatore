CC := gcc

TARGET_NAME := test_punto
BASE_CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
CFLAGS ?= $(BASE_CFLAGS)
CPPFLAGS ?= -MMD -MP
LDFLAGS ?=
LDLIBS ?=

SRC := test.c punto.c ../Archivio/archivio.c ../ID/id.c

OBJ := $(SRC:.c=.o)
DEP := $(OBJ:.o=.d)

ifeq ($(OS),Windows_NT)
    EXE_EXT := .exe
    RUN_CMD := .\$(TARGET_NAME)$(EXE_EXT)
    CLEAN_CMD = del /Q $(subst /,\,$(OBJ) $(DEP) $(TARGET)) 2>NUL
else
    EXE_EXT :=
    RUN_CMD := ./$(TARGET_NAME)$(EXE_EXT)
    CLEAN_CMD = rm -f $(OBJ) $(DEP) $(TARGET)
endif

TARGET := $(TARGET_NAME)$(EXE_EXT)

.PHONY: all run clean rebuild

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(RUN_CMD)

clean:
	-$(CLEAN_CMD)

rebuild:
	$(MAKE) -f $(firstword $(MAKEFILE_LIST)) clean
	$(MAKE) -f $(firstword $(MAKEFILE_LIST)) all

-include $(DEP)
