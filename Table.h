#ifndef _TABLE
#define _TABLE

#include "Cle.h"
#include "InfoAssociee.h"

enum ETAT{
        LIBRE,
        OCCUPE,
        LIBERE
    };

class Cellule{
    public:
        INFOASSOCIEE info;  //prix des produits de l'epicerie
        CLE cle;
        ETAT etat; //etat de la cellule
        unsigned int nb_essai; //nb de tentatives d'insertion de cette clé
};

class Table
{

    unsigned int taille; //m (ds le sujet de tp)
    Cellule *tab;

    public:
        unsigned int (*pcollis)(unsigned int , unsigned int , unsigned int); //pointeur de fonction qu'on a appelé "pcollis"

        Table(unsigned int taille_table);
        ~Table();

        /*Table& operator=(Table&) = delete;
        Table(Table&) = delete;*/

        void inserer(CLE cle, INFOASSOCIEE info_a_ajouter);
        void supprimer(CLE cle);
        bool rechercher(CLE cle, unsigned int &indice_found);

        INFOASSOCIEE retournerInfo(CLE cle);
        void modifierInfo(CLE cle, INFOASSOCIEE new_info);

        void afficher();

};
//hashage basique
unsigned int hachage(CLE cle, unsigned int taille_table);

//adressage ouvert
unsigned int collision1(unsigned int h_init, unsigned int nb_essai, unsigned int taille_table); //réhashage linéaire
unsigned int collision2(unsigned int h_init, unsigned int nb_essai, unsigned int taille_table); //réhashage quadratique
unsigned int collision3(unsigned int h_init, unsigned int nb_essai, unsigned int taille_table); //double hashage

//fonction permettant d'écrir dans un fichier la taille de la table et sa performance correspondante
void ecrirPerfDansFichier2(const char * nomFichier,int taille, double temp);

#endif