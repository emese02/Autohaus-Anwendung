#include "auto.h"
#include <iostream>
#include <sstream>
using namespace electric_auto;

Auto::Auto (string model, string brand, int registration_date, float km, float price, int hp, string fuel)
{
    this->model = model;
    this->brand = brand;
    this->year = registration_date;
    this->km = km;
    this->price = price;
    this->hp = hp;
    this->fuel = fuel;
    stringstream buffer;
    buffer << this->year % 100 << model.substr(0,1) << brand << this->hp/100;
    this->id = buffer.str();
}

string Auto::get_model() const
{
    return this->model;
}

string Auto::get_brand() const
{
    return this->brand;
}

int Auto::get_year() const
{
    return this->year;
}

float Auto::get_price() const
{
    return this->price;
}

float Auto::get_km() const
{
    return  this->km;
}

int Auto::get_hp() const
{
    return this->hp;
}

string Auto::get_id() const
{
    return this->id;
}

string Auto::get_fuel() const
{
    return this->fuel;
}

void Auto::set_model (string new_model)
{
    this->model = new_model;
}

void Auto::set_brand (string new_brand)
{
    this->brand = new_brand;
}

void Auto::set_year (int new_year)
{
    this->year = new_year;
}

void Auto::set_km (float new_km)
{
    this->km = new_km;
}

void Auto::set_price (float new_price)
{
    this->price = new_price;
}

void Auto::set_hp (int hp)
{
    this->hp = hp;
}

void Auto::set_fuel (string new_fuel)
{
    this->fuel = new_fuel;
}

void Auto::print_car()
{
    std::cout << "Model: "<< this->model << " ~ Brand: " << this->brand << "~ Year: " << this->year << " ~Km: "
    << this->km << "~ Price: " << this->price <<" ~ Horse power: " << this->hp <<" ~ Fuel: " << this->fuel << " ~ ID: " << this->id << endl;
}

Auto Auto::get_instance()
{
    return (*this);
}