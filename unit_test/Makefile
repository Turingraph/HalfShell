CC = cc -Wall -Wextra -Werror
SRC_string = $(wildcard string/*.c)
OUT_string = $(patsubst %.c, out/%.out,	$(SRC_string))
SRC_parser = $(wildcard parser/*.c)
OUT_parser = $(patsubst %.c, out/%.out,	$(SRC_parser))

all: $(OUT_string) $(OUT_parser)

$(OUT_string): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/string.a

$(OUT_parser): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/get_next_line.a ../src/lib/parser.a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

clean:
	rm -r -f lib/
	rm -r -f obj/

.PHONY: all clean
