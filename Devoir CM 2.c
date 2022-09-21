#include <stdio.h>
#include <stdlib.h>

// main function that prints hello world

void question1()
{
    int n;
    printf("Enter an integer: ");

    // read integer and store it in n
    scanf("%d", &n);
    // print n and it's adress
    printf("\nValeur = %d, Adresse = %p\n", n, &n);
}

void question2()
{
    char c;
    printf("Enter a character: ");

    // read character and store it in c
    scanf(" %c", &c);
    // print c and it's adress
    printf("Valeur = %c, Adresse = %p", c, &c);
}

void question3()
{
    int a, b;
    printf("\nEnter two integers: \n");
    scanf("%d %d", &a, &b);
    // print a and b and their adresses
    printf("Valeur A = %d, Adresse A = %p \n", a, &a);
    printf("Valeur B = %d, Adresse B = %p\n", b, &b);
    swapIntegers(&a, &b);
    printf("Valeur A = %d, Adresse A = %p \n", a, &a);
    printf("Valeur B = %d, Adresse B = %p\n", b, &b);
}

// function that will commute a integer and b integer
void swapIntegers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function min
int getMinimum(int a, int b, int c)
{
    int min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}

// function max
int getMaximum(int a, int b, int c)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

// function that will return the lowest and highest values
void question4()
{
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Valeur A = %d, Adresse A = %p \n", a, &a);
    printf("Valeur B = %d, Adresse B = %p \n", b, &b);
    printf("Valeur C = %d, Adresse C = %p \n", c, &c);
    int min = getMinimum(a, b, c);
    int max = getMaximum(a, b, c);
    printf("Min = %d, Max = %d", min, max);
}

int main()
{
    question1();
    question2();
    question3();
    question4();
    return 0;
}