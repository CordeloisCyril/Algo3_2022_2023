int enleverClient(int idClient, Chaine nomClient, Tab t, int *nbClients){
    int temp_i;
    int a = 0;
    while(a==0){
        for(int i=0; i<*nbClients; i++){ 
            if(t[i].idClient == idClient && strcmp(t[i].nomClient, nomClient) == 0){
                temp_i = i;
                a = 1;
            }
        }
        if(a==0){
            printf("\nLe client souhaite n'a pas ete enleve car il n'existe pas.\n");
            return 0;
        }
    }
    for(int i = temp_i; i<*nbClients; i++){
        t[i] = t[i+1];
    }
    *nbClients -= 1;
    return 1;
}
int main(int argc, char *argv[])
{
    Tab t;

    Client c;
    c.idClient = 3;
    strcpy(c.nomClient, "c");
    int *nbClients;
    int nbclient = 0;
    nbClients = &nbclient;
    int *indiceClient;
    int indiceclient = 0;
    indiceClient = &indiceclient;
    int *indiceIdMin;
    int indiceidmin = 0;
    indiceIdMin = &indiceidmin;
    int *indiceIdMax;
    int indiceidmax = 0;
    indiceIdMax = &indiceidmax;
    int nbDoublons;

    saisieClients(t, 5, nbClients);
    afficher(t, nbclient);
    enleverClient(2, "b", t, nbClients);
    modifierNom(t, nbclient, 2);
    afficher(t, nbclient);
    rechercheClient(3, t, nbclient, indiceClient);
    rechercherIdMinMax(t, nbclient, indiceIdMin, indiceIdMax);
    ajouterSansDoublon(c, t, nbClients);
    nbDoublons = afficherDoublons(t, nbclient);
    printf("\nNombre de doublons : %d\n", nbDoublons);
    afficher(t, nbclient);
    enleverClient(2, "b", t, nbClients);
    printf("\n----------- Apres modification -----------\n");
    afficher(t, nbclient);

    nbDoublons = afficherDoublons(t, nbclient);
    printf("\nNombre de client dans le tableau : %d\n", nbclient);
    printf("Nombre de doublons : %d\n", nbDoublons);
    printf("\n//END\n");
    return 0;
}