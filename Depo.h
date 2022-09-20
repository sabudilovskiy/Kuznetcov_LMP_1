//
// Created by MRV on 9/20/2022.
//

#ifndef KUZNETCOV_LMP_1_DEPO_H
#define KUZNETCOV_LMP_1_DEPO_H
#include "Cargo_car.h"
#include "Passanger_Car.h"
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <algorithm>

class Depo{
    std::string name;
    std::vector<Car*> cars;
public:
    Depo(std::ifstream& file_in){
        std::string temp;
        std::getline(file_in, temp);
        name = temp;
        while (!file_in.eof()){
            std::getline(file_in, temp);
            if (temp == "Car"){
                cars.push_back(new Car(file_in));
            }
            else if (temp == "Cargo_car"){
                cars.push_back(new Cargo_car(file_in));
            }
            else if (temp == "Passanger_Car"){
                cars.push_back(new Passanger_car(file_in));
            }
        }
    }
    Car* operator[](size_t index){
        return cars[index];
    }
    void sort(std::function<bool (Car*, Car*)> comp){std::sort(cars.begin(),  cars.end(), comp);}
    void print(std::ostream& out){
        for (auto car : cars){
            car->print(out);
            out << '\n';
        }
    }
    size_t size(){
        return cars.size();
    }
    const std::string &get_name() const {
        return name;
    }
    ~Depo(){
        for (auto car: cars){
            delete car;
        }
    }
};
#endif //KUZNETCOV_LMP_1_DEPO_H
