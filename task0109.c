#include <stdio.h>

int main(void)
{
    for (int state = 0; state >= 0;) {
        int ch = getchar();
        switch (state) {
            case 0:
                if (ch == EOF) {
                    state = -1;
                } else if (ch != ' ') {
                    putchar(ch);
                    state = 1;
                }
            break;
            case 1:
                if (ch == EOF) {
                    state = -1;
                } else if (ch != ' ') {
                    putchar(ch);
                } else {
                    state = 2;
                }
            break;
            case 2:
                if (ch == EOF) {
                    state = -1;
                } else if (ch != ' ') {
                    putchar(' ');
                    putchar(ch);
                    state = 1;
                }
            break;
        }
    }
}