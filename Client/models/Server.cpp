#include "Server.h"

const std::string &Server::name () const
{
  return p_name;
}

const std::string &Server::address () const
{
  return p_address;
}

Server::Server (const std::string &p_address, const std::string &p_name) : p_address (p_address), p_name (p_name)
{}

Server::Server ()
{}

void Server::setAddress (const std::string &p_address)
{
  Server::p_address = p_address;
}

void Server::setName (const std::string &p_name)
{
  Server::p_name = p_name;
}
