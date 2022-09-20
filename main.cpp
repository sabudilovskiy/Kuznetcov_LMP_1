#include <iostream>
#include <fstream>
#include "Depo.h"
int main() {
    std::ifstream file_in("in.txt");
    if (!file_in.eof() && file_in.is_open()){
        Depo depo(file_in);
        depo.sort([](Car* left, Car* right) -> bool
        {
            return left->get_number() < right->get_number();
        });
        std::cout << "Sorted\n";
        depo.print(std::cout);
        size_t size = depo.size();
        Passanger_car* min_car = nullptr;
        for (int i = 0; i  < size && !min_car; ++i){
            auto car = depo[i];
            auto car_passanger = dynamic_cast<Passanger_car*>(car);
            if (car_passanger){
                if (!min_car && car_passanger->get_type() == Passanger_car::Type::Coupe && car_passanger->get_number_seat() < 36){
                    min_car = car_passanger;
                }
            }
        }
        if (min_car){
            std::cout << "Answer: ";
            min_car->print(std::cout);
        }
    }
}
