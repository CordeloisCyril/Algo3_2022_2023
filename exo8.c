int afficherDoublons(Tab t, int nbClients){
    int nbDoublons = 0;
    printf("\n-- Affichage des doublons (non prise en charge des triplons, quadruplons, etc...) --\n");
    for(int i = 0; i<nbClients; i++){
        for(int j = 0; j<nbClients; j++){
            if(i != j && t[j].idClient == t[i].idClient && strcmp(t[j].nomClient, t[i].nomClient) == 0){
                nbDoublons += 1;
                if((nbDoublons+1) % 2 == 0){
                    printf("\nId client : %d Nom client : %s Indice : %d\n", t[i].idClient, t[i].nomClient, i);
                }                    
                else{
                    printf("Id client : %d Nom client : %s Indice : %d\n", t[i].idClient, t[i].nomClient, i);              
                }
            }
        }
    }
    if(nbDoublons == 0){
        printf("\nPas de doublons dans le tableau !\n");
    }
    return nbDoublons/2;
}
