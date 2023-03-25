#include "auto_ui.h"
#include <iostream>
using namespace std;
using namespace electric_auto;
using namespace controller;
using namespace repo;
using namespace ui;

// Konstruktor
UI_In_Memory::UI_In_Memory(Controller_In_Memory _auto_controller) : auto_controller(_auto_controller){};
UI_CSV::UI_CSV(Controller_CSV _auto_controller) :auto_controller(_auto_controller){};

// Menu Optionen
void UI::show_menu_manager()
{
    cout<<"1. Add car\n";
    cout<<"2. Delete car\n";
    cout<<"3. Modify car\n";
    cout<<"4. Search car by model\n";
    cout<<"5. Search car by brand\n";
    cout<<"6. Filter car by age\n";
    cout<<"7. Filter car by kilometer\n";
    cout<<"8. Sort by price\n";
    cout<<"9. Show cars\n";
    cout<<"10. Show clients\n";
    cout<<"11. Exit\n";
}

void UI::show_menu_client()
{
    cout<<"1. Search car by model\n";
    cout<<"2. Search car by brand\n";
    cout<<"3. Filter car by age\n";
    cout<<"4. Filter car by kilometer\n";
    cout<<"5. Sort by price\n";
    cout<<"6. Add to favorites\n";
    cout<<"7. Show favorites\n";
    cout<<"8. Show cars\n";
    cout<<"9. Show clients\n";
    cout<<"10. Exit\n";
}

void UI_In_Memory::get_user_choice() {
    cout << "Choose an option: \n";
    cout << "1. Client \n";
    cout << "2. Manager \n";
    int choice1, choice2;
    Auto car;
    string model, brand, id, name;
    int age;
    bool deleted;
    float km;
    cin >> choice1;
    while (choice1 == 1 || choice1 == 2) {
        if (choice1 == 2) {
            UI::show_menu_manager();
            cin >> choice2;
            while (choice2 != 11) {
                switch (choice2) {
                    case 1:
                        car = UI::read_in_car();
                        this->auto_controller.add_car(car);
                        break;
                    case 2:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        deleted = this->auto_controller.delete_car(id);
                        if (!deleted)
                            cout<<"There was no car with the given data!\n";
                        break;
                    case 3:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        cout<<"Enter new data!\n";
                        car = UI::read_in_car();
                        this->auto_controller.modify_car(id, car);
                        break;
                    case 4:
                        cout << "\nModel: ";
                        cin >> model;
                        UI::show_cars(this->auto_controller.find_cars_model(model));
                    case 5:
                        cout << "\nBrand: ";
                        cin >> brand;
                        UI::show_cars(this->auto_controller.find_cars_brand(brand));
                        break;
                    case 6:
                        cin >> age;
                        UI::show_cars(this->auto_controller.filter_cars_age(age));
                        break;
                    case 7:
                        cout << "\nKm: ";
                        cin >> km;
                        UI::show_cars(this->auto_controller.filter_cars_km(km));
                        break;
                    case 8:
                        UI::show_cars(this->auto_controller.sort_by_price());
                        break;
                    case 9:
                        UI::show_cars(this->auto_controller.get_all());
                        break;
                    case 10:
                        UI::show_clients(*this->auto_controller.get_clients());
                        break;
                    default:
                        cout<<"No such option\n!";
                }
                UI::show_menu_manager();
                cin >> choice2;
            }
        } else if (choice1 == 1){
            //
            cout<<"\nName: ";
            cin >> name;
            Client actual_client(name);
            this->auto_controller.add_client(actual_client);
            UI::show_menu_client();
            cin >> choice2;
            while (choice2 != 10) {
                switch (choice2) {
                    case 1:
                        cout << "\nModel:";
                        cin >> model;
                        UI::show_cars(this->auto_controller.find_cars_model(model));
                    case 2:
                        cout <<" \nBrand: ";
                        cin >> brand;
                        UI::show_cars(this->auto_controller.find_cars_brand(brand));
                        break;
                    case 3:
                        cout << "\nAge: ";
                        cin >> age;
                        UI::show_cars(this->auto_controller.filter_cars_age(age));
                        break;
                    case 4:
                        cout << "\nKm: ";
                        cin >> km;
                        UI::show_cars(this->auto_controller.filter_cars_km(km));
                        break;
                    case 5:
                        UI::show_cars(this->auto_controller.sort_by_price());
                        break;
                    case 6:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        car = this->auto_controller.identify_car(id);
                        if (car.get_model()!="")
                            actual_client.add_favorite(car);
                        else
                            cout<<"We don't have this car!\n";
                        break;
                    case 7:
                        UI::show_cars(*actual_client.get_favorite());
                        break;
                    case 8:
                        UI::show_cars(this->auto_controller.get_all());
                        break;
                    case 9:
                        UI::show_clients(*this->auto_controller.get_clients());
                    default:
                        cout << "No such an option";
                }
                UI::show_menu_client();
                cin >> choice2;
            }
        }
        cout << "Choose an option: \n";
        cout << "1. Client \n";
        cout << "2. Manager \n";
        cin >> choice1;
    }
}

