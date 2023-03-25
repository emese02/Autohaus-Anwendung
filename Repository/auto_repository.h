#pragma once
#include <vector>
#include "../Domain/auto.h"
#include "../Domain/client.h"
using namespace electric_auto;
using namespace client;

namespace repo {
    class CrudRepository {
    public:
        virtual void initialize_repository() = 0;
        // Auto hinzufuegen
        virtual void add_car(Auto electric_auto) = 0;
        // Product loeschen
        virtual void delete_car(string id) = 0;
        virtual  std::vector<Auto>* get_cars() = 0;
        virtual  std::vector<Auto> copy_cars() = 0;
        virtual std::vector<Client> *get_clients() = 0;
    };
    // In- MEMoryCSV-File-Repository

class In_Memory_Repository: CrudRepository {
private:
    std::vector<Auto> cars;
    std::vector<Client> clients;
public:
    // Repository initialisieren
    void initialize_repository();
    // Auto hinzufuegen
    void add_car(Auto electric_auto);
    // Product loeschen
    void delete_car(string auto_id);
    // Lieblingsauto hinzufuegen
    void add_favorite(Auto electric_auto);
    std::vector<Auto> get_favorite();
    std::vector<Auto>* get_cars();
    std::vector<Auto> copy_cars();
    void add_client(Client &client);
    std::vector<Client> *get_clients();
};

    class CSV_File_Repository : CrudRepository{
    private:
        std::vector<Auto> cars;
        std::vector<Client> clients;
    public:
        // Repository initialisieren
        void initialize_repository();
        // Auto hinzufuegen
        void add_car(Auto electric_auto);
        // Product loeschen
        void delete_car(string auto_id);
        std::vector<Auto>* get_cars();
        std::vector<Auto> copy_cars();
        void write_to_file();
        void add_client(Client &client);
        std::vector<Client> *get_clients();
    }
    ;}