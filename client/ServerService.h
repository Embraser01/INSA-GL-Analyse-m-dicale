#pragma once
#pragma once
#include <map>
#include "Server.h"



class ServerService
{
public:
	void updateFromMulticast();
	// R�cup�re tous les serveurs d�tect�s par multicast, en �coutant pendant 10 secondes, puis les ajoute 
	// �ventuellement � la base de donn�es

	void addServer(Server s);
	// Ajoute le serveur s � la base de donn�es 
	// C'est une m�thode manuelle, que l'user peut utiliser,
	// mais aussi utilis�e par la fonctionnalit� de mise � jour du serveur

	void removeServer(Server s);
	// C'est une m�thode manuelle, que l'user peut utiliser

	std::map<std::string, std::string> getServers();
	// Retourne les serveurs stock�s dans la base de donn�es 
	// Dans un stockage, un serveur est repr�sent� par une paire de strings : 
	// son adresse IP(unique) et son nom 

	ServerService();
	~ServerService();

};

