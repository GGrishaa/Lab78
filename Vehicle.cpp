#include "Vehicle.h"
Vehicle::Vehicle(){
    mark = new char;
    model = new char;
    number = new char;
    color = new char;
}
Vehicle::Vehicle(char mark[], int len_mark, char model[], int len_model, char number[], int len_number, char color[], int len_color, float weight, int wheels){
    this->mark = new char[len_mark];
    this->model = new char[len_model];
    this->number = new char[len_number];
    this->color = new char[len_color];
        
    this->color_len = len_color;
    this->number_len = len_number;
    this->model_len = len_model;
    this->mark_len = len_mark;
    this->weight = weight;
    this->wheels = wheels;
    this->last_service = 0;

    for(int i = 0; i < color_len; i++){
        this->color[i] = color[i];
    }
    for(int i = 0; i < mark_len; i++){
        this->mark[i] = mark[i];
    }
    for(int i = 0; i < model_len; i++){
        this->model[i] = model[i];
    }
    for(int i = 0; i < number_len; i++){
        this->number[i] = number[i];
    } 
}
Vehicle::Vehicle(const Vehicle& other){
    this->color_len = other.color_len;
    this->number_len = other.number_len;
    this->model_len = other.model_len;
    this->mark_len = other.mark_len;
    this->weight = other.weight;
    this->wheels = other.wheels;
    this->owner = other.owner;
    this->last_service = other.last_service;

    this->mark = new char[this->mark_len];
    this->model = new char[this->model_len];
    this->number = new char[this->number_len];
    this->color = new char[this->color_len];
        
    for(int i = 0; i < this->color_len; i++){
        this->color[i] = other.color[i];
    }
    for(int i = 0; i < this->mark_len; i++){
        this->mark[i] = other.mark[i];
    }
    for(int i = 0; i < this->model_len; i++){
        this->model[i] = other.model[i];
    }
    for(int i = 0; i < this->number_len; i++){
        this->number[i] = other.number[i];
    }
}
Vehicle::~Vehicle(){
    delete[] mark;
    delete[] model;
    delete[] number;
    delete[] color;
}
void Vehicle::show_card(){
    cout << "Vehicle ";
    for(int i = 0; i < mark_len; i++){
        cout << mark[i];
    }
    cout << " ";
    for(int i = 0; i < model_len; i++){
        cout << model[i];
    }
    cout << " in ";
    for(int i = 0; i < color_len; i++){
        cout << color[i];
    }
    cout << " color" << endl;
    cout << "Vehicle's number: ";
    for(int i = 0; i < number_len; i++){
        cout << number[i];
    }
    cout << " Weight is " << weight << " tons" << endl;
}
Vehicle& Vehicle::operator = (const Vehicle& other){
    delete[] this->model;
    delete[] this->mark;
    delete[] this->number;
    delete[] this->color;

    this->mark_len = other.mark_len;
    this->color_len = other.color_len;
    this->model_len = other.model_len;
    this->number_len = other.number_len;
    this->weight = other.weight;
    this->wheels = other.wheels;
    this->last_service = other.last_service;

    this->model = new char[this->model_len];
    this->mark = new char[this->mark_len];
    this->number = new char[this->number_len];
    this->color = new char[this->color_len];

    this->owner = other.owner;
    for(int i = 0; i < model_len; i++){
        this->model[i] = other.model[i];
    }
    for(int i = 0; i < mark_len; i++){
        this->mark[i] = other.mark[i];
    }
    for(int i = 0; i < number_len; i++){
        this->number[i] = other.number[i];
    }
    for(int i = 0; i < color_len; i++){
        this->color[i] = other.color[i];
    }
    return *this;
}

bool Vehicle::change_owner(Customer& new_owner){
    this->owner = &new_owner;
    return true;
}

void Vehicle::get_type(){
    ;
}

void Vehicle::get_name(){
    for(int i = 0; i < mark_len; i++){
        cout << mark[i];
    }
    cout << " ";
    for(int i = 0; i < model_len; i++){
        cout << model[i];
    }
}

void Vehicle::recolor(char new_color[], int len_new_color){
    this->color_len = len_new_color;
    delete[] this->color;
    this->color = new char[len_new_color];
    for(int i = 0; i < len_new_color; i++){
        this->color[i] = new_color[i];
    }
}

bool Vehicle::operator == (const Vehicle& transport){
    if (this->color_len != transport.color_len){
        return false;
    }
    else if (this->mark_len != transport.mark_len){
        return false;
    }
    else if (this->model_len != transport.model_len){
        return false;
    }
    else if (this->number_len != transport.number_len){
        return false;
    }
    else if (this->owner != transport.owner){
        return false;
    }
    else{
        for(int i = 0; i < this->color_len; i++){
            if (this->color[i] != transport.color[i]){
                return false;
            }
        }
        for(int i = 0; i < this->model_len; i++){
            if (this->model[i] != transport.model[i]){
                return false;
            }
        }
        for(int i = 0; i < this->mark_len; i++){
            if(this->mark[i] != transport.mark[i]){
                return false;
            }
        }
        for(int i = 0; i < this->number_len; i++){
            if(this->number[i] != transport.number[i]){
                return false;
            }
        }
        return true;
    }
}

void Vehicle::delete_owner(){
    owner = NULL;
}

void Vehicle::null_service(){
    last_service = 0;
}