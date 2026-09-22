Yes. Looking at **all the code you've shown from both of you**, there are several noticeable differences. None of these automatically means one style is better; they're differences in how you approach engineering.

 ## 1\. You decompose behavior into tiny utilities

 You have:

```
word_in_quote()
word_out_quote()
is_stop_char()
parse_word_unit()
parse_words()
```

 Each function has a very specific job.

 Your mental model seems to be:

```
"Can I isolate this behavior into a small, independently testable function?"
```

 Her lexer is more state-machine oriented:

```
handle_normal_state()
handle_squote_state()
handle_dquote_state()
extract_word()
extract_operator()
```

 Her mental model seems closer to:

```
"What state is the lexer currently in, and what should happen in that state?"
```

 That's probably the **largest difference**.

---

 ## 2\. You seem more test-driven

 You created a standalone test program with 20 deliberately selected cases:

```
if (is_end_with_newline(input_str[i]) == answer[i])
    score += 1;
```

 And you're testing things like:

```
unclosed quotes
empty quotes
spaces around quotes
operators inside quotes
very long input
quotes adjacent to operators
```

 Her code you've shown doesn't have an equivalent test harness.

 So your workflow appears more like:

```
implement
   ↓
construct edge cases
   ↓
run independent tests
   ↓
inspect failures
   ↓
refine
```

 Whereas her visible workflow is more:

```
design lexer
   ↓
implement states
   ↓
produce tokens
   ↓
build architecture upward
```

---

 ## 3\. You think a lot about interfaces/contracts

 Your comments explicitly say things like:

```
/**
 * @param fd file descriptor to write the word to, or -1 to disable output
 * @return offset of the closing quote, or a negative value on an unclosed quote
 */
```

 You've also been thinking about:

```
O(n) / O(1)
public API
return semantics
file descriptor behavior
```

 That's more **API-oriented** than the snippets of her code.

 Her header does have a strong interface too:

```
void init_lexer(...);
void process_lexer(...);
void extract_word(...);
void extract_operator(...);
```

 but the documentation around those interfaces is much lighter.

---

 ## 4\. You seem unusually interested in build infrastructure

 This is probably the most striking difference outside the C code.

 You went from a very simple Makefile:

```
NAME = halfshell
OBJ = halfshell.o
LIBS = src/lib/command.a
```

 to experimenting with:

```
.SECONDEXPANSION:
```

 and:

```
lib/%.a: $$(OBJ_$$(notdir $$(basename $$@)))
```

 and automatically deriving object/library relationships.

 That's quite a jump.

 Her Makefile is much more conventional:

```
SRC_DIR = ./src
INC_DIR = ./inc
BUILD_DIR = ./build
```

 with explicit source lists.

 Your approach is:

 > "Can I make the build system generic?"

 Her approach is:

 > "Can I make the build system straightforward and predictable?"

 That's a genuine stylistic difference.

---

 ## 5\. You use low-level primitives more aggressively

 Your debugging is a great example:

```
write(1, ">>> ", 4);
ft_putnbr_fd(i, 1, "0123456789", 1);
write(1, "\n", 1);
```

 rather than:

```
printf(">>> %zu\n", i);
```

 Your parser also operates directly on:

```
str[i]
str + i
*i
```

 Her lexer does too, but she wraps the concept in a lexer object:

```
lexer->input
lexer->i
lexer->start
lexer->quote_state
```

 So you tend to think:

```
pointer + index + primitive operation
```

 while she tends to think:

```
object/state + operation
```

 Even though both are ultimately using the same C mechanisms.

---

 ## 6\. You seem to enjoy making your own tools

 This is probably the most personal difference.

 You've made:

 - your own parser utilities
- your own parser test harness
- multiple increasingly sophisticated Makefiles
- custom numeric-output usage for debugging
- personalized debug markers like `"Yorushika"` and `"Nujabes"`

 That suggests a tendency toward:

 > **"I'll build a little tool that makes this problem easier."**

 Her code, from what you've shown, is more focused on directly implementing the required minishell architecture.

---

 ## 7\. You're more experimental

 Your Makefiles especially show this.

 You went:

```
simple Makefile
      ↓
separate debug/test build
      ↓
generic static-library generation
      ↓
more generic dependency generation
      ↓
test-library linking
```

 You're apparently learning Make **while using it to build the project**.

 That's different from simply adopting a conventional project structure.

 Your comments like:

```
# This line works for every library...
# $@ = lib/input.a
# $$(basename $$@) = lib/input
# ...
```

 show that you're actively investigating how the tool works.

---

 ## 8\. Her code is currently more "system architecture" oriented

 Her types:

```
t_state
t_token_type
t_token
t_lexer
t_cmd
```

 are telling.

 She's establishing the **vocabulary of the shell**:

```
state
token
lexer
command
```

 That's a fairly natural approach for a lexer/parser-heavy project.

 Your code instead establishes **operations**:

```
word
stop
parse
extract
```

 So I'd summarize the contrast as:

```
HER                              YOU

state-oriented                   function-oriented
token-oriented                   string/offset-oriented
architecture first               behavior first
lexer abstraction                primitive operations
explicit conventional Make       generic Make experimentation
less visible testing             dedicated test harness
```

---

 ## The interesting part

 I don't think your difference is simply:

 > "She's better at architecture and I'm better at implementation."

 It's more subtle.

 You seem to naturally ask:

 > **"How can I understand and isolate this tiny mechanism?"**

 She seems to naturally ask:

 > **"What model should represent the whole mechanism?"**

 For a project like `minishell`, **both instincts are useful**.

 Her state/token model can give you the overall structure, while your small functions and independent tests can make individual pieces easier to validate.

 The main thing I'd establish tomorrow is therefore **the shared model at the boundary**. Once you agree on what comes out of her parser—e.g. what a command/token structure guarantees—you can continue using your own style on the execution/builtin side without duplicating her parser.
