Projet: R U Hungry

Nous avons choisi d'implémenter l'interface utilisateur sur Qt parce qu'on possédait déjà des connaissances avec cette bibliothèque et C++.
L'interface implémentée correspond à la première version que nous avions mis en place avec une page principale, une page pour les plats favoris, les plats bannis et enfin une page pour recharger son compte.
Nous avons pu mettre en place la plupart des fonctionnalitées comme le fait de recharger son compte, ajouter des plats favoris, en bannir d'autres. Il est aussi possible de mettre un budget maximum pour son repas, la suggestion de plats en tiendra compte.
Nous avons aussi mis en place un système de tri des plats par prix ou calories (décroissant et croissant). Enfin, nous avons ajouté la possibilité de filtrer les plats suivant certaines caractéristiques comme le fait que la plat soit halal, végétarien, sans gluten ou sans allergènes communs.
Enfin, il est aussi possible d'ajouter et retirer des plats à sa commande. Nous avons ajouté la possibilité d'obtenir plus d'informations sur un plat via la présence d'un bouton. Nous n'avons cependant pas mis en place de système de drag and drop pour ajouter des plats à sa commande.
Des messages d'avertissement ont été mis en place en prévention de certaines actions ayant un impact sur la commande du client.
Enfin, il est possible d'augmenter ou de diminuer la quantité d'un plat ou d'accompagnement dans sa commande.


Le code a été organisé de la mnière suivante:

Les plats et leur vues possèdent chacun une classe.
Chaque fenêtre de l'application possède une classe différente.
Nous avons aussi une classe pour l'utilisateur.
L'ensemble des plats est décrit dans un fichier json, tout comme l'ensemble des utilisateurs.


Lien du Github de projet: https://github.com/GD-Github/R-U-Hungry-


