#include <stdio.h>

int main(void)
{
    unsigned ns = 0u;
    unsigned nt = 0u;
    unsigned nl = 0u;

    for (;;) {
        switch (getchar()) {
            case EOF:
                goto end;
            case ' ':
                ++ns;
            break;
            case '\t':
                ++nt;
            break;
            case '\n':
                ++nl;
            break;
        }
    }
end:
    printf("spaces:\t%u\ntabs:\t%u\nlines:\t%u\n", ns, nt, nl);
}