//
// Created by MRV on 9/20/2022.
//

#ifndef KUZNETCOV_LMP_1_CAR_H
#define KUZNETCOV_LMP_1_CAR_H
#include <numeric>
#include <fstream>
#include <string>
class Car{
    size_t number;
    std::uint16_t year;
public:
    Car(size_t number, uint16_t year) : number(number), year(year) {}
    Car(std::ifstream& file_in){
        std::string temp;
        std::getline(file_in, temp);
        number = std::stoull(temp);
        std::getline(file_in, temp);
        year = std::stoi(temp);
    }
    size_t get_number() const {
        return number;
    }
    uint16_t get_year() const {
        return year;
    }
    virtual void print(std::ostream& out){
        out << "number: " << number << " year: " << year;
    }
};
#endif //KUZNETCOV_LMP_1_CAR_H
