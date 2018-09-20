all: second

first: second.c
	clang -Wall -Werror -fsanitize=address -std=c99 second.c -o second

clean:
	rm -rf second
