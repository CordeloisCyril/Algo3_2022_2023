int rechercheClient(int idClient, Tab t, int nbClients, int *indiceClient){
    for(int i = 0; i<nbClients; i++){
        if(t[i].idClient == idClient){
            *indiceClient = i;
            printf("\nL'indice du client qui a pour id %d est : %d", idClient, *indiceClient);
            return 1;
        }
    }
    return 0;
}