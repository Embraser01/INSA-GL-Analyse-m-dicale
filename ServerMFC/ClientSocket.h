#pragma once
#include "controllers/AllController.h"
#include "controllers/OneController.h"
#include "controllers/ListController.h"

// Cible de la commande ClientSocket

class ClientSocket : public CAsyncSocket
{
private:
	AllController allController;
	OneController oneController;
	ListController listController;

protected:
	void OnReceive(int nErrorCode) override;
public:

	ClientSocket(const AllController& all_controller, const OneController& one_controller, const ListController& list_controller)
		: allController(all_controller),
		  oneController(one_controller),
		  listController(list_controller)
	{
	}

	virtual ~ClientSocket();
};


