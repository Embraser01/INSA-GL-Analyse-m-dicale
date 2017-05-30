// ClientSocket.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "ServerMFC.h"
#include "ClientSocket.h"


// ClientSocket

#define BUFF_LEN 2048

void ClientSocket::OnReceive(int nErrorCode)
{

	// TODO OnReceive

	char szBuff[BUFF_LEN];
	char szResponse[BUFF_LEN];


	int nReceivedSize = Receive(szBuff, BUFF_LEN);
	TRACE1("Received: %d bytes \n", nReceivedSize);

	if (nReceivedSize <= 0)
	{
		TRACE1("Socket receive error: %d\n", GetLastError());
		return;
	}

	szBuff[nReceivedSize] = '\0';

	TRACE(szBuff);

	std::string strResponse = "Hello World !";
	int nSendBytes = 0;
	const char* pszBuff = strResponse.c_str();
	int nResponseSize = strResponse.length();
	while (nSendBytes < nResponseSize)
	{
		nSendBytes = Send(pszBuff, nResponseSize);
		nResponseSize = nResponseSize - nSendBytes;
		pszBuff = pszBuff + nSendBytes;
	}

	CAsyncSocket::OnReceive(nErrorCode);
}



ClientSocket::~ClientSocket()
{
}


// Fonctions membres ClientSocket
