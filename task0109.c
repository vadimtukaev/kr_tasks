#include <stdio.h>

int main(void)
{
    for (int prev = ' ', curr; (curr = getchar()) != EOF; prev = curr) {
        if (prev != ' ' || curr != ' ') {
            putchar(curr);
        }
    }
}