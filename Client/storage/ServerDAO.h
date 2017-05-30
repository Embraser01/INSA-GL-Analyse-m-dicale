#ifndef MEDANALYSIS_CLIENT_SERVERDAO_H
#define MEDANALYSIS_CLIENT_SERVERDAO_H

#include <vector>
#include <string>
#include <iostream>
#include "../models/Server.h"

using std::string;
using std::vector;

class ServerDAO {
public:

    ServerDAO(string dbName = "Server.db"); // TODO MOVE DEFAULT NAME

    ~ServerDAO();

    vector<Server> findAll();

    Server findByName(string nameServer);

private:
};

#endif //MEDANALYSIS_CLIENT_SERVERDAO_H
