#include <stdio.h>

int main(void)
{
    int not_eof;
    do {
        not_eof = getchar() != EOF;
        printf("%d\n", not_eof);
    } while (not_eof);
}