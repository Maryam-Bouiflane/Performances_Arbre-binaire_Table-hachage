#include <iostream> 
#include <math.h>  
#include <cstdlib> 
#include <cstdio>
#include <fstream> 
#include <algorithm>

#include "Table.h"

using namespace std;


Table::Table(unsigned int taille_table){
    //on initialise les donnee membre de la table et toutes celles des cellules
    taille=taille_table;
    tab = new Cellule[taille];
    for (unsigned int i=0; i<taille; i++){

        tab[i].info=0.0;
        tab[i].cle=0;
        tab[i].etat=LIBRE;
        tab[i].nb_essai=0;
    }
    pcollis = nullptr;
}

Table::~Table(){
    //on libere les pointeurs
    delete [] tab;
    pcollis = nullptr;
}

void Table::inserer(CLE cle, INFOASSOCIEE info_a_ajouter){

    unsigned int nb_essai=1;
    unsigned int h=hachage(cle,taille); //h est le haché
    unsigned int indice=h; //on initialise l'indice au haché

    //tant que ma case est occupé et que je n'ai pas encore fini de parcourir ma table totalement 
    //je calcul un nouvelle indice où aller tenter l'insertion de nouveau
    while( (tab[indice].etat == OCCUPE) && (nb_essai<=taille) ){ 
        indice= pcollis(h,nb_essai,taille);    //on apelle notre fonction de réhashage, indice prend la nouvelle valeur
        nb_essai++; //on incrémente le nb de tentatives
    }

    //j'ai maintenant mon indice où je peux inserer donc j'insere, on modifie tout les champs de la case
    tab[indice].info= info_a_ajouter;
    tab[indice].cle=cle;
    tab[indice].etat=OCCUPE;
    tab[indice].nb_essai=nb_essai;

}

void Table::supprimer(CLE cle){

    unsigned int nb_essai=1;
    unsigned int h=hachage(cle,taille); //h est le haché
    unsigned int indice=h; //on initialise l'indice au haché

    //on parcours notre table, si la case est occupé et que la clé de celle-ci est = à celle qu'on cherche
    //alors on remet tous ces camps à zero et son état à LIBERER ,on a donc supprimer la clé de la table
    while( (tab[indice].etat != LIBRE) && (nb_essai<=taille) ){ 
        
        if(tab[indice].etat == OCCUPE && tab[indice].cle==cle){
            
            tab[indice].info = 0.0;
            tab[indice].cle = 0;
            tab[indice].etat = LIBERE;
            tab[indice].nb_essai=0;
        }

       indice=pcollis(h,nb_essai,taille);   
       nb_essai++;
    }
    
}

bool Table::rechercher(CLE cle, unsigned int &indice_found){

    unsigned int nb_essai=1;
    unsigned int h=hachage(cle,taille);
    unsigned int indice=h;

    //bouléen qu'on va retourner qui indiquera si on a trouver la clé
    bool trouver = false;
 
    if (nb_essai<=taille){

        //si la case est occupé et que la clé de celle-ci = la clé recherché
        if(tab[indice].etat == OCCUPE && tab[indice].cle==cle){

            //on stock l'indice de cette case et on met le booléen à true
            indice_found=indice;
            trouver = true;
        }

        //sinon on met le booléen à false
        if(tab[indice].etat == LIBERE || tab[indice].etat == LIBRE) {

            trouver = false;
        }

        indice=pcollis(h,nb_essai,taille);
        nb_essai++;
    }
    /*
    //à décommenter pour le test des fonctions
    if(trouver == true){
        cout<<"La clé: "<<cle<<" a été trouvé dans la table à l'indice "<<indice_found<<endl;
    }else{
        cout<<"Cette clé n'a pas été trouvé dans la table!"<<endl;
    }
    */
    return trouver;
}

INFOASSOCIEE Table::retournerInfo(CLE cle){

    unsigned int indice;
    bool trouver;
    trouver = rechercher(cle,indice); 

    //si on a trouvé la clé dans la table alors retourne l'info de celle-ci
    //sinon on retourne une valeur par défault 
    if (trouver == true){  

        return tab[indice].info;

    }else return -1.0;
}

void Table::modifierInfo(CLE cle, INFOASSOCIEE new_info){

    unsigned int indice;
    bool trouver;
    trouver = rechercher(cle,indice);

    //si on a trouvé la clé dans la table on modifie son info avec la nouvelle placé en paramètre
    if (trouver == true){

        tab[indice].info= new_info;
        //cout<<"On a modifié, maintenant l'info de "<<cle<<" est "<<new_info<<endl;
    }
}

void Table::afficher(){

    unsigned int i=0;

    //on parcours toute la table depuis le début et on affiche la clé et le nb d'essaie de chaque cases
    while (i<taille){

        if (tab[i].etat == OCCUPE){

            cout<<"Clé: "<<tab[i].cle<<endl;
            cout<<"Nb d'essaie réalisé: "<<tab[i].nb_essai<<endl;
            cout<<"------------------------"<<endl;
        }
        
        i++;
    }
}

//on prend en paramètre une clé et on retourne un indice du tableau de la table (on apel cet indice le haché)
unsigned int hachage(CLE cle, unsigned int taille_table){

    unsigned int indice=cle % taille_table;
    return indice;
}

//h est le haché de la clé dont j'essaie de voir les collisions
//nb_essai est le nombre d'essaie associé à cette clé
//taille_table est la taille de la table 
unsigned int collision1(unsigned int h, unsigned int nb_essai, unsigned int taille_table){    

    unsigned int indice= h + nb_essai;

    //si l'indice calculé est >= à la taille de la table alors je fais % pour obtenir un indice dans 
    //les bornes de la table
    if (indice >= taille_table){
        indice=indice % taille_table;
    }

    return indice;
}

unsigned int collision2(unsigned int h, unsigned int nb_essai, unsigned int taille_table){  

    unsigned int indice= h + pow(nb_essai,2);

    if (indice >= taille_table){
        indice=indice % taille_table;
    }
    
    return indice;
}

unsigned int collision3(unsigned int h, unsigned int nb_essai, unsigned int taille_table){   

    unsigned int indice= h + nb_essai*h;

    if (indice >= taille_table){
        indice=indice % taille_table;
    }

    return indice;
}

//nomFichier est le nom du fichier où ecrir
//taille est la taille de ma table
//temp est la performance de recherche ou d'insertion calculé
void ecrirPerfDansFichier2(const char * nomFichier,int taille, double temp){

    ofstream ofs;
    ofs.open(nomFichier,ios::app);

    if( ofs.bad() ){
        cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);
    }

    ofs<<taille<<' '<<temp<<endl;
    
    ofs.close();
}

