# PSU_2014_zappy


!-------- Serveur --------!

Dernier follow-up, problème majeur --> gestion du temps, et de la synchronisation des éxécutions.
Il fallait trouver un moyen de comptabiliser le temps sous forme de cycles, pour temporiser les actions de chaque
joueur, sans utiliser de threads.
Maintenant : chaque joueur possède son propre fil d'éxecution, avec sous forme de stack, avec pour chaque action demandée
le nombre de cycles à effectuer avant d'agir. Quand un joueur fait une requete au serveur, sauvegarde la commande dans la stack d'executions
du joueur. Elle sera executée N cycles après. Si par hasard une commande est trop longue, le serveur rattrapera le temps perdu en
passant plusieurs tours de cycle d'un coup. Le temps est géré grâce aux appels system get_time_of_day() et  ses fonctions de comparaison (timersub()).
Le temps est stocké dans les struct timeval evidemment.

Le fonctionnement du serveur à été revu pour interpréter les commandes :
- D'un client qui vient de ce connecter (client standby).
- D'un client qui est reconnu comme joueur, (accès au commandes d'un joueur)
- D'un client graphic, (accès aux commandes graphiques)

Car avant on ne reconnaissait pas un client graphique, même si la partie joueur était bien avancée.
De nombreux patchs apportés, au niveaux d'erreurs Valgrind entre autre, et de la compilation avec les flags.
Correctifs apportés pour la commande 'voir'

Au niveau des cmmandes réalisées : Casiment toutes, sauf Broadcast et Incantation et Fork.
Reste à faire : Ponte des oeufs.

Questions : 

--> Catch control-C pour fermet les sockets ? (O/n?)
--> Catch control-D ferme socket client ? (O/n?)

Faut il se fier au serveur de test ? ex : repond ko pour mauvaise commande, façon bizarre de répondre à un 'voir'...

!-------- IA --------!

Amélioration de l'IA (cf schéma + Cedric explique nous tout wsh)
Peut maintenant se connecter au serveur de test, monter des niveaux...

!-------- Caméra --------!

Implémentation de tout les objects, possibilité de cliquer sur une case de la map : affiche les infos d'un joueur.
Possibilité de déplacer la caméra.
Reçois les commandes de base (cf RFC) destinées à un client graphique


