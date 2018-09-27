all: eighth

first: eighth.c
	clang -Wall -Werror -fsanitize=address -std=c99 eighth.c -o eighth

clean:
	rm -rf eighth