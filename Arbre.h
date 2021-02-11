#ifndef _ARBRE
#define _ARBRE

#include <iostream>
#include <string.h>
#include "element.h"

struct Noeud{

    Elem info; //info du noeud d etype Elem
    Noeud * fg; 
    Noeud * fd;

    void afficheNoeud(int decalage); //affiche le noeud sur la console
};


class Arbre{

    private:
        //Donées membres
        Noeud * adRacine;

    public:

        //Fonctions membres

        //preconditions : aucune
        //postcondition : l'arbre est initialement vide 
        Arbre();

        //preconditions : n -> de type pointeur sur noeud
        //postcondition: construit un noeud par copie (copie profonde)
        Noeud * copieNoeud(Noeud *n2); 

        //preconditions : a -> de type arbre en donnée résultat
        //postcondition: construit un arbre identique à "a"
        Arbre(const Arbre &a); 

        //preconditions : n -> de type pointeur sur noeud
        //postcondition: la mémoire alloué sur le tas est libéré
        void SupprimerNoeud(Noeud *n);

        //preconditions : aucune
        //postcondition : l'arbre est supprimé
        ~Arbre();


        //preconditions : n -> de type pointeur sur noeud, e -> de type Elem
        void insererElementAPartirDuNoeud(Noeud * &n,Elem e);

        void inserer(Elem e);

        Noeud* rechercherElementAPartirDuNoeud(Noeud *n,Elem e);
        Noeud* rechercher(Elem e); //recherche un élement dans l'arbre

        Arbre& operator=(const Arbre &b);

        //preconditions : n -> de type pointeur sur noeud
        //postcondition : affiche le parcours prefixe de "n"
        void affichagePrefixNoeud(Noeud *n); 

        //preconditions : aucune
        //postcondition :affiche le parcours de l'abre de façon prefixe
        void parcours_prefixe();  

        //preconditions : n -> de type pointeur sur noeud
        //postcondition : affiche le parcours infixe de "n"
        void affichageInfixNoeud(Noeud *n);

        //preconditions : aucune
        //postcondition :affiche le parcours de l'abre de façon infixe
        void parcours_infixe(); 

        //preconditions : n -> de type pointeur sur noeud
        //postcondition : affiche le parcours postfixe de "n"
        void affichagePostfixNoeud(Noeud *n);

        //preconditions : aucune
        //postcondition :affiche le parcours de l'arbre de façon postfixe
        void parcours_postfixe(); 

        //preconditions : aucune
        //postcondition : affiche l'arbre de façon renversé sur la console
        void affiche_etat_interne(); 
   
};


//preconditions : nomFichier ->chaine de caracteres designant le nom du fichier a creer
//postcondition : le fichier nomFichier ->contient nb entiers separes par des espaces
void ecrirPerfDansFichier1(const char * nomFichier,int info, double temp);


#endif