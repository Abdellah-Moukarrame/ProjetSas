ProjetSas

Description

Ce projet est une application en langage C qui permet de gérer les avions d’un aéroport.
L’utilisateur peut ajouter, modifier, supprimer, rechercher, trier et afficher des avions, ainsi que consulter différentes statistiques liées aux avions.

Fonctionnalités

Ajouter un avion avec :

Module (nom)

Capacité

Statut (en vol, disponible, en maintenance)


Modifier un avion existant

Supprimer un avion par son ID

Afficher tous les avions

Rechercher un avion par ID ou par module

Trier les avions par capacité ou par module

Statistiques :

Nombre total des avions

Nombre d’avions par statut

Avion avec la plus grande capacité

Avion avec la plus petite capacité

Pourcentage d’avions disponibles

Capacité totale des avions



Structure du projet

Projetsas.c → Code source du programme

README.md → Documentation du projet


Compilation & Exécution

Pour compiler et exécuter le projet :

gcc Projetsas.c -o projetsas  
./projetsas  

======================== MENU ====================  
 ||  1 - Pour ajouter un avion appuyez sur     1 ||  
 ||  2 - Pour modifier un avion appuyez sur    2 ||  
 ||  3 - Pour supprimer un avion appuyez sur   3 ||  
 ||  4 - Pour afficher les avions appuyez sur  4 ||  
 ||  5 - Pour rechercher un avion appuyez sur  5 ||  
 ||  6 - Pour trier les avions appuyez sur     6 ||  
 ||  7 - Pour statistiques appuyez sur         7 ||  
==================================================  


