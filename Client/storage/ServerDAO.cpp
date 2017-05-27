#include "ServerDAO.h"

ServerDAO::ServerDAO(string dbName) {
//  sqlite3_open(dbName, &db);
}

ServerDAO::~ServerDAO() {

}

std::vector<Server> ServerDAO::findAll() {
    /* std::string sqlSelectStr = "SELECT * FROM Server;";
     const char *sqlSelect = sqlSelectStr.c_str();
     std::list<Server> servers;
     int code;
     char **results = NULL;
     int rows, columns;
     char *error;

     code = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

     if (code != 0) {
       std::cerr << "Error executing SQLite3 query (findAll): " << sqlite3_errmsg(db) << std::endl;
       sqlite3_free(error);
     } else {
       for (int i = 0; i < rows; i++) {
         std::string adresse = results[i + columns];
         std::string nom = results[i + 1 + columns];
         Server server;
         server.setAddress(adresse);
         server.setName(nom);
         servers.push_back(server);
       }
     }

     return servers;*/
    return std::vector<Server>();
}

Server ServerDAO::findByName(std::string nameServer) {
    /*std::string sqlSelectStr = "SELECT * FROM Server WHERE name='" + nameServer + "';";
    const char *sqlSelect = sqlSelectStr.c_str();
    int code;
    char **results = NULL;
    int rows, columns;
    char *error;

    code = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

    Server server;

    if (code != 0) {
      std::cerr << "Error executing SQLite3 query (findByName): " << sqlite3_errmsg(db) << std::endl;
      sqlite3_free(error);
    } else {
      std::string adresse = results[0 + columns];
      std::string nom = results[1 + columns];
      server.setAddress(adresse);
      server.setName(nom);
    }

    return server;*/

    return Server();
}