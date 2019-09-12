#include <stdio.h>

double cels(double fahr)
{
    return 5.0 / 9.0 * (fahr - 32.0);
}

int main(void)
{
    printf("Celsius\tFahrengeit\n");
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        printf("%7d\t%10.1f\n", fahr, cels(fahr));
    }
    return 0;
}