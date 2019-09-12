#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 20u
#define HEIGHT 22u

int main(void)
{
    unsigned wordlen[MAXLEN];
    unsigned len, i, j;
    int ch;

    memset(wordlen, 0, sizeof(wordlen));
    len = 0;
    do {
        ch = getchar();
        if (ch == EOF || isspace(ch)) {
            if (len != 0 && len <= MAXLEN) ++wordlen[len - 1u];
            len = 0;
        } else {
            ++len;
        }
    } while (ch != EOF);
    len = 0;
    for (i = 0; i < MAXLEN; ++i) {
        if (wordlen[i] > len) len = wordlen[i];
    }
    if (len == 0) {
        printf("ERROR: No words to display.\n");
        return 0;
    }
    for (i = 0; i < MAXLEN; ++i) {
        wordlen[i] = (HEIGHT * wordlen[i] + len / 2) / len;
    }
    for (i = HEIGHT; i != 0; --i) {
        for (j = 0; j < MAXLEN; ++j) {
            printf("%s%c", wordlen[j] < i ? "   " : "###", j == MAXLEN - 1u ? '\n' : ' ');
        }
    }
    for (i = 1u; i <= MAXLEN; ++i) {
        printf(" %u%s", i, i < 10u ? "  " : " ");
    }
    return 0;
}