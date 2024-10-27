/*
 * Calculator.cpp
 *
 *  Date: 10/17/2024
 *  Author: Benedict Sullivan
 */

#include <fstream>
#include <iostream>
#include <limits>

#include "stockroom.h"

char show_menu() { //Helper function to print menu and get input
    char next = '0';
    while (true) { //Loop used for input validation
        std::cout << std::endl;
        std::cout << "1: Search by item name\n";
        std::cout << "2: Print all items and quantities\n";
        std::cout << "3: Print histogram of all items\n";
        std::cout << "4: Exit program\n";
        std::cin >> next;
        if ((next >= '1') && (next <= '4')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Make certain the buffer is empty
            return next; //Break out of the loop when a valid option is selected
        } else {
            std::cout << std::endl << "Invalid option selected." << std::endl; //Loop is not broken and menu is shown again
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Make certain the buffer is empty
        }
    }
}

int main() {

    //Initialize stockroom object
    stockroom* st = new stockroom();

    //Read in data from input file
    std::ifstream file("CS210_Project_Three_Input_File.txt");
    std::string currentline;
    while (std::getline(file, currentline)) {
        st->add_item(currentline);
    }
    file.close();

    //Create backup of data
    std::ofstream backup;
    backup.open("frequency.dat");
    st->write_to_file(backup);
    backup.close();

    //Main loop
    char nextOption = show_menu();

    while (nextOption != '4') { //Loop exits when user enters option 4

        if (nextOption == '1') {

            //Search for item by name
            std::cout << "\nEnter name of item to search for: ";
            std::string item = "";
            std::cin >> item;
            std::cout << std::endl << item << ": " << st->get_item_quantity(item) << std::endl;

        } else if (nextOption == '2') {

            //Print all items and quantities
            st->print_all();

        } else if (nextOption == '3') {

            //Print histogram
            st->print_histogram();

        }

        //Prompt user for next input
        nextOption = show_menu();

    }

    //Notify user and clean up
    std::cout << "Exiting" << std::endl;
    delete st;
    return 0;
}
