/*
@author
Name: Muhammad Yameen
email: yameenmuhammad960@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

// First method recursive:

int F1(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return F1(n - 3) + F1(n - 2);
}

// second method memomrization

int F2(int n)
{
    int *mem_array = (int *)malloc((n + 1) * sizeof(int));
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0 || n == 1 || n == 2)
    {
        mem_array[n] = n;
    }

    for (int i = 3; i <= n; i++)
    {
        mem_array[i] = -1;
    }

    if (mem_array[n] == -1)
    {
        mem_array[n] = F2(n - 3) + F2(n - 2);
        return mem_array[n];
    }
    int res = mem_array[n];
    free(mem_array);
    return res;
}

// Third Iteative method:
int F3(int n)
{
    if (n < 0)
    {
        return -1; // error
    }
    else if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    else
    {
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 2;
        int current;
        for (int i = 3; i <= n; i++)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = current;
        }
        return current;
    }
}

int main()
{
    printf("F1: %d\n", F1(10));
    printf("F2: %d\n", F2(10));
    printf("F3: %d\n", F3(10));

    return 0;
}

/*
Note:
The advantages and disadvantages of these methods are written in the Readme file
*/
