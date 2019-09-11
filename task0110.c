#include <stdio.h>

int main(void)
{
    for (int ch; (ch = getchar()) != EOF;) {
        switch (ch) {
            case '\t':
                printf("\\t");
            break;
            case '\\b':
                printf("\\b");
            break;
            case '\\':
                putchar('\\');
            break;
            default:
                putchar(ch);
            break;
        }
    }
}