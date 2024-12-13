#include <stdio.h>
int canchange(int n)
{
    int a, min;
    if (n == 0)
        return 0;
    if ((n == 3) || (n == 8) || (n == 10))
        return 1;
    if (n < 3)
        return -1;
    min = 1000000;
    a = canchange(n - 10);
    if ((a > 0) && (a < min))
    {
        min = a;
    }

    a = canchange(n - 8);
    if ((a > 0) && (a < min))
    {
        min = a;
    }
    a = canchange(n - 3);
    if ((a > 0) && (a < min))
    {
        min = a;
    }
    if (min != 1000000)
        return min + 1;
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", canchange(n));
}