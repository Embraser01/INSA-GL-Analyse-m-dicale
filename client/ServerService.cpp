#include "stdafx.h"
#include "ServerService.h"
#include <iostream>

using namespace std;

//typedef std::pair<std::string, std::string> pairServer;


void ServerService::updateFromMulticast()
{
	// R�cup�ration des serveurs par multicast, en �coutant pendant 10 secondes + Exception eventuelle
	std::map<std::string, std::string> foundServers;
	// CODE TODO (Julia)  : voir Slack

	// Lecture des serveurs d�j� dans la BD + Exception eventuelle
	std::map<std::string, std::string> fileServers;
	// try ... 
	fileServers = getServers();
	// ... catch 

	// Les serveurs qui ne sont pas d�j� dans la BD et qui sont r�cup�r�s sont ajout�s � la base 
	// + Exception eventuelle
	for(std::map<std::string, std::string>::iterator it = foundServers.begin(); it!= foundServers.end(); it++)
	{
		if(fileServers.find(it->first)==fileServers.end())
		{
			// Insertion de *it dans la BD + Exception eventuelle (impossible d'ins�rer machin)
			Server s(it->first, it->second);
			addServer(s);
		}
	}
	
}

void ServerService::addServer(Server s)
{
	// �criture dans la BD + Exception eventuelle
	//  = appel du DAO = TODO
}

void ServerService::removeServer(Server s)
{
	// �criture dans la BD + Exception eventuelle
	//  = appel du DAO = TODO
}

std::map<std::string, std::string> ServerService::getServers()
// la base de donn�es choisie est SQLite
{
	// lecture des serveurs stock�s depuis la BD
	//  = appel du DAO = TODO

}

ServerService::ServerService()
{

}


ServerService::~ServerService()
{

}
