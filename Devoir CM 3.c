#include <stdio.h>
#include <stdlib.h>

int main()
{

    int nombreNotes = 0;
    float notes[10];

    int coeff[10];

    int choix = 1;
    while (choix > 0 && choix < 7)
    {
        printf("=================\n");
        printf("1. Ajouter une note\n");
        printf("2. Afficher les notes et les coefficients\n");
        printf("3. Calculer la moyenne\n");
        printf("4. Afficher la note minimale et la note maximale\n");
        printf("5. Modifier une note\n");
        printf("6. Ajouter 1 point à toutes les notes\n");
        printf("7. Quitter\n");

        printf("\nQue voulez-vous faire ?\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            saisieNotesEtCoefficients(&nombreNotes, notes, coeff);
            break;
        case 2:
            afficherNotesEtCoefficients(&nombreNotes, notes, coeff);
            break;
        case 3:
            calculerMoyenne(&nombreNotes, notes, coeff);
            break;

        case 4:
            afficherMinEtMax(&nombreNotes, notes);
            break;
        case 5:
            modifierNote(&nombreNotes, notes, coeff);
            break;
        case 6:
            ajouterUnPoint(&nombreNotes, notes);
            break;
        case 7:
            printf("Au revoir !\n");
            break;
        default:
            break;
        }
    }

    return 0;
}

void saisieNotesEtCoefficients(int *nombreNotes, float notes[], int coeff[])
{
    printf("Combien de notes voulez-vous ajouter ?\n");
    int nbNotes;
    scanf("%d", &nbNotes);

    int i;
    for (i = 0; i < nbNotes; i++)
    {
        printf("Entrez la note %d : ", i + 1);
        scanf("%f", &notes[*nombreNotes]);
        printf("Entrez le coefficient de la note %d : ", i + 1);
        scanf("%d", &coeff[*nombreNotes]);
        *nombreNotes += 1;
    }
}

void afficherNotesEtCoefficients(int *nombreNotes, float notes[], int coeff[])
{
    int i;
    for (i = 0; i < *nombreNotes; i++)
    {
        printf("Note %d : %f, coefficient : %d\n", i + 1, notes[i], coeff[i]);
    }
}

void calculerMoyenne(int *nombreNotes, float notes[], int coeff[])
{
    float somme = 0;
    int sommeCoeff = 0;
    int i;
    for (i = 0; i < *nombreNotes; i++)
    {
        somme += notes[i] * coeff[i];
        sommeCoeff += coeff[i];
    }
    printf("La moyenne est de %f\n", somme / sommeCoeff);
}

void afficherMinEtMax(int *nombreNotes, float notes[])
{
    float min = notes[0];
    float max = notes[0];
    int i;
    for (i = 0; i < *nombreNotes; i++)
    {
        if (notes[i] < min)
        {
            min = notes[i];
        }
        if (notes[i] > max)
        {
            max = notes[i];
        }
    }
    printf("La note minimale est de %f et la note maximale est de %f\n", min, max);
}

void modifierNote(int *nombreNotes, float notes[], int coeff[])
{
    printf("Quelle note voulez-vous modifier ?\n");
    int numNote;
    scanf("%d", &numNote);
    printf("Entrez la nouvelle note : ");
    scanf("%f", &notes[numNote - 1]);
    printf("Entrez le nouveau coefficient : ");
    scanf("%d", &coeff[numNote - 1]);
}

void ajouterUnPoint(int *nombreNotes, float notes[])
{
    int i;
    for (i = 0; i < *nombreNotes; i++)
    {
        if (notes[i] + 1 <= 20)
        {
            notes[i] += 1;
        }
        else
        {
            notes[i] = 20;
        }
    }
}


//Il suffit d'attribué un tableau de note et un tableau de coefficient différent à chacun des P élève