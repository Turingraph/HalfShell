
#-----------------------------------------------------------------------------------------------
# *** command ***

CC = cc -Wall -Wextra -Werror

#-----------------------------------------------------------------------------------------------
# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:

# *** library ***

# I will have to fix this lines.
LIBRARY = $(patsubst %, lib/%.a, string get_next_line parser command)
SRC_string = $(wildcard string/*.c)
OBJ_string = $(patsubst %.c, obj/%.o, $(SRC_string))
SRC_get_next_line = $(wildcard get_next_line/*.c)
OBJ_get_next_line = $(patsubst %.c, obj/%.o, $(SRC_get_next_line))
SRC_parser = $(wildcard parser/*.c)
OBJ_parser = $(patsubst %.c, obj/%.o, $(SRC_parser)) $(OBJ_string)
SRC_command = $(wildcard command/*.c)
OBJ_command = $(patsubst %.c, obj/%.o, $(SRC_command)) $(OBJ_parser) $(OBJ_get_next_line)

#-----------------------------------------------------------------------------------------------
# *** create library ***

all: $(LIBRARY)

# This line works for every library in $(LIBRARY) list, but I use lib/input.a as a simple example.
# $@ = lib/input.a
# $$(basename $$@) = lib/input
# $$(notdir $$(basename $$@)) = input
# OBJ_$$(notdir $$(basename $$@)) = OBJ_input
# $$(OBJ_$$(notdir $$(basename $$@))) = $(OBJ_input)
lib/%.a: $$(OBJ_$$(notdir $$(basename $$@)))
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/input/get_next_line/%.o: input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f obj/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
