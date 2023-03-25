#include "../Controller/auto_controller.h"
using namespace  controller;

namespace ui {
    class UI
    {
    public:
        // Das Menu vom Benutzer zeigen
        void show_menu_client();
        // Das Menu vom Manager zeigen
        void show_menu_manager();
        void read_in_id(string &id);
        // ein Auto einlesen
        Auto read_in_car();
        // Liste von Autos anzeigen
        void show_cars(vector<Auto> cars);
        void show_clients(vector<Client> clients);
    };

    class UI_In_Memory: public UI {
    private:
        Controller_In_Memory auto_controller;
    public:
        UI_In_Memory(Controller_In_Memory _auto_controller);
        void get_user_choice();
    };

    class UI_CSV: public  UI
    {
    private:
        Controller_CSV auto_controller;
    public:
        UI_CSV(Controller_CSV _auto_controller);
        void get_user_choice();
    };
}