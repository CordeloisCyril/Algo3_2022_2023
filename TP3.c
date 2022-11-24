#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
typedef int Tab[N];


void remplirTableau(Tab t, int n)
{ 
    int i ;
    srand ( time(NULL) ); 
    for (i=0; i<n; i++)
    t[ i]= rand() % n; 
}

void affiche (int *t, int n , int i ) 
{
	if (i == n) return;
	printf("| %d", t[0]) ;
        affiche (t + 1 , n, i+1) ;
}

void copier(Tab t, Tab t2, int n)
{
    for(int i=0; i<n; i++)
    {
        t2[i]=t[i];
    }
    printf("\n");
}

int triParMin(Tab t, int n)
{
    int min,temp;
    for(int i = 0 ; i < n-1 ; i++)
    {
       min = i;
       for(int j = i+1 ; j < n ; j++)
           if(t[j] < t[min])
               min = j;
       if(min!=i)
       {
          temp = t[i];
          t[i]=t[min];
          t[min]=temp;
       }
    }
}

int permute(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

int initPivot(Tab t, int  g, int d){
	return t[g];
}

int partitionN(int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;  
            permute(&arr[i], &arr[j]);
        }
    }
    permute(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
int partitionner(Tab t, int g, int d){
	int pivot = initPivot(t, g,d);
	int i = g - 1;
	int j = d + 1;
	
	int fin = 0;
	
	while (!fin){
		printf("\nIn the while Pivot %d , i %d , j %d \n", pivot, i, j);
		
		do{	
			j = j -1;
		}while(t[j] < pivot);
		
		do{
		 i = i +1;
		}while(t[i] >= pivot);
		
		if (i < j){
			printf("\n Permute ");
			permute(&t[i], &t[j]);
		}else{
			fin = 1;
		}
	}
	return i;
}

int quicksort(Tab t, int g, int d){
	if (g < d)
    {
		int p = partitionN(t, g, d);
		quicksort(t, g, p-1);
		quicksort(t, p + 1, d);
		
	}
}

void f ()
{
    Tab t1;
    Tab t2;
    remplirTableau(t1, N);
    copier(t1,t2,N);
    triParMin(t1,N);
    affiche(t1,N,0);
    quicksort(t2,0,N-1);
    affiche(t2,N,0);
}

int main(int argc, char const *argv[])
{
    float somme;
    float temps[10];
    float moyenne;
    for(int i=0; i < 10; i++)
    {
        double temps_debut, temps_fin;
        temps_debut=(double)clock(); 
        f (); 
        temps_fin = (double)clock();
        printf ("\nDuree de traitement : %f ms\n", 1000*(temps_fin - temps_debut)/CLOCKS_PER_SEC);
        temps[i] = (temps_fin -temps_debut);
    }
    for( int j = 0;j<10;j++)
    {
        somme = somme + temps[j];
        moyenne = somme /10;
    }
    printf("la moyenne est de : %d", moyenne);
    return 0;

}