#pragma once
#include <string>
using namespace std;

namespace electric_auto {
class Auto
{
private :
    string model;
    string brand;
    int year;
    float km;
    float price;
    int hp;  // Leistung
    string id;
    string fuel; // Treibstoff

public :
    Auto(string model, string brand, int registration_date, float km, float price, int hp, string fuel);
    Auto() = default;
    string get_model() const;
    string get_brand() const;
    int get_year() const;
    float get_price() const;
    float get_km() const;
    int get_hp() const;
    string get_id() const;
    string get_fuel() const;
    void set_model (string new_model);
    void set_brand (string new_brand);
    void set_year (int new_year);
    void set_km (float new_km);
    void set_price (float new_price);
    void set_hp (int hp);
    void set_fuel (string new_fuel);
    // Daten von einem Auto anschauen
    void print_car();
    Auto get_instance();

};}