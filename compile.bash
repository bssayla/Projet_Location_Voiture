#!/bin/bash
echo 'le pojects ecrit par: Mohamed Ouaicha Github:@bssayla'
#ecrire le mot bssayla utilisant la commande echo
echo '██████╗░░██████╗░██████╗░█████╗░██╗░░░██╗██╗░░░░░░█████╗░'
echo '██╔══██╗██╔════╝██╔════╝██╔══██╗╚██╗░██╔╝██║░░░░░██╔══██╗'
echo '██████╦╝╚█████╗░╚█████╗░███████║░╚████╔╝░██║░░░░░███████║'
echo '██╔══██╗░╚═══██╗░╚═══██╗██╔══██║░░╚██╔╝░░██║░░░░░██╔══██║'
echo '██████╦╝██████╔╝██████╔╝██║░░██║░░░██║░░░███████╗██║░░██║'
echo '╚═════╝░╚═════╝░╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝'
gcc -c  ./lib/general/generale_fonctions.c
gcc -c  ./lib/general/les_structures.c
gcc -c  ./lib/cliens/gestion_cliens.c
gcc -c  ./lib/locations/gestion_location.c
gcc -c  ./lib/voitures/gestion_voitures.c
gcc -c main.c
gcc -o main.exe gestion_voitures.o gestion_cliens.o gestion_location.o generale_fonctions.o les_structures.o main.o
echo 'compilation terminer'








