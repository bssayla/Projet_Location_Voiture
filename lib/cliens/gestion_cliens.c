#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"gestion_cliens.h"
#include"../general/les_structures.h"

//le programme ecrit par: Mohamed Ouaicha
bool client_deja_existe(char* fichier,int id){
    //Mohamed Ouaicha
    FILE* client_db = fopen(fichier,"r");
    int cin,telephone,f_id;
    char f_nom[20],f_prenom[20],adress[30];    do{
        fscanf(client_db,"%d - %s - %s - %d - %s - %d\n",&f_id,f_nom,f_prenom,&cin,adress,&telephone);
        if(f_id==id){
            fclose(client_db);
            return true;
        }
    }while(!feof(client_db));
    fclose(client_db);
    return false;
}
void ajouter_client(char* fichier){
    //Mohamed Ouaicha
    FILE* client_db = fopen(fichier,"a");
    int cin,telephone,id;
    char nom[20],prenom[20],adress[30];
    printf("\n-------------------------------------------------------\n");
    printf("Veuillez saisir les nouvelles informations du client\n");
    printf("-------------------------------------------------------\n");
    
    printf("ID de Client: ");
    scanf("%d",&id);

    getc(stdin);
    printf("Nom de Client: ");
    scanf("%s",nom);

    printf("Prenom: ");
    scanf("%s",prenom);
    
    printf("l'adress: ");
    scanf("%s",adress);

    printf("CIN: ");
    scanf("%d",&cin);

    printf("Telephone: ");
    scanf("%d",&telephone);
    printf("\n-------------------------------------------------------\n");

    if(client_deja_existe(fichier,id)){
        system("clear");
        printf("\n-------------------------------------------------------\n");
        printf("Le clien existe deja chager l'id ou le nom\n");
        printf("-------------------------------------------------------\n");
        ajouter_client(fichier);
    }else{
        fprintf(client_db,"%d - %s - %s - %d - %s - %d\n",id,nom,prenom,cin,adress,telephone);
        printf("\nLe Client a ete ajoute avec succes\n");
    }
    fclose(client_db);
    return;

}
void afficher_client(client c){
    //Mohamed Ouaicha
    printf("\n--------------------------INFO CLIEN------------------------\n");
    printf("\t\tID: %d\n",c.idClient);
    printf("\t\tNom complet: %s %s\n",c.nom,c.prenom);
    printf("\t\tCIN: %d\n",c.cin);
    printf("\t\tAdress: %s\n",c.adresse);
    printf("\t\tTelephone: 0%d\n",c.telephone);
    return;
}
void afficher_tous_les_clients(char* fichier){
    //Mohamed Ouaicha
    client c;
    FILE* clients_db = fopen(fichier,"r");
    if(clients_db == NULL){
        printf("en peut pas ouvrir le fichier client\n");
        return;
    }
    do{
        fscanf(clients_db,"%d - %s - %s - %d - %s - %d\n",&c.idClient,c.nom,c.prenom,&c.cin,c.adresse,&c.telephone);
        afficher_client(c);
    }while(!feof(clients_db));
    fclose(clients_db);
    return;
}

void supprimer_client(char* fichier,int id ){
    //Mohamed Ouaicha
    FILE* client_db = fopen(fichier,"r");
    FILE* client_db_tmp = fopen("client_db_tmp.txt","w");
    int cin,telephone,f_id;
    char f_nom[20],f_prenom[20],adress[30];
    do{
        fscanf(client_db,"%d - %s - %s - %d - %s - %d\n",&f_id,f_nom,f_prenom,&cin,adress,&telephone);
        if(f_id!=id){
            fprintf(client_db_tmp,"%d - %s - %s - %d - %s - %d\n",f_id,f_nom,f_prenom,cin,adress,telephone);
        }
    }while(!feof(client_db));
    fclose(client_db);
    fclose(client_db_tmp);
    remove(fichier);
    rename("client_db_tmp.txt",fichier);
    return;
}
void modifier_client(char* fichier,int id){
    //Mohamed Ouaicha
    FILE* client_db;
    int cin,telephone,idClient,size;
    char nom[20],prenom[20],adress[30];
    //effacer les anciennes informations
    supprimer_client(fichier,id);
    client_db = fopen(fichier,"a");

    //ajouter les nouvelles informations avec le meme id
    printf("\n-------------------------------------------------------\n");
    printf("|     saisir les nouvelles informations du client     |\n");
    printf("-------------------------------------------------------\n");

    getc(stdin);
    printf("Nom de Client: ");
    scanf("%s",nom);

    printf("Prenom: ");
    scanf("%s",prenom);
            
    printf("l'adress: ");
    scanf("%s",adress);

    printf("CIN: ");
    scanf("%d",&cin);

    printf("Telephone: ");
    scanf("%d",&telephone);
    printf("\n-------------------------------------------------------\n");
    fprintf(client_db,"%d - %s - %s - %d - %s - %d\n",id,nom,prenom,cin,adress,telephone);
    fclose(client_db);
    return;
    
}