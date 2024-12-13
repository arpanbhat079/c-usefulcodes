#include <stdio.h>
// for showing no combinations exist in case count =0
int count = 0;
void func(int k, int arr[], int temp, int sum, int n)
{
    // printing the sum
    if (sum == 100 && k == 10)
    {
        count++;
        for (int i = 0; i < temp; i++)
        {
            if (i == 0)
            {
                printf("%d ", arr[i]);
            }
            else
            {
                if (arr[i] > 0)
                    printf("+ %d ", arr[i]);
                if (arr[i] < 0)
                    printf("- %d ", -arr[i]);
            }
        }
        printf("= 100");
        printf("\n");
    }
    if (k == 10)
        return;
    // recursive call
    // for grouping and replace minus
    arr[temp] = k;
    func(k + 1, arr, temp + 1, sum + arr[temp], n);
    if (k != 9)
    {
        arr[temp] = 11 * k + 1;
        func(k + 2, arr, temp + 1, sum + arr[temp], n);
    }
    // for replace minus case
    if (n == 2)
    {
        arr[temp] = -k;
        func(k + 1, arr, temp + 1, sum + arr[temp], n);
        if (k != 9)
        {
            arr[temp] = -11 * k - 1;
            func(k + 2, arr, temp + 1, sum + arr[temp], n);
        }
    }
}
// main function
int main()
{
    int n, arr[10];
    // infinite loop for putting choices
    while (n != 3)
    {
        printf("Options :\n1)GROUP\n2)REPLACEMINUS\n3)QUIT\n");
        printf("Choose option: ");
        scanf("%d", &n);
        if (n == 1 || n == 2)
        {
            func(1, arr, 0, 0, n);
            if (count == 0 && n != 3)
                printf("No such combination of grouping exits which sum to 100\n");
            // in case of no combination
            // resetting count again
            count = 0;
        }
    }
    // for quitting
    if (n == 3)
    {
        printf("Quitting...");
    }
    return 0;
}