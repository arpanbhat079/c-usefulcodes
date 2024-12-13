#include <stdio.h>
// subsets
void subsets(int n, int arr[], int subset[], int temp, int x)
{
    if (n == 0)
    {
        printf("{");
        for (int i = 0; i < x; i++)
        {
            printf("%d", subset[i]);
            if (i != x - 1)
                printf(", ");
        }
        printf("}");
        printf("\n");
        return;
    }
    // for subsets
    subsets(n - 1, arr, subset, temp + 1, x);
    subset[x] = arr[temp];
    subsets(n - 1, arr, subset, temp + 1, x + 1);
}
// main
int main()
{
    int n;
    scanf("%d", &n);
    int set[n], subset[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    subsets(n, set, subset, 0, 0);

    return 0;
}
