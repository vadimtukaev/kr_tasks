#include <ctype.h>
#include <stdio.h>

typedef enum {
    BEFORE_WORD,
    INSIDE_WORD,
    AFTER_WORD
} State;

int main(void)
{
    State state = BEFORE_WORD;

    for (int ch; (ch = getchar()) != EOF;) {
        if (isspace(ch)) {
            if (state == INSIDE_WORD) state = AFTER_WORD;
        } else {
            printf(state == AFTER_WORD ? "\n%c" : "%c", ch);
            state = INSIDE_WORD;
        }
    }
}