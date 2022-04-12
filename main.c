//les biblio
#include <stdio.h>
#include <stdlib.h>
#include "lib/general/generale_fonctions.h"


int main(){
    int choix;
    //le menu principal pour choisi ce qu'ils veulent faire
    menu_principal("./database/voitures.txt","./database/clients.txt","./database/contrats.txt");
    
    return 0;
}