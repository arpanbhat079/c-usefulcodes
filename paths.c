#include <stdio.h>
// for counting parts
int count;
// to show paths
void paths(int arrx[], int arry[], int temp, int x1, int x2)
{
    // stopping condition
    if (arrx[temp - 1] > x1 || arry[temp - 1] > x2)
        return;
    // printing array
    if (arrx[temp - 1] == x1 && arry[temp - 1] == x2)
    {
        for (int i = 0; i < temp; i++)
        {
            if (i == temp - 1)
                printf("(%d,%d)\n", arrx[i], arry[i]);
            else
                printf("(%d,%d)-> ", arrx[i], arry[i]);
        }
        count++;
    }
    // recursive part of function
    arrx[temp] = arrx[temp - 1] + 1;
    arry[temp] = arry[temp - 1];
    paths(arrx, arry, temp + 1, x1, x2);
    arry[temp] = arry[temp - 1] + 1;
    arrx[temp] = arrx[temp - 1];
    paths(arrx, arry, temp + 1, x1, x2);
}
// main function
int main()
{
    int arrx[100], arry[100], xend, yend;
    printf("Enter starting coordinates: ");
    scanf("%d %d", &arrx[0], &arry[0]);
    printf("Enter Final coordinates: ");
    scanf("%d %d", &xend, &yend);
    printf("paths are :\n");
    // calling function
    paths(arrx, arry, 1, xend, yend);
    printf("Number of paths are %d", count);
    return 0;
}