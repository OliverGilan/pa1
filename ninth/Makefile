all: ninth

first: ninth.c
	clang -Wall -Werror -fsanitize=address -std=c99 ninth.c -o ninth

clean:
	rm -rf ninth