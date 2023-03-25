#include "auto_repository.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace electric_auto;
using namespace repo;

void In_Memory_Repository::initialize_repository()
{
    this->cars.push_back(Auto("X","Renault", 2021, 3000, 20000,300,"electric_batteries"));
    this->cars.push_back(Auto("X","Tesla", 2009, 300, 3000, 600, "electric_batteries"));
    this->cars.push_back(Auto("Y","Tesla", 2015, 450, 4700, 500, "electric_batteries"));
    this->cars.push_back(Auto("I-Pace","Jaguar", 2020, 200, 10000, 400, "biodiesel"));
    this->cars.push_back(Auto("Loco_Contigo","Rulz",2007, 270, 20000, 560 , "biodiesel"));
    this->cars.push_back(Auto("e-208","Peugeot", 2002, 120,10500,190, "hydrogen"));
    this->cars.push_back(Auto("500","Fiat",2001 , 111, 10600, 150, "biodiesel"));
    this->cars.push_back(Auto("3","Tesla", 2007, 234, 5700, 700, "electric_batteries"));
    this->cars.push_back(Auto("X","Volkswagen", 2022, 146, 4560, 867, "hydrogen"));
    this->cars.push_back(Auto("S","Tesla", 2000, 89, 21999, 300, "electric_batteries"));

}

void In_Memory_Repository::add_car(Auto electric_auto)
{
    this->cars.push_back(electric_auto);
}

void In_Memory_Repository::delete_car(string auto_id)
{
    for (std::vector<Auto>::iterator itr = this->cars.begin(); itr < this->cars.end(); itr++)
    {
        if (itr->get_id() == auto_id)
            this->cars.erase(itr);
    }
}

std::vector<Auto>* In_Memory_Repository::get_cars()
{
    return &this->cars;
}

std::vector<Auto> In_Memory_Repository::copy_cars()
{
    return this->cars;
}

void In_Memory_Repository::add_client(Client &client)
{
    this->clients.push_back(client);
}

std::vector<Client>* In_Memory_Repository::get_clients()
{
    return &this->clients;
}

void CSV_File_Repository::initialize_repository()
{
    ifstream fin;;
    string model, brand, fuel, str_km, str_price, str_hp, str_year, id;
    stringstream buffer;
    int year, hp;
    float km, price;
    fin.open("cars.csv");
    // , Delimitator
    while (getline(fin,id,',')) {
        getline(fin,model,',');
        getline(fin,brand,',');
        getline(fin,str_year,',');
        year = stoi(str_year);
        getline(fin,str_km,',');
        km = stof(str_km);
        getline(fin,str_price,',');
        price = stof (str_price);
        getline(fin,str_hp,',');
        hp = stoi(str_hp);
        getline(fin,fuel,'\n');
        this->cars.push_back(Auto(model, brand, year, km, price, hp, fuel));
    }
    fin.close();
}

void CSV_File_Repository::add_car(Auto car)
{
    this->cars.push_back(car);
    CSV_File_Repository::write_to_file();
}

void CSV_File_Repository::delete_car(string auto_id)
{
    for (std::vector<Auto>::iterator itr = this->cars.begin(); itr < this->cars.end(); itr++)
    {
        if (itr->get_id() == auto_id)
            this->cars.erase(itr);
    }
    CSV_File_Repository::write_to_file();
}

std::vector<Auto>* CSV_File_Repository::get_cars()
{
    return &this->cars;
}

std::vector<Auto> CSV_File_Repository::copy_cars()
{
    return this->cars;
}

void CSV_File_Repository::write_to_file()
{
    ofstream fout;
    fout.open("cars.csv");
    for (auto car: this->cars)
    {
        fout << car.get_id() << "," << car.get_model() << "," << car.get_brand() <<"," << car.get_year() << ","
             << car.get_km() << "," << car.get_price() << "," << car.get_hp() << "," << car.get_fuel() << endl;
    }
    fout.close();
}

void CSV_File_Repository::add_client(Client &client)
{
    this->clients.push_back(client);
}

std::vector<Client>* CSV_File_Repository::get_clients()
{
    return &this->clients;
}