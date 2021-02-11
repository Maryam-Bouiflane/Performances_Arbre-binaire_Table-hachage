Binôme:
BOUIFLANE Maryam, ANGE NIRINA Michaela Rolland

 
ARBRE 
===============================================

 Dans le fichier .h :
----------------------

* Une structure Noeud.
* Une class Arbre.
* Un fichier d'extention Element.h contenant un element de type entier.

 Dans le fichier .cpp : 
------------------------

Nous avons réalisés dans la class Arbre, les fonctions suivantes :

* le constructeur par défaut.
* le constructeur pas copie.
* la procedure SupprimerNoeud qui prend un noeud en parametre.
* le destructeur.
* la procedure d'affichage afficheNoeud de la structure Noeud.
* Trois procédure d'affichage qui pennent chancune un noeud en parametre :
  - affichagePrefixNoeud
  - affichageInfixNoeud
  - affichagePostfixNoeud
* la fonction copieNoeud qui prend un noeud en parametre et retourne un noeud.
* la procedure insererElementAPartirDuNoeud pour inserer un element de type Elem dans un noeud
* la procedure inserer pour inserer un element de type elem dans un arbre.
* la fonction rechercherElementAPartirDuNoeud qui prend un noeud et un element en paremetre et retourne un noeud.
* la fonction rechercher qui prend un element en paremetre et qui retourne un noeud.
* Trois procédures d'affichage d'arbre : 
  - parcours_prefixe
  - parcours_infixe
  - parcours_postfixe

En dehors de la class Arbre, nous avons les fonction suivantes :

* le procédure ecrirPerfDansFichier pour l'écriture dans un fichier.
* le procédure lireDansFichier pour l'écriture dans un fichier.

 
 TABLE DE HASHAGE 
===============================================

 Dans le fichier .h :
----------------------

* Une classe enum d'etat.
* Une class Cellule.
* Une classe Arbre.
* Un fichier d'extention Cle.h contenant une clé de type entier positif.
* Un fichier d'extention InfoAssociee.h contenant un element de type double.
    
 Dans le fichier .cpp :
-------------------------

Nous avons réalisés dans la class, les fonctions suivantes :

* le constructeur par défaut,
* le constructeur pas copie.
* le destructeur.
* la procedure inserer qui prend une clé de type Cle et une info de type InfoAssociee en parametre.
* la procedure supprimer qui prend une cle en parametre.
* la fonction rechercher qui prend une clé de type clé et une indice de type entier positif en paremetre.
* la fonction retournerInfo qui prend une clé de type clé en parametre et retourne une InfoAssociee.
* la procedure modifierInfo qui prend une clé de type Cle et une info de type InfoAssociee en parametre.
* la procedure d'affichage afficher.

En dehors de la class Arbre, nous avons les fonction suivantes :

* la fonction Hashage qui prend une clé de type clé et une indice de type entier positif en paremetre et qui retourne un entier positif.
* Trois fonctions de Rehashage qui prennet chancune trois entiers positifs en parametre et qui retourne chancune un entier positif :
  - collision1 pour le rehashage linéaire.
  - collision2 pour le rehashage quadratique.
  - collision3 pour le double hashage.
* le procédure ecrirPerfDansFichier pour l'écriture dans un fichier.
* le procédure lireDansFichier pour l'écriture dans un fichier.
	
MAIN 
===============================================

L'utilisateur à le choix entre executer le programme des Arbres ou bien celui des Tables de hashage
	
* [ ] S'il choisit la table de hashage nous avons:
	
	* Creation de deux fichiers pour la performance des procedures d'insertion et de la recherche.
	* Creation d'un tableau de table de taille nbTable.
	* Lancement du chrono sur la performance de la procedure rechercher.
	* Ecrire le resultat dans le fichier destiné.
	* Lancement du chrono sur la performance de la procedure inserer.
	* Ecrire le resultat dans le fichier destiné.
	* affichage de courbe grâce à gnuplot : commande plot " " sur le fichier choisi.
    
    
* [ ] S'il choisit les Arbres alors nous avons:
    
	* Creation de deux fichiers pour la performance des procedures d'insertion et de la recherche.
	* Creation d'un tableau d'arbre de taille nbArbre.
	* Lancement du chrono sur la performance de la procedure rechercher.
	* Ecrire le resultat dans le fichier destiné.
	* Lancement du chrono sur la performance de la procedure inserer.
	* Ecrire le resultat dans le fichier destiné.
	* affichage de courbe grâce à gnuplot : commande plot " " sur le fichier choisi.


ETUDE DES PERFOMANCES
===============================================

On a éffectué une étude de la performance au niveau des fonctions d'inserion et de recherche, sur 10000 caractères, pour la classe Table de Hashage et Arbre.

-> On a commencé par construire un tableau de pointeurs pour les deux class.
* Puis créer une fonction pour chronométrer la durée du lancement de chaque 
élement dans les deux fonctions (affichage et insersion).
* Ensuite nous avons stocker les résultats qui y sont générées dans un fichier.
-Pour tester toutes les fonctions du programme, les appels des fonctions sont mis en commentaire
dans le main, il suffit de les décommenter pour observer leur fonctionnement.
-Des "cout" sont mis en commenteires dans les fichier .cpp pour voir le fontionnement des procedures 
ou la valeur de retour desfocntions. 
-Enfin grace à gnuplot, nous avons pu conclure la performance de chaque classe :
    -Pour la tables de Hashage, les informations sont considérables autour de la valeur:
        -Pour la fonction inserer :  
            -utliser set yrange [0.00 000 000:0.00 000 009].
            -plot " " sur le fichier d'extention txt
            -les elements sont concentrés autour de la valeur : 0,00 000 005
        -Pour la procedure recherche :
            -utliser set yrange [0.000 000:0.000 006].
            -plot " " sur le fichier d'extention txt
            -les elements sont concentrés autour de la valeur : 0,000 002
    -Pour les arbres, les informations sont considérables autour de la valeur:
        -Pour la fonction inserer : 0,000 001.
            -utliser set yrange [0.000 000:0.000 005].
            -plot " " sur le fichier d'extention txt
            -les elements sont concentrés autour de la valeur : 0,000 001
        -Pour la procedure recherche :0,00 000 008.
            -utliser set yrange [0.00 000 000:0.00 000 006].
            -plot " " sur le fichier d'extention txt
            -les elements sont concentrés autour de la valeur : 0,00 000 002
-La performance pour l'insertion est meilleure dans les tables de Hashage.
-La performance pour la recherche est meilleure pour les arbres.

