#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../general/les_structures.h"

#ifndef _LIB_LOCATIONS_GESTION_LOCATION_H_
#define _LIB_LOCATIONS_GESTION_LOCATION_H_


//le programme ecrit par: Mohamed Ouaicha
void visualiser_location(char* fichier,int numero_contrat);
void louer_une_voiture(char* clients_db,char* voiture_db,char* contrat_db);
void retourner_une_voiture(int voiture_id,char* voiture_db,int contrat_id,char* contrat_db);
void modifier_une_contrat(int numero_contrat,char* clients_db,char* voiture_db,char* contrat_db);
void supprimer_une_contrat(int numero_contrat,char* contrat_db);
void afficher_contrat(contrat contrat_location);
void ajouter_contrat(char* voiture_db,char* client_db,char* location_db);
bool exister_contrat(char* contrat_db,int numero_contrat);
#endif
