#pragma once
#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "Vehicle.h"
#include <iostream>
using namespace std;
class Vehicle;

class Customer{
  private:
    static int id;
    int cod;

    char* name;
    int name_len;

    char* phone;
    int phone_len;

    char* category;
    int category_len;

    int years;

    int vehicle_count;
    Vehicle** list;

  public:
    Customer();
    Customer(char name[], int len_name, char phone[], int len_phone, char category[], int len_category, int years, Vehicle list[], int count_vehicle);
    Customer(char name[], int len_name, char phone[], int len_phone, char category[], int len_category, int years);
    Customer(const Customer& other);
    ~Customer();
    void show_phone_number();
    void show_category();
    void show_name();
    void show_information();
    Customer & operator = (const Customer& other);
    bool add_vehicle(Vehicle& transport);
    int get_year();
    char* get_category();
    int get_category_len();
    void delete_vehicle(Vehicle& transport);
};
#endif