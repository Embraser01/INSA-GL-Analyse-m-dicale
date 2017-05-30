# Projet G�nie Logiciel - Analyse m�dicale

## Presentation
  Ceci est un projet fait en G�nie Logiciel 3IF � l'INSA de Lyon. Le sujet est disponible [ici](docs/sujet.pdf)
  Auteurs :
*    Marc-Antoine FERNANDES
*    Julia LU DAC
*    Lucas ONO
*    Tianhao WU
*    Ye YUAN

-------------------------------------------------------------------------------

## Utiliser l'application

### Serveur

L'application serveur permet d'�valuer les maladies possibles qui peuvent �tre incluses dans un g�nome. 

##### Fichiers utilis�s

Il s'appuie sur un fichier contenant un dictionnaire des maladies qu'il est capable d'�valuer. 

##### D�marrage du serveur

Lorsque l'interface est lanc�e, un num�ro de port sur lequel doit d�marrer le serveur est demand�, 
ainsi que le nom du fichier contenant le dictionnaire de maladies. C'est le port sur lequel sera lanc�e l'application serveur. 
Ces param�tres choisis, il suffit de cliquer sur le bouton "Start Server", qui d�marrera le serveur si tout fonctionne.
Un serveur en ex�cution est capable de r�pondre � des requ�tes de client arrivant sur son adresse IP et son num�ro de port. 
Ces requ�tes doivent concerner l'une des trois fonctions : 

* Fournir la liste des maladies du dictionnaire

* Indiquer si un risque de maladie est pr�sente dans un g�nome

* Fournir la liste des risques de maladie dans un g�nome


##### Diffusion de l'adresse IP et du port via multicast

Un bouton "Start Multicast" permet au serveur d'envoyer � intervalles r�guliers (2.5 s) son adresse IP et
le port de connexion sur une adresse multicast, pour en informer les clients. L'adresse IP est 225.6.7.8 et le port est 5678.
Le bouton "Stop Multicast" permet d'arr�ter ces envois.


##### Quitter
Un bouton permet de quitter l'application � tout moment.


##### Erreurs possibles 
Lorsque le fichier du dictionnaire des maladies ou que le port sur lequel vous voulez d�marrer est d�j� occup�, le serveur ne d�marre pas 
et vous devrez sp�cifier une autre valeur.


--------

### Client

L'application cliente permet d'obtenir des �valuations des maladies � risque sur des g�nomes de patient.
Pour cela, elle envoie des requ�tes � des serveurs qui lui envoient la r�ponse.


##### Evaluer une analyse m�dicale


C'est la fonction primaire de l'application. Lorsque l'on clique sur ce bouton, une fen�tre s'ouvre avec 3 boutons. Chaque bouton permet d'envoyer une requ�te � un ou plusieurs serveurs :

* Get diseases : Vous recevrez la liste des maladies � risque que le serveur cible est capable d'�valuer.

* Evaluate All Disease : Le g�nome � �valuer est demand�. Vous recevrez la liste de l'ensemble des 
maladies � risque que les serveurs r�pertori�s ont trouv� sur ce g�nome.

* Evaluate One Disease : Le g�nome � �valuer et la maladie � chercher sur ce g�nome sont demand�s. 
Vous recevrez une r�ponse "Yes" ou "No" lors de la pr�sence ou non de la maladie sur le g�nome.

##### Gestion des serveurs enregistr�s
Une fen�tre s'ouvre. 
* Update Servers List : met � jour les serveurs r�pertori�s dans la base de donn�es. 

* Add Server : permet d'ajouter manuellement un serveur dans la base de donn�es. 
Son adresse IP et son nom sont demand�s. 

* Remove Server : permet d'enlever manuellement un serveur r�pertori� de la base de donn�es. 
Son adresse IP est demand�e. 


##### Quitter
Un bouton permet de fermer l'application � tout moment.

##### Erreurs possibles 
* Impossible de lire le fichier contenant le g�nome
* Impossible de manipuler la base de donn�es des serveurs r�pertori�s
* Erreur de r�seau 


-------------------------------------------------------------------------------

## Contribuer

### D�pendance

* [Visual Studio 2017+](https://www.visualstudio.com/)

### Configurer l'environnement

Pour ouvrir le projet, il suffit de cloner 
le projet et d'ouvrir la solution sur Visual Studio (VS 2017+)


### Lancer les tests

Les tests utilisent la librairie [_Catch_](https://github.com/philsquared/Catch).


Pour que les tests fonctionnent, il faut configurer les projets pour 
que le dossier de travail soit la racine de la solution. 

Pour cela, il suffit de faire : clic droit sur _ServerTests_ > Onglet
_Deboggage_ > dans _Dossier de travail_ remplacer `$(ProjectDir)` par `$(SolutionDir)`.

Refaire la m�me chose pour _ClientTests_

Maintenant pour lancer les tests, il faut soit lancer l'executable g�n�r� par VS,
soit utiliser l'extension [_Resharper C++_](https://www.jetbrains.com/resharper-cpp/) 
qui offre une interface de test. Dans ce cas l�, il faut lancer les tests en faisant 
Clic droit sur le projet > Run Unit Test
