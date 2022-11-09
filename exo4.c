void modifierNom(Tab t, int nbClients, int i){
    Chaine nouveauNom;
    if(i <= nbClients){
        printf("\nEntrer le nouveau nom du client d'indice %d : ", i);
        scanf("%s", nouveauNom);
        strcpy(t[i].nomClient, nouveauNom);
    }
}