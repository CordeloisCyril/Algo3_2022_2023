#include <stdio.h>
#include<stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Question 1 :
#define MAX 10
typedef char Tab[MAX];
typedef struct Client
{
    int id;
    char nom[15];
}Client;

//Question 2 & 6 :
void ajouterClientFichier(FILE *f, Client c)
{
    f=fopen("test.txt","r+");
    fseek(f, 0, SEEK_SET);
    int id = 0 ;
    char nom[12];
    bool trouver  = false;
    printf("entrez l'id\n");
    scanf("%d", &c.id);
    
    printf("entrez le nom\n");
    scanf("%s", &c.nom);
    do
    {
        fscanf(f,"%d %s", &id, &nom);
        printf("%s", c.nom);
        printf("%s", nom);
        if(c.nom == nom)
        {
            printf("le client existe déjà ! ");
            trouver = true;
        }
    }while (!feof(f));
    if(trouver == false)
    {
        fseek(f,0, SEEK_END);
        fprintf(f,"\n");
        fprintf(f, "%d ", c.id);
        fprintf(f, "%s ", c.nom);
    }
}

//Question 3 :
void afficherClientFichier(FILE *f, Client c)
{
    f=fopen("test.txt","a+");
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[12];
    do
    {
        fscanf(f,"%d %s", &id, &nom);
        printf("l'id est : %d et le nom est %s \n", id, nom);
    } while (!feof(f));
}

//Question 4 :
int nombreClientsFichier(FILE *f)
{
    f=fopen("test.txt","r+");
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[12];
    int compte=0;
    while (!feof(f))
    {
        fscanf(f,"%d %s", &id, &nom);
        compte +=1;
    }
    return compte;
}

//Question 5 :
bool appartientClientFichier(FILE *f, char _nom[15])
{
    f=fopen("test.txt","r+"); 
    fseek(f, 0, SEEK_SET);
    int id =0;
    char nom[15];
    while (!feof(f))
    {
        fscanf(f,"%d %s", &id, &nom);
        if (_nom == nom)
        {
            printf("le client %s a l'id %d", nom, id);
            return true;
        }
        else 
        return false;
    }
}
int main(int argc, char const *argv[])
{
    FILE *f=NULL;
    f=fopen("test.txt","r+");
    Client c;
    int num=0;
    char _nom[15];
    afficherClientFichier(f,c);
    num = nombreClientsFichier(f);
    printf("il y a : %d", num);
    appartientClientFichier(f, _nom);
    return 0;
}