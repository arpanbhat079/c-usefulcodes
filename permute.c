#include <stdio.h>
#include <string.h>
int count = 0;
void swap(int i, int j, char s[])
{
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return;
}
void permute(char s[], int l, int r)
{
    if (l == r)
    {
        printf("%s", s);
        count++;
        printf("\n");
        return;
    }
    else
    {
        int used[256] = {0};
        for (int i = l; i <= r; i++)
        {
            if (used[(int)s[i]] == 0)
            {
                used[(int)s[i]] = 1;
                swap(l, i, s);
                permute(s, l + 1, r);
                swap(l, i, s);
            }
        }
    }
}
int main()
{
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    permute(s, 0, len - 1);
    printf("No. of permutations are : %d", count);
}
