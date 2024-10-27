#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "stockroom.h"

//Get quantity of any one item
int stockroom::get_item_quantity(std::string name) {
    for (int i=0; i<itemnames.size(); i++) {
        if (itemnames[i] == name) {
            return itemquantities[i];
        }
    }
    return 0;
}

//Wrapper function to add an item by name, automatically updating the quantity as well
void stockroom::add_item(std::string name) {
    for (int i=0; i<itemnames.size(); i++) {
        if (itemnames[i] == name) {
            itemquantities[i] += 1;
            return;
        }
    }
    itemnames.push_back(name);
    itemquantities.push_back(1);
}

//Menu option 2
void stockroom::print_all() {
    std::cout << std::endl;
    for (int i=0; i<itemnames.size(); i++) {
        std::cout << itemnames[i] << ": " << itemquantities[i] << std::endl;
    }
}

//Menu uption 3
void stockroom::print_histogram() {
    std::cout << std::endl;
    for (int i=0; i<itemnames.size(); i++) {
        std::cout << std::left << std::setw(15) << itemnames[i];
        std::cout << " ";
        for (int j=0; j<itemquantities[i]; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

//Used for data backup
void stockroom::write_to_file(std::ofstream &file) {
    for (int i=0; i<itemnames.size(); i++) {
        file << itemnames[i] << "," << itemquantities[i];
        if (i < itemnames.size()-1) {
            file << ",";
        }
    }
}
