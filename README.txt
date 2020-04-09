Projet: R U Hungry

Nous avons choisi d'impl�menter l'interface utilisateur sur Qt parce qu'on poss�dait d�j� des connaissances avec cette biblioth�que et C++.
L'interface impl�ment�e correspond � la premi�re version que nous avions mis en place avec une page principale, une page pour les plats favoris, les plats bannis et enfin une page pour recharger son compte.
Nous avons pu mettre en place la plupart des fonctionnalit�es comme le fait de recharger son compte, ajouter des plats favoris, en bannir d'autres. Il est aussi possible de mettre un budget maximum pour son repas, la suggestion de plats en tiendra compte.
Nous avons aussi mis en place un syst�me de tri des plats par prix ou calories (d�croissant et croissant). Enfin, nous avons ajout� la possibilit� de filtrer les plats suivant certaines caract�ristiques comme le fait que la plat soit halal, v�g�tarien, sans gluten ou sans allerg�nes communs.
Enfin, il est aussi possible d'ajouter et retirer des plats � sa commande. Nous avons ajout� la possibilit� d'obtenir plus d'informations sur un plat via la pr�sence d'un bouton. Nous n'avons cependant pas mis en place de syst�me de drag and drop pour ajouter des plats � sa commande.
Des messages d'avertissement ont �t� mis en place en pr�vention de certaines actions ayant un impact sur la commande du client.
Enfin, il est possible d'augmenter ou de diminuer la quantit� d'un plat ou d'accompagnement dans sa commande.


Le code a �t� organis� de la mni�re suivante:

Les plats et leur vues poss�dent chacun une classe.
Chaque fen�tre de l'application poss�de une classe diff�rente.
Nous avons aussi une classe pour l'utilisateur.
L'ensemble des plats est d�crit dans un fichier json, tout comme l'ensemble des utilisateurs.


Lien du Github de projet: https://github.com/GD-Github/R-U-Hungry-


