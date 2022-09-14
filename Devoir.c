#include <stdio.h>

int multiplication(int nombre1,int nombre2)
{
    int resultat;
    resultat = (nombre1*nombre2);
    return(resultat);

}

int main()
{
    int facteur = 3;
    printf("%d",(multiplication(21,24)*3));
    printf("\n");
    printf("%d",(multiplication(24,27)*3));
    return 0;
}