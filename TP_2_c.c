#include <stdio.h>
#define N 10

typedef int Tab[N];

// Fonction de somme du code de base
int somme(Tab t, int n, int i)
{
    int res_0;
    // printf("Calcul de la somme a partir de l'indice %d :\n", i);
    if (i < n)
    {
        // printf("\t appel du calcul de la somme a partir de l'indice %d:\n", i + 1);
        res_0 = t[i] + somme(t, n, i + 1);
        // printf("t addition avec t[%d]\n", i);
    }
    // printf("\t Somme a partir de l'indice %d=%d\n\n", i, res_0);
    return res_0;
}

// Question 1
void affiche(Tab t, int n, int i)
{
    if (i < n)
    {
        printf("%d ", t[i]);
        affiche(t, n, i + 1);
    }
    else
        printf("\n");
}

// Question 2
int somme2(Tab t, int n)
{
    if (n > 0)
    {
        // printf("Calcul de la somme a partir de l'indice %d, ajout de %d\n", n - 1, t[n - 1]);
        return t[n - 1] + somme2(t, n - 1);
    }

    else
        return 0;
}

// Question 3
int sup(Tab t, int v, int nb)
{
    // printf("nb = %d, value = %d, t[%d] = %d\n", nb, value, nb - 1, t[nb - 1]);
    if (nb > 0)
        if (t[nb - 1] > v)
            return 1 + sup(t, v, nb - 1);
        else
            return sup(t, v, nb - 1);
    else
        return 0;
}

// Question 4
void affiche_inverse(Tab t, int nb)
{
    if (nb > 0)
    {
        printf("%d ", t[nb - 1]);
        affiche_inverse(t, nb - 1);
    }
    else
    {
        printf("\n");
    }
}

// Question 5
int recherche(Tab t, int v, int nb)
{
    if (nb > 0)
    {
        if (t[nb - 1] == v)
            return nb - 1;
        else
            return recherche(t, v, nb - 1);
    }
    else
        return -1;
}

/* Question 6 - Partie 1 */
int *triTab(Tab t, int nb)
{
    int i, j, tmp;
    for (i = 0; i < nb; i++)
    {
        for (j = i + 1; j < nb; j++)
        {
            if (t[i] > t[j])
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
    return t;
}

/* Question 6 - Partie 2 */
int recherche_dicho(Tab t, int v, int nb)
{
    int mid = nb / 2;
    if (nb > 0)
    {
        if (t[mid] == v)
            return mid;
        else if (t[mid] > v)
            return recherche_dicho(t, v, mid);
        else
            return recherche_dicho(t, v, nb - mid);
    }
    else
        return -1;
}

int main()
{
    Tab t1 = {4, 2, 8, 0, 7, 3, 1, 5, 9, 6};
    Tab t2 = {4, 2, 8, 0, 7, 3, 1, 5, 9, 6};

    printf("La somme des entiers du tableau t1 (somme)= %d\n", somme(t1, N, 0));
    printf("1) Affichage du tableau t1\n");
    affiche(t1, N, 0);
    printf("2) La somme des entiers du tableau t1 (somme2)= %d\n", somme2(t1, N));

    int value;
    printf("3) Entrez une valeur dont vous allez rechercher les élements supérieur dans le tableau: ");
    scanf("%d", &value);
    printf("3) Nombre d'élements supérieur à %d = %d\n", value, sup(t1, value, N));
    printf("4) Affichage du tableau t1 à l'envers\n");
    affiche_inverse(t1, N);
    int elementARechercher;
    printf("5) Entrez un élément à rechercher dans le tableau: ");
    scanf("%d", &elementARechercher);
    printf("5) L'élément %d se trouve dans le tableau à l'indice : %d\n", elementARechercher, recherche(t1, elementARechercher, N));

    printf("6) Entrez un élément à rechercher par dichotomie dans le tableau trié: ");
    int elementARechercherDichotomie;
    scanf("%d", &elementARechercherDichotomie);
    triTab(t2, N);
    printf("6) Le tableau  triée est : ");
    affiche(t2, N, 0);
    printf("6) L'élément %d se trouve dans le tableau trié à l'indice : %d\n", elementARechercherDichotomie, recherche_dicho(t2, elementARechercherDichotomie, N));

    return 0;
}