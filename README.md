# Projet Jeu de Plateau IMT Nord Europe
## Introduction
Ce projet de développement d'un jeu de plateau en C fonctionnel sur terminal a été réalisé par Guillaume FAURE, Alexandre DORCIVAL et William NGUYEN dans le cadre de notre cursus à l'IMT.<br>
Nous avons décidé de réaliser le jeu "Le Labyrinthe", à la fois faisable sur terminal, très intéressant et amusant.
## Comment lancer le jeu
Pour lancer le jeu, le simple fichier game.exe lance le jeu sur le terminal. Attention, le jeu n'est compatible qu'avec des systèmes d'exploitation Linux ou MacOS, pour la version Windows, la branche "guillaume" est utilisable mais pratique d'utilisation.
Si vous voulez faire des modification et recompiler le jeu vous pouvez faire :
'''
gcc *.c -o game
./game.exe
'''
Il est aussi possible d'analyser les pertes de mémoire avec la commande:
'''
valgrind --leak-check=full ./game.exe
'''
## Les règles du Labyrinthe


#Stages: 

#definition des objets:<br>
  le plateau<br>
    X matrice de tuiles<br>
    X fonction de définition<br>
    X listes colones fixe <br>
    X listes ligne fixe<br>
  les tuiles<br>
    X gerer les murs / directions<br>
    X la proportion de tuiles (- T + L)<br>
    X tuiles fixe ou mobile<br>
  les joueurs<br>
    conditions de victoire (retourner a ca case apres toutes les cartes)<br>
    trouver toutes les case que l'on peux acceder<br>
    X déplacement du joueur:<br>
        X textuel(methode basic non opti)<br>
        X déplacement clé directionnel<br>
        déplacement au cli (opti)<br>
  les trésors<br>
    X afficher une seule cartes<br>
    X garder trace des cartes precedentes<br>
#definition des règles:<br>
 X pousser<br>X
 X règles de déplacement<br>
     X les tuiles fixes<br>X
      annuler action<br>
 #affichage:<br>
    X affichage ASCII<br>
    affichage Graph OpenGL SDL (opt)<br>
    
