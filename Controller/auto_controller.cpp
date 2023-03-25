#include <algorithm>
#include "auto_controller.h"
using namespace std;
using namespace electric_auto;
using namespace controller;
using namespace repo;

Controller_In_Memory::Controller_In_Memory(In_Memory_Repository &repository)
{
    this->auto_repo = repository;
}

void Controller_In_Memory::add_car(Auto car)
{
    this->auto_repo.add_car(car);
}

bool Controller_In_Memory::delete_car(string auto_id)
{
    auto size_before_delete = this->auto_repo.get_cars()->size();
    this->auto_repo.delete_car(auto_id);
    if (size_before_delete == this->auto_repo.get_cars()->size())
        return false;
    else
        return true;
}

void Controller_In_Memory::modify_car(string id, Auto &modified_car)
{
    string actual_id;
    auto car_to_modify = find_if(this->auto_repo.get_cars()->begin(), this->auto_repo.get_cars()->end(),
                         [&](Auto &car)
                         {
                            actual_id = car.get_id();
                            return actual_id == id;
                         } );
    if (car_to_modify != auto_repo.get_cars()->end())
    {
        string new_brand = modified_car.get_brand(), new_model = modified_car.get_model(), new_fuel = modified_car.get_fuel();
        int new_year = modified_car.get_year(), new_hp = modified_car.get_hp();
        float new_km = modified_car.get_km();
        car_to_modify->set_brand(new_brand);
        car_to_modify->set_model(new_model);
        car_to_modify->set_year(new_year);
        car_to_modify->set_hp(new_hp);
        car_to_modify->set_km(new_km);
        car_to_modify->set_fuel(new_fuel);
    }
}

std::vector<Auto> Controller_In_Memory::find_cars_brand (string brand)
{
    std::vector<Auto> searched_cars;
    string actual_brand;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_brand = itr->get_brand();
        if (actual_brand == brand)
            searched_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return searched_cars;
}

std::vector<Auto> Controller_In_Memory::find_cars_model(string model)
{
    std::vector<Auto> searched_cars;
    string actual_model;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_model = itr->get_model();
        if (actual_model == model)
            searched_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return searched_cars;
}

std::vector<Auto> Controller_In_Memory::filter_cars_km (float km)
{
    std::vector<Auto> filtered_cars;
    float actual_km;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_km = itr->get_km();
        if (actual_km == km)
            filtered_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return filtered_cars;
}

std::vector<Auto> Controller_In_Memory::filter_cars_age (int age)
{
    std::vector<Auto> filtered_cars;
    int actual_age;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_age = 2023 - itr->get_year();
        if (actual_age == age)
            filtered_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return filtered_cars;
}

std::vector<Auto> Controller_In_Memory::sort_by_price ()
{
    // wir kopieren alle Produkten und danach sortieren
    std::vector<Auto> sorted = this->auto_repo.copy_cars();

    sort(sorted.begin(), sorted.end(),
         [](Auto car1, Auto car2)
         {
             float price1 = car1.get_price();
             float price2 = car2.get_price();
             return price1 < price2;
         });
    return sorted;
}

std::vector<Auto> Controller_In_Memory::get_all()
{
    return this->auto_repo.copy_cars();
}

void Controller_In_Memory::add_client(Client &client)
{
    this->auto_repo.add_client(client);
}

std::vector<Client>* Controller_In_Memory::get_clients()
{
    return this->auto_repo.get_clients();
}

Auto Controller_In_Memory :: identify_car (string id)
{
    std::vector<Auto> filtered_cars;
    int actual_age;
    for (auto itr = this->get_all().begin(); itr < this->get_all().end(); itr++)
    {
        if (itr->get_id() == id)
            return (*itr);
    }
    return Auto("","",0,0,0,0,"");
}

Controller_CSV::Controller_CSV(CSV_File_Repository &repository)
{
    this->auto_repo = repository;
}

void Controller_CSV::add_car(Auto car)
{
    this->auto_repo.add_car(car);
}

bool Controller_CSV::delete_car(string auto_id)
{
    auto size_before_delete = this->auto_repo.get_cars()->size();
    this->auto_repo.delete_car(auto_id);
    if (size_before_delete == this->auto_repo.get_cars()->size())
        return false;
    else
        return true;
}

void Controller_CSV::modify_car(string id, Auto &modified_car)
{
    string actual_id;
    auto car_to_modify = find_if(this->auto_repo.get_cars()->begin(), this->auto_repo.get_cars()->end(),
                                 [&](Auto &car)
                                 {
                                     actual_id = car.get_id();
                                     return actual_id == id;
                                 } );
    if (car_to_modify != auto_repo.get_cars()->end())
    {
        string new_brand = modified_car.get_brand(), new_model = modified_car.get_model(), new_fuel = modified_car.get_fuel();
        int new_year = modified_car.get_year(), new_hp = modified_car.get_hp();
        float new_km = modified_car.get_km();
        car_to_modify->set_brand(new_brand);
        car_to_modify->set_model(new_model);
        car_to_modify->set_year(new_year);
        car_to_modify->set_hp(new_hp);
        car_to_modify->set_km(new_km);
        car_to_modify->set_fuel(new_fuel);
    }
    this->auto_repo.write_to_file();
}

std::vector<Auto> Controller_CSV::find_cars_brand (string brand)
{
    std::vector<Auto> searched_cars;
    string actual_brand;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_brand = itr->get_brand();
        if (actual_brand == brand)
            searched_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return searched_cars;
}

std::vector<Auto> Controller_CSV::find_cars_model(string model)
{
    std::vector<Auto> searched_cars;
    string actual_model;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_model = itr->get_model();
        if (actual_model == model)
            searched_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return searched_cars;
}

std::vector<Auto> Controller_CSV::filter_cars_km (float km)
{
    std::vector<Auto> filtered_cars;
    float actual_km;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_km = itr->get_km();
        if (actual_km == km)
            filtered_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return filtered_cars;
}

std::vector<Auto> Controller_CSV::filter_cars_age (int age)
{
    std::vector<Auto> filtered_cars;
    int actual_age;
    for (std::vector<Auto>::iterator itr = this->auto_repo.get_cars()->begin(); itr < this->auto_repo.get_cars()->end(); itr++)
    {
        actual_age = 2022 - itr->get_year();
        if (actual_age == age)
            filtered_cars.push_back(*itr);
    }
    // neue vector zurueckgeben
    return filtered_cars;
}

std::vector<Auto> Controller_CSV::sort_by_price ()
{
    // wir kopieren alle Produkten und danach sortieren
    std::vector<Auto> sorted = this->auto_repo.copy_cars();

    sort(sorted.begin(), sorted.end(),
         [](Auto car1, Auto car2)
         {
             float price1 = car1.get_price();
             float price2 = car2.get_price();
             return price1 < price2;
         });
    return sorted;
}

std::vector<Auto> Controller_CSV::get_all()
{
    return this->auto_repo.copy_cars();
}

void Controller_CSV::add_client(Client &client)
{
    this->auto_repo.add_client(client);
}

std::vector<Client>* Controller_CSV::get_clients()
{
    return this->auto_repo.get_clients();
}

Auto Controller_CSV :: identify_car (string id)
{
    std::vector<Auto> filtered_cars;
    for (auto itr = this->get_all().begin(); itr < this->get_all().end(); itr++)
    {
        if (itr->get_id() == id)
            return (*itr);
    }
    return Auto("","",0,0,0,0,"");
}

