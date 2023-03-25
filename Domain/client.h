#pragma once
#include <string>
#include <vector>
#include "auto.h"
#define NULL_CLIENT Client("");
#define NULL_STRING ""
using namespace std;
using namespace electric_auto;

namespace client {
    class Client {
    private :
        std::vector<Auto> client_favorites;
        string name;
    public:
        Client(string name);
        // Lieblingsauto hinzufuegen
        void add_favorite(Auto car);
        std::vector<Auto>* get_favorite();
        string get_name();
    }
;}