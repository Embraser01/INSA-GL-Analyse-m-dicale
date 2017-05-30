#ifndef MEDANALYSIS_CLIENT_SERVERSERVICE_H
#define MEDANALYSIS_CLIENT_SERVERSERVICE_H

#include <vector>
#include <string>
#include "../models/Disease.h"
#include "../models/Genome.h"
#include "../storage/ServerDAO.h"

using std::vector;
using std::string;
using std::pair;


class ServerService {

public:

    ServerService(string filePath);

    void addServer(Server s);

    void removeServer(Server s);

    vector<Server> servers();


private:
    ServerDAO serverDAO;

};

#endif //MEDANALYSIS_CLIENT_SERVERSERVICE_H