void UI_CSV::get_user_choice() {
    cout << "Choose an option: \n";
    cout << "1. Client \n";
    cout << "2. Manager \n";
    int choice1, choice2;
    Auto car;
    string model, brand, id, name;
    int age;
    bool deleted;
    float km;
    cin >> choice1;
    while (choice1 == 1 || choice1 == 2) {
        if (choice1 == 2) {
            UI::show_menu_manager();
            cin >> choice2;
            while (choice2 != 11) {
                switch (choice2) {
                    case 1:
                        car = UI::read_in_car();
                        this->auto_controller.add_car(car);
                        break;
                    case 2:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        deleted = this->auto_controller.delete_car(id);
                        if (!deleted)
                            cout<<"There was no car with the given data!\n";
                        break;
                    case 3:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        cout<<"Enter new data!\n";
                        car = UI::read_in_car();
                        this->auto_controller.modify_car(id, car);
                        break;
                    case 4:
                        cout << "\nModel: ";
                        cin >> model;
                        UI::show_cars(this->auto_controller.find_cars_model(model));
                    case 5:
                        cout << "\nBrand: ";
                        cin >> brand;
                        UI::show_cars(this->auto_controller.find_cars_brand(brand));
                        break;
                    case 6:
                        cin >> age;
                        UI::show_cars(this->auto_controller.filter_cars_age(age));
                        break;
                    case 7:
                        cout << "\nKm: ";
                        cin >> km;
                        UI::show_cars(this->auto_controller.filter_cars_km(km));
                        break;
                    case 8:
                        UI::show_cars(this->auto_controller.sort_by_price());
                        break;
                    case 9:
                        UI::show_cars(this->auto_controller.get_all());
                        break;
                    case 10:
                        UI::show_clients(*this->auto_controller.get_clients());
                        break;
                    default:
                        cout<<"No such option\n!";
                }
                UI::show_menu_manager();
                cin >> choice2;
            }
        } else if (choice1 == 1){
            cout<<"\nName: ";
            cin >> name;
            Client actual_client(name);
            this->auto_controller.add_client(actual_client);
            UI::show_menu_client();
            cin >> choice2;
            while (choice2 != 10) {
                switch (choice2) {
                    case 1:
                        cout << "\nModel:";
                        cin >> model;
                        UI::show_cars(this->auto_controller.find_cars_model(model));
                    case 2:
                        cout <<" \nBrand: ";
                        cin >> brand;
                        UI::show_cars(this->auto_controller.find_cars_brand(brand));
                        break;
                    case 3:
                        cout << "\nAge: ";
                        cin >> age;
                        UI::show_cars(this->auto_controller.filter_cars_age(age));
                        break;
                    case 4:
                        cout << "\nKm: ";
                        cin >> km;
                        UI::show_cars(this->auto_controller.filter_cars_km(km));
                        break;
                    case 5:
                        UI::show_cars(this->auto_controller.sort_by_price());
                        break;
                    case 6:
                        cout<<"Enter the id!\n";
                        UI::read_in_id(id);
                        car = this->auto_controller.identify_car(id);
                        if (car.get_model()!="")
                            actual_client.add_favorite(car);
                        else
                            cout<<"We don't have this car!\n";
                        break;
                    case 7:
                        UI::show_cars(*actual_client.get_favorite());
                        break;
                    case 8:
                        UI::show_cars(this->auto_controller.get_all());
                        break;
                    case 9:
                        UI::show_clients(*this->auto_controller.get_clients());
                        break;
                    default:
                        cout << "No such an option";
                }
                UI::show_menu_client();
                cin >> choice2;
            }
        }
        cout << "Choose an option: \n";
        cout << "1. Client \n";
        cout << "2. Manager \n";
        cin >> choice1;
    }
}

Auto UI::read_in_car()
{
    string model, brand, fuel;
    int year, hp;
    float km, price;
    cout << "model: ";
    cin >> model;
    cout << "\nbrand: ";
    cin >> brand;
    cout << "\nyear: ";
    cin >> year;
    cout<<"\nkm: ";
    cin >> km;
    cout<<"\nprice: ";
    cin >> price;
    cout<<"\nhp: ";
    cin >> hp;
    cout<<"\nfuel: ";
    cin >> fuel;
    return Auto(model,brand,year,km,price,hp,fuel);
}

void UI::read_in_id(string &id)
{
    cout << "ID: ";
    cin >> id;
}


void UI::show_cars(std::vector<Auto> cars)
{
    for (auto car: cars)
        car.print_car();
}


void UI::show_clients(vector<Client> clients)
{
    for (auto client: clients)
    {
        cout << client.get_name();
        cout << endl;
    }

}
