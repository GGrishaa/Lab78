#pragma once
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "Customer.h"
#include <iostream>
using namespace std;
class Customer;

class Vehicle{
  private:
    char* mark;
    int mark_len;

    char* model;
    int model_len;

    char* number;
    int number_len;

    char* color;
    int color_len;

    float weight;
    int wheels;

    Customer* owner;

    int last_service;
  public:
    Vehicle();
    Vehicle(char mark[], int len_mark, char model[], int len_model, char number[], int len_number, char color[], int len_color, float weight, int wheels);
    Vehicle(const Vehicle& other);
    ~Vehicle();
    void show_card();
    Vehicle& operator = (const Vehicle& other);
    virtual bool change_owner(Customer& new_owner);
    virtual void get_type();
    void get_name();
    void recolor(char new_color[], int len_new_color);
    bool operator == (const Vehicle& other);
    void delete_owner();
    void null_service();
};

#endif