# Projet Jeu de Plateau IMT Nord Europe
## Introduction
Ce projet de développement d'un jeu de plateau en C fonctionnel sur terminal a été réalisé par Guillaume FAURE, Alexandre DORCIVAL et William NGUYEN dans le cadre de notre cursus à l'IMT.<br>
Nous avons décidé de réaliser le jeu "Le Labyrinthe", à la fois faisable sur terminal, très intéressant et amusant.<br>
### Image du jeu de société labyrinthe original:<br><br>
![alt text](https://www.regle-du-jeu.fr/wp-content/uploads/2020/11/regles-du-jeu-Labyrinthe.jpg "Jeu du labyrinthe")
<br>
## Comment lancer le jeu
Pour lancer le jeu, le simple fichier game.exe lance le jeu sur le terminal:<br>
* Pour Linux et MacOS : branche main
* Pour Windows : branche Windows

Si vous voulez faire des modification et recompiler le jeu vous pouvez faire :
```
//Pour Windows

gcc *.c -o game
./game.exe

//Pour Unix

make
```
Il est aussi possible d'analyser les pertes de mémoire avec la commande:
```
valgrind --leak-check=full ./game.exe
```
Le jeu est afficher à l'aide de la table ASCII.
## Les règles du Labyrinthe
### Le jeu se joue:
* de 1 à 4 joueurs
* de 1 à 6 trésors par personne
### Comment jouer au labyrinthe
Le labyrinthe est un jeu qui se joue en tour par tour, c'est le premier joueur qui commence à jouer puis dans l'ordre jusqu'à revenir au premier joueur. Chaque joueur a un objectif de trésor (les trésors sont symboliser par des lettres capitales de A à Z) et son but est de tous les récupérer avant de revenir à sa case de départ.<br>
Pour cela, le tour de chaque joueur se déroule en 2 phases, le placement de la tuile avec le déplacement d'une colonne ou d'une ligne et le déplacement du joueur :<br>
* Pour le placement de la tuile, le joueur peut la déplacer avec les flèches directionneles et la tourner avec "a" et "z" (pour la version linux) quand le placement lui convient et qu'il souhaite déplacer la colonne ou la ligne sur laquelle la tuile a été placé, le joueur appuie sur "entrée". Une colonne et une ligne sur deux est déplacable, les colonnes et lignes fixes sont symbolisés par les tuiles plus foncées.

ATTENTION: Si un joueur est expulsé hors du plateau lors d’un mouvement d’une colonne ou d’une rangée il est replacé à l’opposé de celle-ci. Cependant, ceci ne constitue pas un mouvement du pion.
* Pour le déplacement du joueur, le joueur symbolisé par la première lettre de son pseudo peut se déplacer à l'aide des fléches directionnelles sur les chemins possibles et appuyer sur "entrée" quand il est satisfait de son déplacement.
<br>
Pour remporter une partie au Labyrinthe, le joueur doit avoir découvert tous ses trésors et doit revenir à son point de départ. Une fois de retour à son point de départ il est déclaré vainqueur et la partie est terminée.

    
