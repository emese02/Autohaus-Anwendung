#include "test_controller.h"
#include "auto_controller.h"
#include <iostream>
#include <cassert>
#include <memory>
using namespace repo;
using namespace controller;

void test_find_cars_brand()
{
    auto repository = make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    auto found = controller->find_cars_brand("Tesla");
    assert(found.begin()->get_model() == "X");
    assert((found.begin()+2)->get_model() == "3");
}

void test_find_cars_model()
{
    string model="Loco_Contigo";
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    auto found = controller->find_cars_model(model);
    assert(found.size()==1);
    assert(found.begin()->get_brand() == "Rulz");
    model = "X";
    found = controller->find_cars_model(model);
    assert(found.size() == 3);
    assert(found.begin()->get_brand() == "Renault");
    assert((found.begin()+2)->get_brand() == "Volkswagen");
}

void test_filter_cars_age()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    int age = 16;
    auto filtered_cars = controller->filter_cars_age(age);
    assert(filtered_cars.size() == 2);
    assert(filtered_cars.begin()->get_model() == "Loco_Contigo" && filtered_cars.begin()->get_brand() == "Rulz");
    assert((filtered_cars.begin()+1)->get_model() == "3" && (filtered_cars.begin()+1)->get_brand() == "Tesla");
    // keine Autos mit der Bedingung
    age = 35;
    filtered_cars = controller->filter_cars_age(age);
    assert(filtered_cars.empty());
}

void test_filter_cars_km()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    float km = 200;
    auto filtered_cars = controller->filter_cars_km(km);
    assert(filtered_cars.size()==1);
    // keine Autos mit der Bedingung
    km = 1000;
    filtered_cars = controller->filter_cars_km(km);
    assert(filtered_cars.empty());
}

void test_sort_by_price()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    auto sorted = controller->sort_by_price();
    assert(sorted.size()==10);
    // kleinste Preis am Anfang
    assert(sorted.begin()->get_price() == 3000  && sorted.begin()->get_model() == "X" && sorted.begin()->get_brand() == "Tesla");
    // teuerste am Ende
    assert((sorted.begin()+9)->get_price() == 21999 && (sorted.begin()+9)->get_model() == "S" && (sorted.begin()+9)->get_brand() == "Tesla");
}

void test_modify_car()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    string id = "22XVolkswagen10";
    Auto modified_car("Volkswagen","X",2022,160,4580,1000,"biodiesel");
    controller->modify_car(id,modified_car);
    assert((controller->get_all().begin()+8)->get_brand() == "Volkswagen");
}

void test_add_favorite()
{
    auto repository = std::make_unique<In_Memory_Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller_In_Memory> controller = std::make_unique<Controller_In_Memory>(*repository);
    Auto new_auto("Z","Tesla",2009,89,21999,320,"electric_batteries");
    Client c("Franziska");
    assert(c.get_favorite()->size() == 0);
    c.add_favorite(new_auto);
    assert(c.get_favorite()->size() == 1);
}

void test_controller()
{
    test_find_cars_brand();
    test_find_cars_model();
    test_filter_cars_age();
    test_filter_cars_km();
    test_sort_by_price();
    test_modify_car();
    test_add_favorite();
    std::cout << "Controller tested!\n";
}