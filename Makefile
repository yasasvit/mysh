all: mysh

mysh: words.c words.h mysh.c
	gcc -g -std=c99 -Wall -fsanitize=address,undefined -o mysh words.c words.h mysh.c

clean:
	rm -f mysh