#include <stdio.h> // remove later
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "words.h"
#ifndef BUFSIZE
#define BUFSIZE 128
#endif
static char buf[BUFSIZE];
static unsigned pos;
static unsigned bytes;
static int closed;
static int input;

// isspace but \n is not whitespace
int is_space(char c) {
    if (c == '\n') return 0;
    return isspace(c);
}

void words_init(int fd)
{
    input = fd;
    pos = 0;
    bytes = 0;
    closed = 0;
}

char *words_next(void)
{
    if (closed)
        return NULL;
    // skip whitespace
    while (1)
    {
        // ensure we have a char to read
        if (pos == bytes)
        {
            bytes = read(input, buf, BUFSIZE);
            // for (int i = 0; i < bytes; i++)
            //     printf("%c", buf[i]);
            // printf("\n");
            if (bytes < 1)
            {
                closed = 1;
                return NULL;
            }
            pos = 0;
        }
        if (!is_space(buf[pos]))
            break;
        ++pos;
    }
    // start reading a word
    int start = pos;
    char *word = NULL;
    int wordlen = 0;
    do
    {
        // printf("2\n");
        ++pos;
        if (pos == bytes)
        {
            // save word so far
            // printf("1\n");
            int fraglen = pos - start;
            word = realloc(word, wordlen + fraglen + 1);
            memcpy(word + wordlen, buf + start, fraglen);
            wordlen += fraglen;
            // for (int i = 0; i < wordlen; i++) {
            //     printf("%c", word[i]);
            // }
            // printf("*2\n");
            if (buf[pos-1] == '\n' || buf[pos-1] == '<' || buf[pos-1] == '>' || buf[pos-1] == '|') {
                // printf("break\n");
                word[wordlen] = '\0';
                return word;    
            }
            // refresh the buffer
            bytes = read(input, buf, BUFSIZE);
            // printf("buffer: ");
            // for (int i = 0; i < bytes; i++)
            //     printf("%c", buf[i]);
            // printf("\n");
            if (bytes < 1)
            {
                closed = 1;
                break;
            }
            pos = 0;
            start = 0;
        } else if (buf[pos-1] == '\n' || buf[pos-1] == '<' || buf[pos-1] == '>' || buf[pos-1] == '|') {
            int fraglen = pos - start;
            word = realloc(word, wordlen + fraglen + 1);
            memcpy(word + wordlen, buf + start, fraglen);
            wordlen += fraglen;
            // printf("break\n");
            word[wordlen] = '\0';
            return word;    
        }
    } while (!is_space(buf[pos]));
    // grab the word from the current buffer
    // (Note: start == pos if we refreshed the buffer and got a space first.)
    if (start < pos)
    {
        int fraglen = pos - start;
        word = realloc(word, wordlen + fraglen + 1);
        memcpy(word + wordlen, buf + start, fraglen);
        wordlen += fraglen;
    }
    if (word)
    {
        // if (buf[pos] == '\n') {
        //     word[wordlen] = '\n';
        //     word[wordlen+1] = '\0'
        // } else {
        //     word[wordlen] = '\0';
        // }
        word[wordlen] = '\0';
    }
    return word;
}