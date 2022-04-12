#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../general/les_structures.h"

#ifndef _LIB_VOITURES_FONCTIONS_H_
#define _LIB_VOITURES_FONCTIONS_H_

//le programme ecrit par: Mohamed Ouaicha
bool est_exist(char *voiture_db,int idVoiture);
bool est_disponible(char* fichier,int idVoiture);
void ajouter_voiture(char* fichier);
void afficher_voiture(voiture v);
void afficher_toutes_les_voitures(char* fichier);
void modifier_voiture(char* fichier,int idVoiture);
void supprimer_voiture(char* fichier,int idVoiture);
void switch_la_location(char* fichier,int idVoiture);

#endif