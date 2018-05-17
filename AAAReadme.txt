                              

                                .--.              .  
                                |   )       o    _|_ 
                                |--'.--..-. . .-. |  
                                |   |  (   )|(.-' |  
                                '   '   `-' | `--'`-'
                                            ;        
                                         `-'         



Julie Loisel/ Jeremy Uzan


4M053 : Calcul scientifique pour les grands systèmes linéaires
C.Guichard, X.Claeys, P.Marchand & B.Thierry






DESCRIPTIF D'INTRODUCTION

Après avoir créé et implémenté les 3 classes DenseMatrix, SparseMatrix et FredholmMatrix, le projet consistait à trouver un moyen d'optimiser le calcul de la décomposition en valeurs singulières tronquée. 



CONTENU DES DIFFERENTS FICHIERS

Le projet est composé de 
- 3 fichiers cpp, 3 fichiers hpp constitutifs des 3 classes DenseMatrix, SparseMatrix et FredholmMatrix, 
- 1 fichier CrossApprox.cpp contenant la fonction qui modélise l'algorithme d'approximation en croix de la question 7
- d'un Makefile permettant de compiler le projet, 
- d'un main.cpp contenant des tests. 
Enfin, il contient 
-un fichier filename permettant de récupérer les valeurs des coefficients tests de la matrice dense
-un graphique représentant la courbe décroissante de la partie 6 du projet



MISE EN MARCHE



1ERE PARTIE: extraction des valeurs des coefficients de la matrice dense récupérés depuis le fichier filename 
-Dans votre terminal, dirigez-vous vers le projet nommé Projet a l'aide de la commande "cd location/location/location/Projet"
-Exécutez à l'aide de la commande "make" qui permet de compiler 
-Effectuez ensuite "bin/question1" qui va permette l'affichage des coefficients de la matrice dense


2E PARTIE: implémentation de la classe SparseMatrix
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question2"
La question2.cpp crée une matrice A à partir de ses coordonnées CSR row, col et val. Il teste l'affichage des valeurs de val, affiche ladite matrice A,  effectue le produit de la matrice A avec le vecteur unitaire de taille 5, et l'affiche. 


3E PARTIE: implémentation de la classe FredholmMatrix
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question3"
La question3.cpp va effectuer plusieurs teste sur la classe FredholmMatrix:
     1) On affiche une matrice de Fredholm de taille 5*5 initialisée à 0
     2) On teste la fonction Insert
     3) On teste le produit
     4) On teste le Solver


4E PARTIE: Décomposition en valeurs singulières
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question4"
La question4.cpp teste la fonction amie FrobeniusNorm et affiche une matrice A donnée et sa norme de Frobenius. 


5E PARTIE: Calcul de la SVD tronquée à l'aide de la library GSL
-Installer la libraire GSL en écrivant sur le terminal :(sur Windows): sudo apt-get install libgsl2, (sur MAC):brew install gsl 
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question5"
La question5.cpp affiche une matrice B de taille 5*5 donnée et calcule la SDV tronquée à l'ordre k (k allant de 1 à 5) .


6E PARTIE: Visualisation 
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question6"
Le main.cpp permet d'afficher la matrice définit par 
B = (Bj,k) ∈ RN×N et Bj,k = exp(−(j − k)^2/N^2) pour un N choisit
-Ouvrez ensuite le graphique du dossier Projet; il représente la courbe donnant l'erreur log( ∥B−Bk∥ F) en fonction de |log(k)| sur k = 1...N


7E PARTIE: Algorithme d'approximation en croix
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question7"
La question7.cpp teste le bon fonctionnement de la fonction membre de la classe FredholmMatrix qui modélise l'algorithme d'approximation en croix permettant de construire une approximation de B sous la forme Ar=Somme de p=1 à r de (sp*up*vpt)


8E PARTIE: Visualisation
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question8"
- Ouvrez (si terminé) le graphique (non achevé) du dossier ProjetJJ; il représente courbe donnant log(∥B − B􏰇k∥F) en fonction de | log(k)| sur k = 1 . . . N, où B􏰇k a cette fois été construit à l'aide de l'algorithme d'approximation en croix.




