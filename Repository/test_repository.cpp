#include "test_repository.h"
#include "auto_repository.h"
#include <memory>
#include <iostream>
#include <cassert>
using namespace repo;

void test_initialize_repository()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    assert(repository->get_cars()->size() == 10);
    // Am Anfang
    assert(repository->get_cars()->begin()->get_model() == "X" && repository->get_cars()->begin()->get_brand() == "Renault");
    // In der Mitte
    assert((repository->get_cars()->begin()+2)->get_model() == "Y" && (repository->get_cars()->begin()+2)->get_brand() == "Tesla");
    // Am Ende
    assert((repository->get_cars()->end()-1)->get_model() == "S" && (repository->get_cars()->end()-1)->get_brand() == "Tesla");
}

void test_add_car()
{
    //2ePeugeot1,e-208,Peugeot,2002,120,10500,190,hydrogen
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    assert(repository->get_cars()->size() == 10);
    Auto new_car("f998","Peugeot", 2018, 180,9998,230, "hydrogen");
    repository->add_car(new_car);
    assert(repository->get_cars()->size() == 11);
    // neues Auto am Ende eingefuegt
    Auto new_car2("g786","Peugeot", 2020, 180,9998,230, "hydrogen");
    Auto new_car3("h555","Peugeot", 2019, 190,9778,18, "hydrogen");
    // mehrere Autos hinzufuegen
    repository->add_car(new_car2);
    repository->add_car(new_car3);
    assert(repository->get_cars()->size() == 13);
}

void test_delete_car()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    auto old_size = repository->get_cars()->size();
    // echtes Auto loeschen
    // ID von Auto ("I-Pace","Jaguar",2020,200,10000,400,"biodiesel") ---> 20IJaguar4
    repository->delete_car("20IJaguar4");
    auto new_size = repository->get_cars()->size();
    assert(old_size-1 == new_size);
    // Auto loeschen die nicht in Repository ist
    // ID von Auto ("8","Tesla",2007,234,5700,7,245);  -> 208TESLA5
    repository->delete_car("208TESLA5");
    assert(new_size == repository->get_cars()->size());
}

void test_add_to_favorite()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
   Auto new_auto("Z","Tesla",2009,89,21999,320,"electric_batteries");
    Client c("Franziska");
    assert(c.get_favorite()->size() == 0);
    c.add_favorite(new_auto);
    assert(c.get_favorite()->size() == 1);
}

void test_copy_cars()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    auto copied = repository->copy_cars();
    assert(copied.size() == 10);
    assert(copied.begin()->get_model() == "X" && copied.begin()->get_brand() == "Renault");
    assert(copied[2].get_model() == "Y" && copied[2].get_brand() == "Tesla");
}

void test_repository()
{
    test_initialize_repository();
    test_add_car();
    test_delete_car();
    test_add_to_favorite();
    test_copy_cars();
    std::cout << "Repository tested!\n";
}