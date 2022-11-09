int ajouterSansDoublon(Client c, Tab t, int *nbClients){
    for(int i=0; i<*nbClients; i++){
        if(t[i].idClient == c.idClient && strcmp(t[i].nomClient, c.nomClient) == 0){
                printf("\nLe client voulant etre ajoute existe deja.\n");
                return 0;
        }   
    }
    ajouter(c, t, nbClients);
    printf("\nClient qui a pour id : %d et nom : %s a ete ajoute en position : %d\n", c.idClient, c.nomClient, *nbClients-1);
    return 1; 
}