#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *buf;
    size_t len;
    size_t siz;
} Line;

void Line_clear(Line *self)
{
    self->buf[0] = '\0';
    self->len = 0;
}

void Line_init(Line *self)
{
    self->siz = 256u;
    self->buf = malloc(sizeof(char) * self->siz);
    Line_clear(self);
}

void Line_add(Line *self, char ch)
{
    self->buf[self->len] = ch;
    ++self->len;
    if (self->len == self->siz) {
        self->siz *= 2u;
        self->buf = realloc(self->buf, self->siz);
    }
    self->buf[self->len] = '\0';
}

void Line_destroy(Line *self)
{
    free(self->buf);
}

int main(void)
{
    Line current;
    Line_init(&current);
    for (int ch;;) {
        ch = getchar();
        if (ch == EOF || ch == '\n') {
            if (current.len > 80u) {
                printf("%s\n", current.buf);
            }
            Line_clear(&current);
        } else {
            Line_add(&current, ch);
        }
        if (ch == EOF) break;
    }
    Line_destroy(&current);
    return 0;
}