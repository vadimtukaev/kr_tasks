#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NCHARS 26u
#define HEIGHT 22u

int main(void)
{
    unsigned freq[NCHARS];
    memset(freq, 0, sizeof(freq));
    unsigned maxfreq = 0;
    for (int ch; (ch = getchar()) != EOF;) {
        if (isalpha(ch)) {
            unsigned curfreq = ++freq[(unsigned)(toupper(ch) - 'A')];
            if (curfreq > maxfreq) maxfreq = curfreq;
        }
    }
    unsigned i;
    if (maxfreq != 0) {
        for (i = 0; i < NCHARS; ++i) {
            freq[i] = (HEIGHT * freq[i] + maxfreq / 2) / maxfreq;
        }
    }
    for (i = HEIGHT; i != 0; --i) {
        for (unsigned j = 0; j < NCHARS; ++j) {
            printf(freq[j] < i ? "   " : "## ");
        }
        printf("\n");
    }
    for (i = 0; i < NCHARS; ++i) {
        printf("%c%c ", i + 'A', i + 'a');
    }
    printf("\n");
    return 0;
}