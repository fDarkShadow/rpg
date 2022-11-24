# RPG

Il s'agit d'un petit RPG en un contre un.

## Comment jouer

Au lancement de la partie, les joueurs sont invités à choisir leur personnages et leur donner un nom.

Les personnages sont par la suite mis dans une file d'attaque, associés à un numéro de groupe.

Chaque tour de jeu, chaque joueur est invité à choisir ses actions.

Avant toute action, un résumé des joueurs est affiché. Chaque joueur est associé à un numéro.

Il y a ainsi un attaquant et une victime pour chaque action.

Un joueur pourra faire les choix suivants :
- choix de lancer une capacité ou non
- choix d'attaquer ou non

Lors d'une attaque, la victime à la capacité d'esquiver en fonction de son agilité.

Le groupe de joueur ayant réussi à vaincre ses adversaire est déclaré vainqueur.

## Architecture

Une architecture logicielle a été donnée à ce projet afin de faciliter la maintenance et l'ajout de nouvelles fonctionnalités.

### Personnage

Un personnage est une classe abstraite. Ceci permet de pouvoir choisir entre différents personnages.

Cette classe intègre un visiteur afin de faciliter les ajouts de fonctionnalités.

Vient ensuite une classe d'aide profitant du CRTP afin de communaliser certaines méthodes sans pour autant faire appel à la table virtuelle.

Puis viennent les implémentations, permettants de définir les caractéristiques du personnage ainsi implémenté.

Un visiteur est implémenté ainsi qu'une fonction d'aide pour son utilisation afin de retourner le nom de la classe du personnage.

### Arme

Une arme dérive plus simplement d'une classe abstraite.

De la même manière, des visiteurs sont implémentés.

### Protection

Une protection (bouclier, armures, etc.) dérive d'une classe CRTP elle-même dérivant d'une classe abstraite.

Des visiteurs sont implémentés.

### Capacité

Une capacité dérive d'une classe abstraite.

Des visiteurs sont implémentés.

Les applications des capacités sont faites dans un visiteur, une remise à zéro est faite lorsque le visiteur est détruit.

### Jet de dé

Certaines actions ont certaines chances de réussir ou non. Ceci est basé sur un pourcentage de chances de réussite.

Pour ce faire, un objet de tirage pseudo-random, basé sur l'entropie du système et suivant une distribution uniforme est mis en place. A chaque appel, un tirage d'entier entre 1 et 100 est effectué. Si ce nombre est inférieur ou égal aux chances de succès, alors le tirage de dés est réussi.