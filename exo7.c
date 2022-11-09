void rechercherIdMinMax(Tab t, int nbClients, int *indiceIdMin, int *indiceIdMax){
    int tempIdMin = t[0].idClient;
    int tempIdMax = t[0].idClient;
    for(int i = 1; i<nbClients; i++){
        if(t[i].idClient < tempIdMin){
            tempIdMin = t[i].idClient;
            *indiceIdMin = i;
        }
        if(t[i].idClient > tempIdMax){
            tempIdMax = t[i].idClient;
            *indiceIdMax = i;
        }  
    }
    printf("\nL'indice dans le tableau du client ayant l'id Client minimum : %d\n", *indiceIdMin);
    printf("L'indice dans le tableau du client ayant l'id Client maximum : %d\n", *indiceIdMax);
}