#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <fstream> 
#include <cstdlib> 

#include "element.h"
#include "Arbre.h"

using namespace std;

void Noeud::afficheNoeud(int decalage){

    //on affiche fd puis fg car dans la console l'arbre est renversé à la vertical
    //si le fd est pas vide alors on l'affiche
    if (fd!= nullptr){
        fd->afficheNoeud(decalage+3);
    }

    //on gère les decalages, on doit afficher le bon nb
    for (int i=0; i<decalage; i++){
        cout<<" ";
    }

    //on affiche la valeur de la racine du noeud
    cout<<info<<endl;

    //si le fg est pas vide alors on l'affiche
    if (fg!= nullptr){
        fg->afficheNoeud(decalage+3);
    }
}

Arbre::Arbre () {

    adRacine= nullptr;
}

//on fais une copie profonde du noeud
Noeud * Arbre::copieNoeud(Noeud *n2){

    //on creer un nouveau noeud
    Noeud * n1= new Noeud;

    //on l'initialise
    n1->info=0;
    n1->fg=nullptr;
    n1->fd=nullptr;

    //on enregistre l'info du noeud à copier dans une variable
    Elem INFO=n2->info;
    //on affecte cet info au noeud à construir
    n1->info= INFO;

    //on verifie que le fg du noeud à copier n'est pas null avant de rapeler récursivement la fonction sur celui-ci
    //afin d'affecter tous cela au fg du noeud en construction
    Noeud * FG=n2->fg;
    if (FG != nullptr){
        n1->fg= copieNoeud(FG);
    }

    //de meme pour le fd
    Noeud * FD=n2->fd;
    if (FD != nullptr){
        n1->fd= copieNoeud(FD);
    }

    return n1;
}

Arbre::Arbre (const Arbre &a) {

    adRacine=copieNoeud(a.adRacine);
}

void Arbre::SupprimerNoeud(Noeud *n) {

    if (n != nullptr) {
        //on apel recursivement la fonction pour supprimer fg et fd
        SupprimerNoeud(n->fg);
        SupprimerNoeud(n->fd);

        //on supprime le pointeur sur noeud
        delete n;
        n=NULL;
    }
}

Arbre::~Arbre(){

    SupprimerNoeud(adRacine);
}

void Arbre::insererElementAPartirDuNoeud(Noeud *&n, Elem e){
    //si le noeud est vide 
    if (n == nullptr){

        //on creer un noeud qui contiendra l'info "e" a inserer
        n= new Noeud;
        n->fg= nullptr;
        n->fd= nullptr;
        n->info= e;

    }else{

        if(e != n->info){

            if(e < n->info){
                insererElementAPartirDuNoeud(n->fg,e);
            }else{
                insererElementAPartirDuNoeud(n->fd,e);
            }
        }
    }
}

void Arbre::inserer(Elem e){

    insererElementAPartirDuNoeud(adRacine,e);

}

Noeud* Arbre::rechercherElementAPartirDuNoeud(Noeud *n,Elem e){

    if (n != nullptr){

        if(e == n->info){

            return n;

        }else{

            if(e < n->info){
                return rechercherElementAPartirDuNoeud(n->fg,e);
            }else{
                return rechercherElementAPartirDuNoeud(n->fd,e);
            }
        }
    }
    return nullptr;
}

Noeud* Arbre::rechercher(Elem e){

    return rechercherElementAPartirDuNoeud(adRacine,e);

}

Arbre& Arbre::operator=(const Arbre &b){
     
    adRacine=copieNoeud(b.adRacine);

    return *this;
} 

//parcours prefix
void Arbre::affichagePrefixNoeud(Noeud *n){
    
    if(n!=nullptr){

        cout<<n->info<<" ";
        affichagePrefixNoeud(n->fg);
        affichagePrefixNoeud(n->fd);
    }
}

void Arbre::parcours_prefixe(){
    affichagePrefixNoeud(adRacine);
}

//parcours infix
void Arbre::affichageInfixNoeud(Noeud *n){

    if(n!=nullptr){
        
        affichageInfixNoeud(n->fg);
        cout<<n->info<<" ";
        affichageInfixNoeud(n->fd);
    }
}

void Arbre::parcours_infixe(){
    affichageInfixNoeud(adRacine);
}

//parcours postfix
void Arbre::affichagePostfixNoeud(Noeud *n){
    
    if(n!=nullptr){
        
        affichagePostfixNoeud(n->fg);
        affichagePostfixNoeud(n->fd);
        cout<<n->info<<" ";
    }
}

void Arbre::parcours_postfixe(){
    affichagePostfixNoeud(adRacine);
}

void Arbre::affiche_etat_interne(){

    adRacine->afficheNoeud(0);
}

void ecrirPerfDansFichier1(const char * nomFichier,int info, double temp){

    ofstream ofs;
    ofs.open(nomFichier,ios::app);

    if( ofs.bad() ){
        cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);
    }

    ofs<<info<<' '<<temp<<endl;
    
    ofs.close();
}
