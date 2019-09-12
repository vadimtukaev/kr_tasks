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

Line *Line_reverse(Line *self)
{
    if (self->len > 1u) {
        for (size_t i = 0, j = self->len - 1u; i < j; ++i, --j) {
            char tmp = self->buf[i];
            self->buf[i] = self->buf[j];
            self->buf[j] = tmp;
        }
    }
    return self;
}

int main(void)
{
    Line current;
    Line_init(&current);
    for (int ch;;) {
        ch = getchar();
        if (ch == EOF || ch == '\n') {
            printf("%s\n", Line_reverse(&current)->buf);
            Line_clear(&current);
        } else {
            Line_add(&current, ch);
        }
        if (ch == EOF) break;
    }
    Line_destroy(&current);
    return 0;
}