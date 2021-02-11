#include <iostream>
#include <chrono> 
#include <cstdlib> 
#include <cstdio>
#include <math.h>  
#include <fstream> 
#include <algorithm>
#include <vector> //si on utilise la 2e méthode de stockage des tables

#include "Table.h"
#include "Arbre.h"

using namespace std;

const int nbArbre=10000;
const int MAX_CHAR=100000;  //taille max de mes fichiers
const int TAILLE_TABLE=1000;  //capacité de mes tables
const int nbTable=10000;  //nb de tables créé

int main()
{
      int rep;
      cout<<"Voulez-vous faire un arbre (si oui tapez 1)"<<endl;
      cout<<"Voulez-vous faire une table de Hashage (si oui tapez 2)"<<endl;
      cin>>rep;

      switch(rep){

            case 1: 

            cout<<endl<<"=============== PERFORMANCES ==============="<<endl;
            char fichierRecherche1[MAX_CHAR];
            char fichierInserer1[MAX_CHAR]; 

            cout << "Entrez le nom du fichier de performance de recherche a creer" <<endl;
            scanf("%99s",fichierRecherche1);
            cout << "Entrez le nom du fichier de performance d'insertion a creer" <<endl;
            scanf("%99s",fichierInserer1);


            int nb_alea;
            Arbre* tab[nbArbre];

            for(int i=0; i<nbArbre; i++){

                  tab[i]=new Arbre;
            }

            for(int i=0; i<nbArbre; i++){

                  nb_alea=rand();   
                  auto debutR = chrono::system_clock::now(); //start du chrono
                  {
                        /*
                        for(int j=0; j<nbArbre; j++){
                              nb_alea=rand();
                              tab[i]->rechercher(nb_alea);
                        }
                        */

                        tab[i]->rechercher(nb_alea);
                  }

                  auto finR = chrono::system_clock::now(); //stop du chrono
                  chrono::duration<double> elapsedR = finR - debutR; //on recup la duree des opération de recherche

                  double tempsR = elapsedR.count(); //on calcul le temps de recherche
                  ecrirPerfDansFichier1(fichierRecherche1,nb_alea,tempsR); //on ecrit la perf dans le fichier de performance de recherche


                  auto debutI = chrono::system_clock::now(); //start du chrono
                  {
                        /*
                        for(int j=0; j<nbArbre; j++){
                              nb_alea=rand();
                              tab[i]->inserer(nb_alea);
                        }
                        */

                        tab[i]->inserer(nb_alea);
                  }

                  auto finI = chrono::system_clock::now(); //stop du chrono
                  chrono::duration<double> elapsedI = finI - debutI; //on recup la duree de l'opération d'insertion

                  double tempsI = elapsedI.count(); //on calcul le temps d'insertion
                  ecrirPerfDansFichier1(fichierInserer1,nb_alea,tempsI); //on ecris la perf dans le fichier de performance d'insertion
            }

            break;

            case 2: 

            cout<<endl<<"=============== PERFORMANCES ==============="<<endl;
            char fichierRecherche2[MAX_CHAR]; 
            char fichierInserer2[MAX_CHAR];  
            
            cout << "Entrez le nom du fichier de performance de recherche a creer" <<endl;
            scanf("%99s",fichierRecherche2);  //creation du fichier de perf de recherche
            cout << "Entrez le nom du fichier de performance d'insertion a creer" <<endl;
            scanf("%99s",fichierInserer2);  //creation du fichier de perf d'insertion
            
            //on demande à l'utilisateur le réhashage souhaité
            int rep;
            cout<<"Voulez-vous faire un ré-hashage linéaire? (si oui tapez 1)"<<endl;
            cout<<"Voulez-vous faire un ré-hashage quadratique? (si oui tapez 2)"<<endl;
            cout<<"Voulez-vous faire un double ré-hashage? (si oui tapez 3)"<<endl;
            cin>>rep;



            int nb_alea2;  //nb aléatoir qui sera tiré à la recherche et l'insertion
            unsigned int indice_trouver=0; //on initialise le param de la fonction recherche
            INFOASSOCIEE info_a_inserer=1.5;  //on initialise l'info associee a la cle
            
            //2e façon de stocker toutes mes tables creé
            //vector <Table> tab;
            Table* tab2[nbTable];

            for(int i=0; i<nbTable; i++){  
                  
                  //tab.emplace_back (TAILLE_TABLE); //ajoute et construit une nouvelle table dans le tableau tab
                  tab2[i]=new Table(TAILLE_TABLE); //chaque case de mon tab va pointer vers une table nouvellement construite
            }

            for(int i=0; i<nbTable; i++){
                  
                  switch(rep){ //en fonction du réhashage choisi par l'utilisateur on fais pointer le pointeur vers la bonne fonction de réhashage

                  case 1: tab2[i]->pcollis=collision1;
                        break;

                  case 2: tab2[i]->pcollis=collision2;
                        break;

                  case 3: tab2[i]->pcollis=collision3;
                        break;
                  default:
                        break;
                  }
                  
                  auto debutR = chrono::system_clock::now(); //start du chrono
                  {
                        for(int j=0; j<nbTable; j++){  //on recherche nbTable fois des clé dans ma table
                              
                              nb_alea2=rand(); //on tire un nouvelle cle aléatoirement
                              tab2[i]->rechercher(nb_alea2,indice_trouver);
                        }
                  }

                  auto finR = chrono::system_clock::now(); //stop du chrono
                  chrono::duration<double> elapsedR = finR - debutR;  //on recup la duree des opération de recherche

                  double tempsR = elapsedR.count()/TAILLE_TABLE; //on calcul le temps moyen de recherche
                  ecrirPerfDansFichier2(fichierRecherche2,i,tempsR); //on ecrit la perf dans le fichier de performance de recherche

                  
                  auto debutI = chrono::system_clock::now(); //start du chrono
                  {
                        for(int j=0; j<TAILLE_TABLE; j++){ //on insere nbTable fois des clé dans ma table
                              
                              nb_alea2=rand(); //on tire un nouvelle cle aléatoirement
                              tab2[i]->inserer(nb_alea2,info_a_inserer); 
                        }
                  }

                  auto finI = chrono::system_clock::now();  //stop du chrono
                  chrono::duration<double> elapsedI = finI - debutI; //on recup la duree de l'opération d'insertion

                  double tempsI = elapsedI.count()/TAILLE_TABLE; //on calcul le temps moyen d'insertion
                  ecrirPerfDansFichier2(fichierInserer2,i,tempsI); //on ecris la perf dans le fichier de performance d'insertion
                  
                  info_a_inserer+=2; //on incremente la valeur associé aux cle de ma table ->pas forcément nécessaire
            }

            break;

      }

      return 0;
}
