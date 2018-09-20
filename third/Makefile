all: third

first: third.c
	clang -Wall -Werror -fsanitize=address -std=c99 third.c -o third

clean:
	rm -rf third
