#include<stdio.h>
#include"les_structures.h"
const int jours_par_mois[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int annees_bissextiles(date d){
    //on va caluler nombres des annees bissextiles passer 
    // on connait que 1 annee = 365.2425 jours
    int annee = d.annee;
    if(d.mois<=2){
        annee--;
    }
    // 97/400 * année ===> 0.2425 * annee
    return annee/4 - annee/100 + annee/400;
}
int nombre_des_jours(date d1,date d2){
    //on caluler suposant que 1 annee = 365 jours
    
    int i;
    long int nombre_jour_1 = d1.jour + d1.annee*365;
    long int nombre_jour_2 = d2.jour + d2.annee*365;
    for(i=0;i<d1.mois-1;i++){
        nombre_jour_1 += jours_par_mois[i];
    }
    for(i=0;i<d2.mois-1;i++){
        nombre_jour_2 += jours_par_mois[i];
    }
    //donc il faut ajouter le nombre des annees bissextiles
    //car chaque annee bissextile on va ajouter 1 jour
    nombre_jour_1 += annees_bissextiles(d1);
    nombre_jour_2 += annees_bissextiles(d2);
    return nombre_jour_2 - nombre_jour_1;

}