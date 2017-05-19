#include "stdafx.h"
#include "ServerService.h"
#include <iostream>

using namespace std;

//typedef std::pair<std::string, std::string> pairServer;


void ServerService::UpdateFromMulticast()
{
	// R�cup�ration des serveurs par multicast, en �coutant pendant 10 secondes + Exception eventuelle
	std::map<std::string, std::string> foundServers;
	// CODE TODO (Julia)  : voir Slack 

	// Lecture des serveurs d�j� dans la BD + Exception eventuelle
	std::map<std::string, std::string> fileServers;
	// try ... 
	fileServers = GetServers();
	// ... catch 

	// Les serveurs qui ne sont pas d�j� dans la BD et qui sont r�cup�r�s sont ajout�s � la base 
	// + Exception eventuelle
	for(std::map<std::string, std::string>::iterator it = foundServers.begin(); it!= foundServers.end(); it++)
	{
		if(fileServers.find(it->first)==fileServers.end())
		{
			// Insertion de *it dans la BD + Exception eventuelle (impossible d'ins�rer machin)
			Server s(it->first, it->second);
			AddServer(s);
		}
	}
	
}

void ServerService::AddServer(Server s)
{
	// �criture dans la BD + Exception eventuelle
	//  = appel du DAO = TODO
}

void ServerService::RemoveServer(Server s)
{
	// �criture dans la BD + Exception eventuelle
	//  = appel du DAO = TODO
}

std::map<std::string, std::string> ServerService::GetServers()
// la base de donn�es choisie est SQLite
{
	std::map<std::string, std::string> servers;
	// lecture des serveurs stock�s depuis la BD
	//  = appel du DAO = TODO
	// try ...
		
	// catch...

	return servers;
}

ServerService::ServerService()
{

}


ServerService::~ServerService()
{

}
