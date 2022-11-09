int saisieClients(Tab t, int p, int *nbClients){
    if(*nbClients == N){
        return 0;
    }
    else{
        for(int i=0; i<p; i++){
            Client c = t[*nbClients + i];
            saisie(&c);
            ajouter(c, t, nbClients);
        }
        return 1;
    }
}