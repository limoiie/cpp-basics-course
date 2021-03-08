#include "Address.h"

#include <iostream> // for using std::cout

// implementation out of class definition
void Address::print_info() const {
    std::cout << "City: " << city << ", "
              << "Street No." << street_number << std::endl;
}
