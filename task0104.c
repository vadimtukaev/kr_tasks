#include <stdio.h>

int main(void)
{
    printf("Celsius\tFahrengeit\n");
    for (int cels = 0; cels <= 300; cels += 20)
        printf("%7d\t%10.1f\n", cels, 9.0 / 5.0 * cels + 32.0);
}