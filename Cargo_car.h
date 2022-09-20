//
// Created by MRV on 9/20/2022.
//

#ifndef KUZNETCOV_LMP_1_CARGO_CAR_H
#define KUZNETCOV_LMP_1_CARGO_CAR_H
#include "Car.h"
class Cargo_car : public Car{
    std::uint16_t tonnage;
    enum class type{
        cistern, platform, poluvagon, refrigector
    } type;
public:
    Cargo_car(std::ifstream& file_in) : Car(file_in){
        std::string temp;
        std::getline(file_in, temp);
        tonnage = std::stoi(temp);
        std::getline(file_in, temp);
        if (temp == "cistern"){
            type = type::cistern;
        }
        else if(temp == "platform"){
            type = type::platform;
        }
        else if(temp == "poluvagon"){
            type = type::poluvagon;
        }
        else {
            type = type::refrigector;
        }
    }
    [[nodiscard]] uint16_t get_tonnage() const {
        return tonnage;
    }
    void print(std::ostream &out) override {
        Car::print(out);
        out << " tonnage: " << tonnage << " type: ";
        switch (type) {
            case type::cistern:
                out << "cistern";
                break;
            case type::platform:
                out << "platform";
                break;
            case type::poluvagon:
                out << "poluvagon";
                break;
            case type::refrigector:
                out << "refrigector";
                break;
        }
    }
};
#endif //KUZNETCOV_LMP_1_CARGO_CAR_H
