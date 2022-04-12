#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"../general/les_structures.h"

//le programme ecrit par: Mohamed Ouaicha
#ifndef _LIB_CLIENS_GESTION_CLIENS_H_
#define _LIB_CLIENS_GESTION_CLIENS_H_
bool client_deja_existe(char* fichier,int id);
void ajouter_client(char* fichier);
void afficher_tous_les_clients(char* fichier);
void modifier_client(char* fichier,int id);
void supprimer_client(char* fichier,int id);
#endif