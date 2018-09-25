all: seventh

first: seventh.c
	clang -Wall -Werror -fsanitize=address -std=c99 seventh.c -o seventh

clean:
	rm -rf seventh
