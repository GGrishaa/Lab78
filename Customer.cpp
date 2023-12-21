#include "Customer.h"
Customer::Customer(){
    name_len = 6;
    char namename[7] = "NoName";
    name = new char;
    for(int i = 0; i < name_len; i++){
        name[i] = namename[i];
    }
    phone_len = 3;
    char phonephone[4] = "000";
    phone = new char;
    for(int i = 0; i < phone_len; i++){
        phone[i] = phonephone[i];
    }
    category_len = 2;
    char categorycategory[3] = "NO"; 
    category = new char;
    for(int i = 0; i < category_len; i++){
        category[i] = categorycategory[i];
    }
    years = 0;
    vehicle_count = 1;
    list = new Vehicle*[vehicle_count];
}
Customer::Customer(char name[], int len_name, char phone[], int len_phone, char category[], int len_category, int years, Vehicle list[], int count_vehicle){
    ++id;
    this->cod = id;
    this->name = new char[len_name];
    this->name_len = len_name;
    for(int i = 0; i < len_name; i++){
        this->name[i] = name[i];
    }

    this->phone = new char[len_phone];
    this->phone_len = len_phone;
    for(int i = 0; i < len_phone; i++){
        this->phone[i] = phone[i];
    }

    this->category = new char[len_category];
    this->category_len = len_category;
    for(int i = 0; i < len_category; i++){
        this->category[i] = category[i];
    }

    this->years = years;

    this->vehicle_count = count_vehicle;
    this->list = new Vehicle*[this->vehicle_count];
    for(int i = 0; i < vehicle_count; i++){
        this->list[i] = &(list[i]); 
    }
}

Customer::Customer(char name[], int len_name, char phone[], int len_phone, char category[], int len_category, int years){
    ++id;
    this->cod = id;
    this->name = new char[len_name];
    this->name_len = len_name;
    for(int i = 0; i < len_name; i++){
        this->name[i] = name[i];
    }

    this->phone = new char[len_phone];
    this->phone_len = len_phone;
    for(int i = 0; i < len_phone; i++){
        this->phone[i] = phone[i];
    }

    this->category = new char[len_category];
    this->category_len = len_category;
    for(int i = 0; i < len_category; i++){
        this->category[i] = category[i];
    }

    this->years = years;

    this->vehicle_count = 0;
    this->list = new Vehicle*[this->vehicle_count];
}

Customer::Customer(const Customer& other){
    delete[] this->name;
    delete[] this->phone;
    delete[] this->category;
    delete[] this->list;

    this->cod = other.cod;
    this->name_len = other.name_len;
    this->phone_len = other.phone_len;
    this->category_len = other.category_len;
    this->years = other.years;
    this->vehicle_count = other.vehicle_count;
        
    this->name = new char[name_len];
    this->phone = new char[phone_len];
    this->category = new char[category_len];
    this->list = new Vehicle*[vehicle_count];

    for(int i = 0; i < name_len; i++){
        this->name[i] = other.name[i];
    }
    for(int i = 0; i < phone_len; i++){
        this->phone[i] = other.phone[i];
    }
    for(int i = 0; i < category_len; i++){
        this->category[i] = other.category[i];
    }
    for(int i = 0; i < vehicle_count; i++){
        this->list[i] = other.list[i];
    }
}

Customer::~Customer(){
    delete[] this->name;
    delete[] this->phone;
    delete[] this->category;
    delete[] this->list;
}

void Customer::show_phone_number(){
    for(int i = 0; i < phone_len; i++){
        cout << phone[i];
    }
}
void Customer::show_category(){
    for(int i = 0; i < category_len; i++){
        cout << category[i];
    }
}
void Customer::show_name(){
    for(int i = 0; i < name_len; i++){
            cout << name[i];
        }
}
void Customer::show_information(){
    cout << "Name: ";
    show_name();
    cout << endl;
    cout << "Id number: " << id << endl;
    cout << "Driving car for " << years << " years ";
    cout << "Driver's license category: ";
    show_category();
    cout << endl;
    cout << "Phone number: ";
    show_phone_number();
    cout << endl;
    if(vehicle_count == 0){
        cout << "Has no vehicles" << endl;
    } 
    else if(vehicle_count == 1){
        cout << "Has 1 vehicle" << endl;
        list[0]->show_card();
    }
    else{
        cout << "Has " << vehicle_count << " vehicles" << endl;
        for(int i = 0; i < vehicle_count; i++){
            list[i]->show_card();
        }
    }
}
Customer& Customer::operator = (const Customer& other){
    delete[] this->name;
    delete[] this->phone;
    delete[] this->category;
    delete[] this->list;

    this->category_len = other.category_len;
    this->cod = other.cod;
    this->name_len = other.name_len;
    this->phone_len = other.phone_len;
    this->vehicle_count = other.vehicle_count;
    this->years = other.years;

    this->name = new char[this->name_len];
    this->category = new char[this->category_len];
    this->phone = new char[this->phone_len];
    this->list = new Vehicle*[this->vehicle_count];

    for(int i = 0; i < this->name_len; i++){
        this->name[i] = other.name[i];
    }
    for(int i = 0; i < this->phone_len; i++){
        this->phone[i] = other.phone[i];
    }
    for(int i = 0; i < this->category_len; i++){
        this->category[i] = other.category[i];
    }
    for(int i = 0; i < this->vehicle_count; i++){
        this->list[i] = other.list[i];
    }

    return *this;
}

int Customer::id = 0;

bool Customer::add_vehicle(Vehicle& transport){
    this->list[this->vehicle_count] = &transport;
    this->vehicle_count++;
    return true;
}

int Customer::get_year(){
    return years;
}

char* Customer::get_category(){
    return category;
}

int Customer::get_category_len(){
    return category_len;
}

void Customer::delete_vehicle(Vehicle& transport){
    int ii = -100;
    for(int i = 0; i < vehicle_count; i++){
        if (*list[i] == transport){
            ii = i;
            vehicle_count--;
        }
    }
    if (ii >= 0){
        for(int i = ii; i < vehicle_count; i++){
            list[i] = list[i + 1];
        }
    }
}