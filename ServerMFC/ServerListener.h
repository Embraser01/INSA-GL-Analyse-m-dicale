#pragma once

// Cible de la commande ServerListener

class ServerListener : public CAsyncSocket
{
protected:
	void OnAccept(int nErrorCode) override;
public:
	ServerListener();
	virtual ~ServerListener();
};


