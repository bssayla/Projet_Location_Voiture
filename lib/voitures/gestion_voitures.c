//les biblio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_voitures.h"
#include "../general/les_structures.h"

bool est_exist(char *fichier,int idVoiture){
    //le programme ecrit par: Mohamed Ouaicha
    int id,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];
    FILE* voiture_db = fopen(fichier,"r");
    do{
        fscanf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",&id,marque,nomVoitures,col,&nb_places,&prix_par_jour,en_location);
        if(idVoiture==id){
            fclose(voiture_db);
            return true;
        }
    }while(!feof(voiture_db));
    fclose(voiture_db);
    return false;
}
bool est_disponible(char* fichier,int idVoiture){
    //le programme ecrit par: Mohamed Ouaicha
    int id,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];
    FILE* voiture_db = fopen(fichier,"r+");
    if(voiture_db==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return false;
    }
    do{
        fscanf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",&id,marque,nomVoitures,col,&nb_places,&prix_par_jour,en_location);
        if(idVoiture == id && (strcmp(en_location,"non") == 0)){
            fclose(voiture_db);
            return true;
        }
    }while(!feof(voiture_db));
    fclose(voiture_db);
    return false;
}
void ajouter_voiture(char* fichier){
    //le programme ecrit par: Mohamed Ouaicha
    FILE* voiture_db = fopen(fichier,"a+");
    int id,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];

    printf("\n-------------------------------------------------------\n");
    printf("|       Saisir les informations du voiture            |\n");
    printf("-------------------------------------------------------\n");

    printf("ID de la voiture: ");
    scanf("%d",&id);
    
    printf("La marque: ");
    scanf("%s",marque);

    printf("Nom de voiture: ");
    scanf("%s",nomVoitures);

    printf("Nombre des places: ");
    scanf("%d",&nb_places);

    printf("Couleur: ");
    scanf("%s",col);

    printf("En location: ");
    scanf("%s",en_location);

    printf("Le prix par jour: ");
    scanf("%d",&prix_par_jour);
    
    
    if(est_exist(fichier,id)){
        printf("\n-------------------------------------------------------\n");
        printf("|                  Ce ID deja exist                   |\n");
        printf("-------------------------------------------------------\n");
        ajouter_voiture(fichier);
        fclose(voiture_db);
        return;
    }else{
        fprintf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",id,marque,nomVoitures,col,nb_places,prix_par_jour,en_location);        
        printf("\n-------------------------------------------------------\n");
    }
    fclose(voiture_db);
    return;

}
void afficher_voiture(voiture v){

    printf("\n-----------------------INFO-------------------------\n");
    printf("\tID Voiture: %d\n",v.idVoiture);
    printf("\tMarque: %s\n",v.marque);
    printf("\tNom Voiture: %s\n",v.nomVoiture);
    printf("\tCouleur: %s\n",v.couleur);
    printf("\tNombre de places: %d\n",v.nbplaces);
    printf("\tPrix par jour: %d\n",v.prixJour);
    printf("\tEn location: %s\n",v.EnLocation);
    return;
}
void afficher_toutes_les_voitures(char* fichier){
    //le programme ecrit par: Mohamed Ouaicha
    voiture v;
    FILE* voiture_db = fopen(fichier,"r");
    do{
        fscanf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",&v.idVoiture,v.marque,v.nomVoiture,v.couleur,&v.nbplaces,&v.prixJour,v.EnLocation);
        afficher_voiture(v);
    }while(!feof(voiture_db));
    fclose(voiture_db);
    return;
}

void supprimer_voiture(char* fichier,int id_voiture ){
    //le programme ecrit par: Mohamed Ouaicha
    FILE* voiture_db = fopen(fichier,"r");
    FILE* voiture_db_tmp = fopen("voiture_db_tmp.txt","w");
    int id,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];
    do{
        fscanf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",&id,marque,nomVoitures,col,&nb_places,&prix_par_jour,en_location);
        if(id_voiture!=id){
            fprintf(voiture_db_tmp,"%d - %s - %s - %s - %d - %d - %s\n",id,marque,nomVoitures,col,nb_places,prix_par_jour,en_location);
        }
    }while(!feof(voiture_db));
    fclose(voiture_db);
    fclose(voiture_db_tmp);
    remove(fichier);
    rename("voiture_db_tmp.txt",fichier);
    return;
}
void modifier_voiture(char* fichier,int idVoiture){
    //le programme ecrit par: Mohamed Ouaicha
    int id=idVoiture,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];

    //suprimer les info anciens
    supprimer_voiture(fichier,idVoiture);
    //les nouveau info
    printf("\n-------------------------------------------------------\n");
    printf("|    Saisir les nouveau informations du voiture\n    |\n");
    printf("-------------------------------------------------------\n");
    
    printf("La marque: ");
    scanf("%s",marque);

    printf("Nom de voiture: ");
    scanf("%s",nomVoitures);

    printf("Nombre des places: ");
    scanf("%d",&nb_places);

    printf("Couleur: ");
    scanf("%s",col);

    printf("En location: ");
    scanf("%s",en_location);

    printf("Le prix par jour: ");
    scanf("%d",&prix_par_jour);

    FILE* voiture_db = fopen(fichier,"a+");
    if(voiture_db == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    fprintf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",id,marque,nomVoitures,col,nb_places,prix_par_jour,en_location);
    fclose(voiture_db);
    return;
}
void switch_la_location(char* fichier,int idVoiture){
    //le programme ecrit par: Mohamed Ouaicha
    FILE* voiture_db=fopen(fichier,"a+");
    int id,nb_places,prix_par_jour;
    char marque[15],nomVoitures[15],en_location[4],col[7];
    do{
        fscanf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",&id,marque,nomVoitures,col,&nb_places,&prix_par_jour,en_location);
        if(idVoiture==id){
            if(strcmp(en_location,"oui")==0){
                strcpy(en_location,"non");
                supprimer_voiture(fichier,idVoiture);
                //ouvrir une auter fois car dans la fonction supprimer_voiture on suprimer le fichier
                //et il afut le ouvrir une autre fois
                voiture_db=fopen(fichier,"a");
                fprintf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",id,marque,nomVoitures,col,nb_places,prix_par_jour,en_location);
                fclose(voiture_db);
                return;
            }else{
                strcpy(en_location,"oui");
                supprimer_voiture(fichier,idVoiture);
                FILE* voiture_db=fopen(fichier,"a");
                fprintf(voiture_db,"%d - %s - %s - %s - %d - %d - %s\n",id,marque,nomVoitures,col,nb_places,prix_par_jour,en_location);
                fclose(voiture_db);
                return;
            }
        }
    }while(!feof(voiture_db));
    printf("\n-------------------------------------------------------\n");
    printf("|              La voiture n'existe pas                |\n");
    printf("-------------------------------------------------------\n");
    fclose(voiture_db);
    return;
}