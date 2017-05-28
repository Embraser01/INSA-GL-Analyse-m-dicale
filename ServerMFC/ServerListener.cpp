// ServerListener.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ServerMFC.h"
#include "ServerListener.h"


// ServerListener

void ServerListener::OnAccept(int nErrorCode)
{
	ClientSocket* pSockClient = new ClientSocket();

	// accept onnection

	bool bResult = Accept(*pSockClient);

	CString strPeerName;
	UINT uiPort;
	pSockClient->GetPeerName(strPeerName, uiPort);

	CAsyncSocket::OnAccept(nErrorCode);
}

ServerListener::ServerListener()
{
}

ServerListener::~ServerListener()
{
}


// Fonctions membres ServerListener
