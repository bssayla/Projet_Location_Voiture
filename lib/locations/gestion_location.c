#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"gestion_location.h"
#include"../general/les_structures.h"
#include"../voitures/gestion_voitures.h"
#include"../cliens/gestion_cliens.h"

bool exister_contrat(char* contrat_db,int contrat_id){
    //le programme ecrit par: Mohamed Ouaicha

    int id_voiture,id_client,cout,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee,id_contrat;
    FILE* fichier_contrat=fopen(contrat_db,"r");
    //on va chercher le contrat dans le fichier
    do{
        //iteration dans le fichier
        fscanf(fichier_contrat,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",&id_contrat,&id_voiture,&id_client,&cout,&d_jour,&d_mois,&d_annee,&f_jour,&f_mois,&f_annee);
        //on verifie si le contrat existe
        if(id_contrat == contrat_id){
            return true;
        }
    }while(!feof(fichier_contrat));
    //close le fichier
    fclose(fichier_contrat);
    return false;
}

void afficher_contrat(contrat contrat_location){
    //le programme ecrit par: Mohamed Ouaicha

    //fonction pour l'affichage des donnees de contrat
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\nNumero de contrat: %d\n",contrat_location.numContrat);
    printf("Numero de voiture: %d\n",contrat_location.idVoiture);
    printf("Numero de client: %d\n",contrat_location.idClient);
    printf("Date de debut: %d/%d/%d\n",contrat_location.debut.jour,contrat_location.debut.mois,contrat_location.debut.annee);
    printf("Date de fin: %d/%d/%d\n",contrat_location.fin.jour,contrat_location.fin.mois,contrat_location.fin.annee);
    printf("Prix: %d\n",contrat_location.cout);
    printf("\n--------------------------------------------------------------------------------\n");
    return;
}
void visualiser_location(char* fichier,int numero_contrat){
    //le programme ecrit par: Mohamed Ouaicha

    //on cherche le contrat dans le fichier et puis on l'affiche
    int id_voiture,id_client,cout,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee,id_contrat;
    FILE* fichier_location;
    //un element de type contrat pour l'iteration dans le fichier
    contrat contrat_location;

    //ovrir le fichier en lecture seulement
    fichier_location=fopen(fichier,"r");

    //check si le fichier est bien ouvrir
    if(fichier_location==NULL){
        printf("Impossible d'ouvrir le fichier %s\n",fichier);
        return;
    }else{
    
        do{
        //on va scan les atributes de chaque line pour les compare avec le numero on au debut
            fscanf(fichier_location,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",
            &id_contrat,&id_voiture,&id_client,&d_jour,&d_mois,&d_annee,&f_jour,&f_mois,&f_annee,&cout);
        
            if(id_contrat == numero_contrat){
                contrat_location.numContrat=id_contrat;
                contrat_location.idVoiture=id_voiture;
                contrat_location.idClient=id_client;
                contrat_location.debut.jour=d_jour;
                contrat_location.debut.mois=d_mois;
                contrat_location.debut.annee=d_annee;
                contrat_location.fin.jour=f_jour;
                contrat_location.fin.mois=f_mois;
                contrat_location.fin.annee=f_annee;
                contrat_location.cout=cout;
                afficher_contrat(contrat_location);
                return;
            }
        
        }while(!feof(fichier_location));

    }
    printf("\nContrat non trouve\n");
    //fermer le fichier
    fclose(fichier_location);
    return;
}
void ajouter_contrat(char* voiture_db,char* client_db,char* location_db){
    //le programme ecrit par: Mohamed Ouaicha

    FILE* fichier_contrat=fopen(location_db,"a");
    FILE* fichier_voiture=fopen(voiture_db,"a+");
    int id_contrat,id_voiture,id_client,cout,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee;
    //on va stocker la valeur du fonction exist et dispo pour pas les faire deux foix
    bool V1,V2;
    //prend les infos du contrat
    printf("\n-------------------------------------------------------\n");
    printf("Veuillez saisir les nouvelles informations du contrat\n");
    printf("-------------------------------------------------------\n");
    do{
        printf("Numero de contrat: ");
        scanf("%d",&id_contrat);
        V1 = exister_contrat(location_db,id_contrat);
        if(V1){
            printf("\n-------------------------------------------------------\n");
            printf("|           Le contrat existe deja chager l'id        |\n");
            printf("-------------------------------------------------------\n");
        }
    }while(V1);
    do{
        printf("Numero de voiture: ");
        scanf("%d",&id_voiture);
        V1 = est_exist(voiture_db,id_voiture);
        V2 = est_disponible(voiture_db,id_voiture);
        if(!V1){
            printf("\n-------------------------------------------------------\n");
            printf("  |       Il ya pas une voiture avec se id              |");
            printf("\n-------------------------------------------------------\n");
        }
        if(!V2){
            printf("\n-------------------------------------------------------\n");
            printf("  |              Cette voiture est deja louer           |");
            printf("\n-------------------------------------------------------\n");
        }
        // il faut etre existe et dispo pour passer
    }while(!(V1 && V2));
   

    do{
        printf("Numero de client: ");
        scanf("%d",&id_client);
        V1=client_deja_existe(client_db,id_client);
        if(!V1){
            printf("\n-------------------------------------------------------\n");
            printf("|           Le client n'existe pas chager l'id          |\n");
            printf("-------------------------------------------------------\n");
        }
    }while(!V1);

    printf("Date de debut(jj/mm/aaaa): ");
    scanf("%d/%d/%d",&d_jour,&d_mois,&d_annee);

    printf("Date de fin(jj/mm/aaaa): ");
    scanf("%d/%d/%d",&f_jour,&f_mois,&f_annee);

    printf("Prix: ");
    scanf("%d",&cout);
    printf("\n-------------------------------------------------------\n");
    
    //la voiture faut  etre undispo maintenant
    switch_la_location(voiture_db,id_voiture);
    //ajouter les info de contrat
    fprintf(fichier_contrat,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",id_contrat,id_voiture,id_client,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee,cout);
    printf("\nLe contrat a ete ajoute avec succes\n");
    //colse le fichier
    fclose(fichier_contrat);
    return;
}
void retourner_une_voiture(int voiture_id,char* voiture_db,int contrat_id,char* contrat_db){
    //le programme ecrit par: Mohamed Ouaicha

    //la voiture va etre disponible 
    switch_la_location(voiture_db,voiture_id);
    //supprimmr la cotrat de cette voitute
    supprimer_une_contrat(contrat_id,contrat_db);
    return;
}


void supprimer_une_contrat(int contrat_num,char* contrat_db){
    //le programme ecrit par: Mohamed Ouaicha

    int id_contrat,id_voiture,id_client,cout,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee;

    FILE* fichier_contrat=fopen(contrat_db,"r");
    FILE* fichier_contrat_tmp=fopen("contrat_tmp.txt","w");
    //on va chercher le contrat dans le fichier
    do{
        //iteration dans le fichier
        fscanf(fichier_contrat,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",&id_contrat,&id_voiture,&id_client,&d_jour,&d_mois,&d_annee,&f_jour,&f_mois,&f_annee,&cout);
        //on verifie si le contrat existe
        if(id_contrat != contrat_num){
            //on va modifier le contrat
            fprintf(fichier_contrat_tmp,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",id_contrat,id_voiture,id_client,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee,cout);
        }
    }while(!feof(fichier_contrat));
    //on ferme les fichiers
    fclose(fichier_contrat);
    fclose(fichier_contrat_tmp);
    //on supprime le fichier
    remove(contrat_db);
    //on renomme le fichier temporaire
    rename("contrat_tmp.txt",contrat_db);
    return;
}


void modifier_une_contrat(int num_contrat ,char* clients_db,char* voiture_db,char* contrat_db){
    //le programme ecrit par: Mohamed Ouaicha

    
    int id_contrat,id_voiture,id_client,cout,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee;
    FILE* fichier_contrat;
    FILE* fichier_contrat_tmp=fopen("contrat_tmp.txt","w");
    bool V1,V2;
    //on va chercher le contrat dans le fichier et on le modifie
    supprimer_une_contrat(num_contrat,contrat_db);
    printf("\n-------------------------------------------------------\n");
    printf("|    saisir les nouvelles informations du contrat     |\n");
    printf("-------------------------------------------------------\n");
    do{
        printf("Numero de voiture: ");
        scanf("%d",&id_voiture);
        V1 = est_exist(voiture_db,id_voiture);
        V2 = est_disponible(voiture_db,id_voiture);
        if(!V1){
            printf("\n-------------------------------------------------------\n");
            printf("  |       Il ya pas une voiture avec se id              |");
            printf("\n-------------------------------------------------------\n");
        }else if(!V2){
            printf("\n-------------------------------------------------------\n");
            printf("  |              Cette voiture est deja louer           |");
            printf("\n-------------------------------------------------------\n");
        }
    // il faut etre existe et dispo pour passer
    }while(!(V1 && V2));

    do{
        printf("Numero de client: ");
        scanf("%d",&id_client);
        printf("\n-------------------------------------------------------\n");
        printf("  |          Il ya pas un clien avec se id              |");
        printf("\n-------------------------------------------------------\n");
    }while(!client_deja_existe(clients_db,id_client));

    printf("Date de debut(jj/mm/aaaa): ");
    scanf("%d/%d/%d",&d_jour,&d_mois,&d_annee);

    printf("Date de fin(jj/mm/aaaa): ");
    scanf("%d/%d/%d",&f_jour,&f_mois,&f_annee);

    printf("Prix: ");
    scanf("%d",&cout);
    printf("\n-------------------------------------------------------\n");

    
    fichier_contrat=fopen(contrat_db,"a");
    
    fprintf(fichier_contrat,"%d - %d - %d - %d / %d / %d - %d / %d / %d - %d\n",id_contrat,id_voiture,id_client,d_jour,d_mois,d_annee,f_jour,f_mois,f_annee,cout);
    
    return;
}