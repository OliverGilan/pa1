all: sixth

first: sixth.c
	clang -Wall -Werror -fsanitize=address -std=c99 sixth.c -o sixth

clean:
	rm -rf sixth
