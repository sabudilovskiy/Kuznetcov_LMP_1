//
// Created by MRV on 9/20/2022.
//

#ifndef KUZNETCOV_LMP_1_PASSANGER_CAR_H
#define KUZNETCOV_LMP_1_PASSANGER_CAR_H
#include "Car.h"
class Passanger_car : public Car{
public:
    enum class Type{
        Coupe, Plackart
    };
protected:
    Type type;
    std::uint8_t number_seat;
    bool show;
public:
    Passanger_car(std::ifstream& file_in) : Car(file_in){
        std::string temp;
        std::getline(file_in, temp);
        if (temp == "Coupe"){
            type = Type::Coupe;
        }
        else type = Type::Plackart;
        std::getline(file_in, temp);
        number_seat = std::stoi(temp);
        std::getline(file_in, temp);
        if (temp == "yes") {
            show = true;
        }
        else show = false;
    }
    Type get_type() const {
        return type;
    }
    uint8_t get_number_seat() const {
        return number_seat;
    }
    bool is_show() const {
        return show;
    }
    void print(std::ostream &out) override {
        Car::print(out);
        out << " type: ";
        switch (type) {
            case Type::Coupe:
                out << "Coupe";
                break;
            case Type::Plackart:
                out << "Plackart";
                break;
        }
        out << " number seat: " << (int)number_seat << " show: " << (show ? "yes" : "no");
    }
};

#endif //KUZNETCOV_LMP_1_PASSANGER_CAR_H
