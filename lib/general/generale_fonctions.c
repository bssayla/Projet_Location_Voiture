#include"generale_fonctions.h"
#include<stdio.h>
#include<stdlib.h>
#include "../locations/gestion_location.h"
#include"../voitures/gestion_voitures.h"
#include "../cliens/gestion_cliens.h"

//Programe ecrit par Mohamed Ouaicha
//j'ai utilise return a la place de break dans le switch car il ya recursivite dans le switch
//est fait un bug que le programe rester dans la fonction meme si on a fini le switch
void menu_principal(char* voiture_db,char* client_db,char* location_db){
    //Mohamed Ouaicha
    int choix;
    system("clear");
    
    printf("\n               -------------------------MENU---------------------");
	printf("\n               |                                                |");
	printf("\n               |    1-Gestion des location.................     |");
	printf("\n               |    2-Gestion des voitures.................     |");
	printf("\n               |    3-Gestion des clients..................     |");
	printf("\n               |    4-Quitter..............................     |");
	printf("\n               |                                                |");
	printf("\n               |                                                |");
	printf("\n               --------------------------------------------------");
	printf("\n\n                                Votre choix  :  ");
    do{
        //prenant le choix de l'utilisateur et afficher la page suivant
        scanf("%d",&choix);
        switch(choix){
            case 1:
                system("clear");
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 2:
                system("clear");
                gestion_voitures_page(voiture_db,client_db,location_db);
                return;
            case 3:
                system("clear");
                gestion_clien_page(voiture_db,client_db,location_db);
                return;
            case 4:
                printf("\n-------------------------------------------------------\n");
                printf("|                        Au revoir                    |\n");
                printf("-------------------------------------------------------\n");
                return;
            default:
                printf("\nChoix invalide");
                break;
        }
        //si le choix est pas dans la liste en il faut resaisir le choix
        //en laissant la fonction menu principal a l'exterieur de la boucle
        //pour eviter de reprint de la page
        if(choix>4 || choix<=0){
            printf("\n\n\tVotre choix: ");
        }
    }while(choix!=4);
    return;
}
void gestion_voitures_page(char* voiture_db,char* client_db,char* location_db){
    //Mohamed Ouaicha


    printf("\n               ----------------------VOITURES--------------------");
	printf("\n               |                                                |");
	printf("\n               |    1-Afficher les voitures................     |");
	printf("\n               |    2-Ajouter une voiture..................     |");
	printf("\n               |    3-Supprimer une voiture................     |");
	printf("\n               |    4-Modifier une voiture.................     |");
	printf("\n               |    5-Retour...............................     |");
	printf("\n               |                                                |");
	printf("\n               --------------------------------------------------");
	printf("\n\n                                Votre choix  :  ");
    int choix,id;
    do{
        scanf("%d",&choix);
        switch(choix){
            case 1:
                system("clear");
                afficher_toutes_les_voitures(voiture_db);
                gestion_voitures_page(voiture_db,client_db,location_db);
                return;
            case 2:
                system("clear");
                ajouter_voiture(voiture_db);
                gestion_voitures_page(voiture_db,client_db,location_db);
                return;
            case 3:
                system("clear");
                printf("Donner id de la voiture a supprimer: ");
                scanf("%d",&id);
                supprimer_voiture(voiture_db,id);
                gestion_voitures_page(voiture_db,client_db,location_db);
                return;
            case 4:
                system("clear");
                printf("Donner id de la voiture a modifier: ");
                scanf("%d",&id);
                modifier_voiture(voiture_db,id);
                gestion_voitures_page(voiture_db,client_db,location_db);
                return;
            case 5:
                system("clear");
                menu_principal(voiture_db,client_db,location_db);
                return;
            default:
                printf("\nChoix invalide");
                break;
        }
        if(choix>5 || choix<=0){
            printf("\n\n\tVotre choix: ");
        }
    }while(choix!=5);
    return;
}
void gestion_location_page(char* voiture_db,char* client_db,char* location_db){
    //Mohamed Ouaicha

    int choix,idVoiture,numContrat;
    printf("\n               ---------------------LOCATION---------------------");
	printf("\n               |                                                |");
	printf("\n               |    1-Visualiser Contrat...................     |");
	printf("\n               |    2-Louer une voiture....................     |");
	printf("\n               |    3-Retourner une voiture................     |");
	printf("\n               |    4-Modifier un contrat..................     |");
	printf("\n               |    5-Supprimer un contrat.................     |");
	printf("\n               |    6-Retour...............................     |");
    printf("\n               |                                                |");
	printf("\n               --------------------------------------------------");
	printf("\n\n                                Votre choix  :  ");
    do{
        //prenant le choix de l'utilisateur et afficher la page suivant
        scanf("%d",&choix);
        switch(choix){
            case 1:
                system("clear");
                printf("donner le numero de contrat: ");
                scanf("%d",&numContrat);
                visualiser_location(location_db,numContrat);
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 2:
                system("clear");
                ajouter_contrat(voiture_db,client_db,location_db);
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 3:
                system("clear");
                printf("Donner le id de voitures: ");
                scanf("%d",&idVoiture);
                printf("donner ID de contrat de se voiture: ");
                scanf("%d",&numContrat);
                retourner_une_voiture(idVoiture,voiture_db,numContrat,location_db);
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 4:
                printf("donner le numero de contrat: ");
                scanf("%d",&numContrat);
                modifier_une_contrat(numContrat,client_db,voiture_db,location_db);
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 5:
                printf("donner le numero de contrat: ");
                scanf("%d",&numContrat);
                supprimer_une_contrat(numContrat,location_db);
                gestion_location_page(voiture_db,client_db,location_db);
                return;
            case 6:
                system("clear");
                menu_principal(voiture_db,client_db,location_db);
                return;
            default:
                printf("\nChoix invalide");
                break;
        }
        //si le choix est pas dans la liste en il faut resaisir le choix
        //en laissant la fonction menu principal a l'exterieur de la boucle
        //pour eviter de reprint de la page
        if(choix>6 || choix<=0){
            printf("\n\t\t\tVotre choix: ");
        }
    }while(choix!=6);
    return;
}
void gestion_clien_page(char* voiture_db,char* client_db,char* location_db){
    //Mohamed Ouaicha

    int choix,id;
    printf("\n               -----------------------CLIENTS--------------------");
	printf("\n               |                                                |");
	printf("\n               |    1-Liste les clients....................     |");
	printf("\n               |    2-Ajouter un client....................     |");
	printf("\n               |    3-Modifier un client...................     |");
	printf("\n               |    4-Supprimer un client..................     |");
	printf("\n               |    5-Retour...............................     |");
	printf("\n               |                                                |");
	printf("\n               --------------------------------------------------");
	printf("\n\n                                Votre choix  :  ");
    do
    {
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                system("clear");
                afficher_tous_les_clients(client_db);
                gestion_clien_page(voiture_db,client_db,location_db);
                return;
            case 2:
                system("clear");
                ajouter_client(client_db);
                gestion_clien_page(voiture_db,client_db,location_db);
                return;
            case 3:
                system("clear");
                printf("Donner id du client a modifier: ");
                scanf("%d",&id);
                modifier_client(client_db,id);
                gestion_clien_page(voiture_db,client_db,location_db);
                return;
            case 4:
                system("clear");
                printf("Donner id du client a supprimer: ");
                scanf("%d",&id);
                supprimer_client(client_db,id);
                gestion_clien_page(voiture_db,client_db,location_db);
                return;
            case 5:
                system("clear");
                menu_principal(voiture_db,client_db,location_db);
                return;
            default:
                printf("\nChoix invalide");
                break;
        }
    } while (choix!=5);
    
    return;
}
