#pragma once
#include "../Repository/auto_repository.h"
using  namespace electric_auto;
using namespace repo;

namespace controller {
class Controller_In_Memory
{
private:
     In_Memory_Repository auto_repo;
public:
    Controller_In_Memory(In_Memory_Repository &repository);
    // Auto hinzufuegen
    void add_car(Auto electric_auto);
    // Auto loeschen
    bool delete_car(string auto_id);
    void modify_car(string id, Auto &modified_car);
    // nach Autos suchen (Modell/Marke)
    std::vector<Auto> find_cars_brand (string brand);
    std::vector<Auto> find_cars_model (string model);
    // Autoliste nach dem Alter/Kilometer filtern
    std::vector<Auto> filter_cars_age (int age);
    std::vector<Auto> filter_cars_km (float km);
    // nach Preis sortieren
    std::vector<Auto> sort_by_price ();
    vector<Auto> get_all();
    void add_client(Client &client);
    std::vector<Client>* get_clients();
    Auto identify_car (string id);
};


class Controller_CSV
    {
    private:
//    E auto_repo;
        CSV_File_Repository auto_repo;
    public:
//    Controller(E &repository);
        Controller_CSV(CSV_File_Repository &repository);
        // Auto hinzufuegen
        void add_car(Auto electric_auto);
        // Auto loeschen
        bool delete_car(string auto_id);
        void modify_car(string id, Auto &modified_car);
        // nach Autos suchen (Modell/Marke)
        std::vector<Auto> find_cars_brand (string brand);
        std::vector<Auto> find_cars_model (string model);
        // Autoliste nach dem Alter/Kilometer filtern
        std::vector<Auto> filter_cars_age (int age);
        std::vector<Auto> filter_cars_km (float km);
        // nach Preis sortieren
        std::vector<Auto> sort_by_price ();
        vector<Auto> get_all();
        void add_client(Client &client);
        std::vector<Client>* get_clients();
        Auto identify_car (string id);
    };
;}