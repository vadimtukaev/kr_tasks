#include <stdio.h>

int main(void)
{
    unsigned nl = 0u;
    unsigned nw = 0u;
    unsigned nc = 0u;

    for (int prev = 1, curr; (curr = getchar()) != EOF; prev = curr) {
        ++nc;
        if (curr == '\n') ++nl;
        curr = curr == ' ' || curr == '\n' || curr == '\t';
        if (prev && !curr) ++nw;
    }
    printf("lines:\t%u\nwords:\t%u\nchars:\t%u\n", nl, nw, nc);
}