#include "ServerService.h"

ServerService::ServerService(string filePath) {
    serverDAO = ServerDAO(filePath);
}

void ServerService::addServer(Server s) {


}

void ServerService::removeServer(Server s) {

}

vector<Server> ServerService::servers() {
    // TODO Exception handling
    return serverDAO.findAll();
}
