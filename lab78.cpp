#include <iostream>
using namespace std;
#include "Vehicle.h"
#include "Customer.h"


class MaintenanceRecord{
  public:
    bool buy_car(Customer& client, Vehicle& transport){
        if (transport.change_owner(client)){
            client.add_vehicle(transport);
            cout << endl;
            transport.get_type();
            cout << " ";
            transport.get_name();
            cout << " теперь принадлежит ";
            client.show_name();
            cout << endl << endl;
            return true;
        }
        cout << endl << "Переоформление невозможно" << endl;
        client.show_name();
        cout << " не может управлять ";
        transport.get_type();
        cout << endl;
        return false;
    }
    void recolor(Vehicle& transport, char new_color[], int len_new_color){
        transport.recolor(new_color, len_new_color);
        cout << endl;
        transport.get_type();
        cout << " ";
        transport.get_name();
        cout << " был перекрашен в ";
        for(int i = 0; i < len_new_color; i++){
            cout << new_color[i];
        }
        cout << endl;
    }
    void sell_car(Customer& client, Vehicle& transport){
        client.delete_vehicle(transport);
        transport.delete_owner();
        cout << endl;
        transport.get_type();
        cout << " ";
        transport.get_name();
        cout << " теперь не принадлежит ";
        client.show_name();
        cout << endl;
    }
    void service(Vehicle& transport){
        transport.null_service();
        cout << endl << "Были проведены технические ремонт и обслуживание над ";
        transport.get_type();
        cout << " ";
        transport.get_name();
        cout << endl;
    }
};

class motorcycle : public Vehicle{
  public:
    bool change_owner(Customer& new_owner){
        char needcategory1 = 'A';
        for(int i = 0; i < new_owner.get_category_len(); i++){
            if (new_owner.get_category()[i] == needcategory1){
                return Vehicle::change_owner(new_owner);
            }
        }

        if (new_owner.get_year() >= 2){
            char needcategory2 = 'B';
            for(int i = 0; i < new_owner.get_category_len(); i++){
                if (new_owner.get_category()[i] == needcategory2){
                    return Vehicle::change_owner(new_owner);
                }
            }
        }
        return false;
    }
    void get_type(){
        char type[] = {'m', 'o', 't', 'o', 'r', 'c', 'y', 'c', 'l', 'e'};
        for(int i = 0; i < 10; i++){
            cout << type[i];
        }
    }
    motorcycle():Vehicle(){
        ;
    }
    motorcycle(char mark[], int len_mark, char model[], int len_model, char number[], int len_number, char color[], int len_color, float weight, int wheels) : Vehicle(mark, len_mark, model, len_model, number, len_number, color, len_color, weight, wheels){
        ;
    }
};

class light_vehicle : public Vehicle{
  public:
    bool change_owner(Customer& new_owner){
        char needcategory = 'B';
        for(int i = 0; i < new_owner.get_category_len(); i++){
            if (new_owner.get_category()[i] == needcategory){
                return Vehicle::change_owner(new_owner);
            }
        }
        return false;
    }
    void get_type(){
        char type[] = {'l', 'i', 'g', 'h', 't', ' ', 'c', 'a', 'r'};
        for(int i = 0; i < 9; i++){
            cout << type[i];
        }
    }
    light_vehicle() : Vehicle(){
        ;
    }
    light_vehicle(char mark[], int len_mark, char model[], int len_model, char number[], int len_number, char color[], int len_color, float weight, int wheels) : Vehicle(mark, len_mark, model, len_model, number, len_number, color, len_color, weight, wheels){
        ;
    }
};

class heavy_vehicle : public Vehicle{
  public:
    bool change_owner(Customer& new_owner){
        char needcategory = 'C';
        for(int i = 0; i < new_owner.get_category_len(); i++){
            if (new_owner.get_category()[i] == needcategory){
                return Vehicle::change_owner(new_owner);
            }
        }
        return false;
    }
    void get_type(){
        char type[] = {'h', 'e', 'a', 'v', 'y', ' ', 'c', 'a', 'r'};
        for(int i = 0; i < 9; i++){
            cout << type[i];
        }
    }
    heavy_vehicle() : Vehicle(){
        ;
    }
    heavy_vehicle(char mark[], int len_mark, char model[], int len_model, char number[], int len_number, char color[], int len_color, float weight, int wheels) : Vehicle(mark, len_mark, model, len_model, number, len_number, color, len_color, weight, wheels){
        ;
    }
};

int main(){
    cout << "Everything is okay!" << endl << endl << endl;
    char mark1[] = {'T', 'o', 'y', 'o', 't', 't', 'a'};
    char model1[] = {'C', 'o', 'r', 'o', 'l', 'l', 'a'};
    char num1[] = {'M', '1', '1', '9', 'B', 'P', '2', '1'};
    char color1[] = {'y', 'e', 'l', 'l', 'o', 'w'};
    light_vehicle car1(mark1, 7, model1, 7, num1, 8, color1, 6, 2, 4);

    char mark2[] = {'N', 'i', 's', 's', 'a', 'n'};
    char model2[] = {'G', 'T', 'R'};
    char num2[] = {'P', '3', '3', '3', 'T', 'K', '1', '1', '7'};
    char color2[] = {'b', 'l', 'a', 'c', 'k'};
    light_vehicle car2(mark2, 6, model2, 3, num2, 9, color2, 5, 2.5, 4);
    Vehicle spisok[1] = {car1};

    char name1[] = {'P', 'e', 't', 'r'};
    char number1[] = {'8', '9', '2', '7', '9', '9', '3', '6', '3', '2', '5'};
    char cat1[] = {'A', 'C'};
    Customer man1(name1, 4, number1, 11, cat1, 2, 1, spisok, 1);

    char mark3[] = {'d', 'a', 'k', 'o', 't', 'a'};
    char model3[] = {'s', 'p', 'o', 'r', 't'};
    char num3[] = {'A', '2', '3', 'A'};
    char color3[] = {'b', 'l', 'u', 'e'};
    motorcycle cycle1(mark3, 6, model3, 5, num3, 4, color3, 4, 0.5, 2);

    char mark4[] = {'u', 'a', 'z'};
    char model4[] = {'2', '3', '1'};
    char num4[] = {'A', '1', '2', '3', 'S', 'K', '2', '1'};
    char color4[] = {'o', 'r', 'a', 'n', 'g', 'e'};
    heavy_vehicle heavy1(mark4, 3, model4, 2, num4, 8, color4, 6, 5, 6);

    man1.show_information();
    MaintenanceRecord pupupu;
    pupupu.buy_car(man1, car2);
    char color3[] = {'r', 'e', 'd'};
    pupupu.recolor(car2, color3, 3);
    cout << endl;
    man1.show_information();
    pupupu.sell_car(man1, car1);
    man1.show_information();
    return 0;
}
