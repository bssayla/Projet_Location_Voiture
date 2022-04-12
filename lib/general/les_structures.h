#ifndef _LIB_LES_STUCTURES_H_
#define _LIB_LES_STUCTURES_H_

//le programme ecrit par: Mohamed Ouaicha
typedef struct date{
    int jour;
    int mois;
    int annee;
}date;



typedef struct voiture{
    int idVoiture;
    char marque[15];
    char nomVoiture[15];
    char couleur[7];
    int nbplaces;
    int prixJour;
    char EnLocation[4];
}voiture;


typedef struct contrat{
    int numContrat;
    int idVoiture;
    int idClient;
    date debut;
    date fin;
    int cout;
}contrat;


typedef struct client{
    int idClient;
    char nom[20];
    char prenom[20];
    int cin;
    char adresse[30];
    int telephone;
}client;


#endif