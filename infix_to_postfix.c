#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char symbols[100];
    int top;
} stack;

stack temp;

void initstack(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

void push(stack *s, char ch)
{
    s->symbols[++s->top] = ch;
}

char pop(stack *s)
{
    if (!isEmpty(s))
    {
        return s->symbols[s->top--];
    }
    return '\0'; // Return null character if stack is empty
}

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void final_postfix(stack *s, char final[])
{
    int i, j = 0;
    for (i = 0; s->symbols[i]; i++)
    {
        if (isDigit(s->symbols[i]))
        {
            final[j++] = s->symbols[i];
        }
        else if (s->symbols[i] == '(')
        {
            push(&temp, s->symbols[i]);
        }
        else if (s->symbols[i] == ')')
        {
            while (!isEmpty(&temp))
            {
                char topChar = pop(&temp);
                if (topChar == '(')
                    break;
                final[j++] = topChar;
            }
        }
        else
        { // the character is an operator
            while (!isEmpty(&temp) && precedence(temp.symbols[temp.top]) >= precedence(s->symbols[i]))
            {
                final[j++] = pop(&temp);
            }
            push(&temp, s->symbols[i]);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&temp))
    {
        final[j++] = pop(&temp);
    }

    final[j] = '\0'; // Null-terminate the final string
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL)
    {
        printf("Memory not allocated");
        return 1;
    }
    initstack(s);

    char ch;
    while (1)
    {
        ch = getchar();
        if (ch == '$')
            break; // Use '$' to signal end of input
        push(s, ch);
    }

    char final[100];
    final_postfix(s, final);
    printf("%s\n", final);

    free(s); // Free the allocated memory
    return 0;
}
