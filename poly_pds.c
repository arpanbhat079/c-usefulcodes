#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// defining my term(polynomial)
typedef struct
{
    int degree;
    int coeff;
} term;
// function to print
void print_poly(term *poly, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            printf("%d ", poly[i].coeff);
        else if (poly[i].coeff != 0)
        {
            if (poly[i].coeff > 0)
                printf("+%dx^%d ", poly[i].coeff, i);
            else
                printf("-%dx^%d ", -poly[i].coeff, i);
        }
    }
    printf("\n");
}
// multiplying 2 polynomials
void multiply_poly(term *poly1, term *poly2, int n1, int n2)
{
    term *p3 = (term *)malloc((n1 + n2 - 1) * sizeof(term));
    for (int i = 0; i < n1 + n2 - 1; i++)
    {
        p3[i].degree = i;
        p3[i].coeff = 0;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            p3[i + j].coeff = poly1[i].coeff * poly2[j].coeff;
        }
    }
    print_poly(p3, n1 + n2 - 1);
    free(p3);
}
// subtracting two polynomials
void sub_poly(term *poly1, term *poly2, int n1, int n2)
{
    int n = (n1 > n2) ? n1 : n2, m = (n1 < n2) ? n1 : n2;
    term *p3 = (term *)malloc(n * sizeof(term));
    for (int i = 0; i < m; i++)
    {
        p3[i].coeff = poly1[i].coeff - poly2[i].coeff;
    }
    for (int i = m; i < n; i++)
    {
        if (n1 > n2)
        {
            p3[i].coeff = poly1[i].coeff;
        }
        else
        {
            p3[i].coeff = poly2[i].coeff;
        }
    }
    print_poly(p3, n);
    free(p3);
}
// adding two polynomials
void add_poly(term *poly1, term *poly2, int n1, int n2)
{
    int n = (n1 > n2) ? n1 : n2, m = (n1 < n2) ? n1 : n2;
    term *p3 = (term *)malloc(n * sizeof(term));
    for (int i = 0; i < m; i++)
    {
        p3[i].coeff = poly1[i].coeff + poly2[i].coeff;
    }
    for (int i = m; i < n; i++)
    {
        if (n1 > n2)
        {
            p3[i].coeff = poly1[i].coeff;
        }
        else
        {
            p3[i].coeff = poly2[i].coeff;
        }
    }
    print_poly(p3, n);
    free(p3);
}
// main function
int main()
{
    term *poly1, *poly2;
    printf("Enter degree of polynomial 1: ");
    int n1;
    scanf("%d", &n1);
    poly1 = (term *)malloc((n1 + 1) * sizeof(term));
    for (int i = 0; i < n1 + 1; i++)
    {
        poly1[i].degree = i;
        poly1[i].coeff = 0;
    }
    printf("Enter degree of polynomial 2: ");
    int n2;
    scanf("%d", &n2);
    poly2 = (term *)malloc((n2 + 1) * sizeof(term));
    for (int i = 0; i < n2 + 1; i++)
    {
        poly2[i].degree = i;
        poly2[i].coeff = 0;
    }
    int k, x;
    printf("For polynomial 1(Enter degree 9999 to stop):\n");
    while (x != 9999)
    {
        printf("Enter degree of term you want to enter: ");
        scanf("%d", &x);
        if (x == 9999)
            break;
        printf("Enter coefficient: ");
        scanf("%d", &k);
        poly1[x].coeff = k;
    }
    x = 0;
    printf("For polynomial 2(Enter degree 9999 to stop):\n");
    while (x != 9999)
    {
        printf("Enter degree of term you want to enter: ");
        scanf("%d", &x);
        if (x == 9999)
            break;
        printf("Enter coefficient: ");
        scanf("%d", &k);
        poly2[x].coeff = k;
    }
    printf("Polynomial 1:\n");
    print_poly(poly1, n1 + 1);
    printf("Polynomial 2:\n");
    print_poly(poly2, n2 + 1);
    printf("On adding we get:\n");
    add_poly(poly1, poly2, n1 + 1, n2 + 1);
    printf("On subracting we get:\n");
    sub_poly(poly1, poly2, n1 + 1, n2 + 1);
    printf("On mulitplying we get:\n");
    multiply_poly(poly1, poly2, n1 + 1, n2 + 1);
    free(poly1);
    free(poly2);
    return 0;
}