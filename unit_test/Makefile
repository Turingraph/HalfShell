CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)

SRC_string = $(wildcard string/*.c)
LIB_string = $(patsubst %, ../src/lib/%.a, string)

SRC_get_next_line = $(wildcard get_next_line/*.c)
LIB_get_next_line = $(patsubst %, ../src/lib/%.a, get_next_line string)

SRC_parser = $(wildcard parser/*.c)
LIB_parser = $(patsubst %, ../src/lib/%.a, get_next_line parser)

OUT = $(patsubst %.c, out/%.out, $(SRC_get_next_line) $(SRC_string) $(SRC_parser))

all: $(OUT)

$(OUT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. $(LIB_$(notdir $(call remove_slash, $(dir $@))))

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

clean:
	rm -r -f lib/
	rm -r -f obj/

.PHONY: all clean
