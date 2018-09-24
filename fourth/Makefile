all: fourth

first: fourth.c
	clang -Wall -Werror -fsanitize=address -std=c99 fourth.c -o fourth

clean:
	rm -rf fourth
