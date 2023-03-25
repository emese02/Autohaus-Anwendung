#include "client.h"
using namespace client;


void Client::add_favorite(Auto car)
{
    this->client_favorites.push_back(car);
}

std::vector<Auto>* Client::get_favorite()
{
    return &this->client_favorites;
}

Client::Client(string _name)
{
    this->name = _name;
}

string Client::get_name()
{
    return this->name;
}

