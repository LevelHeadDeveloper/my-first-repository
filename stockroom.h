#ifndef STOCKROOM_H
#define STOCKROOM_H

#include <string>
#include <vector>
#include <fstream>

class stockroom {
    public:
        int get_item_quantity(std::string name);
        void add_item(std::string name);
        void print_all();
        void print_histogram();
        void write_to_file(std::ofstream &file);

    private:
        //Data is kept private and wrapper functions are used to access/modify it as necessary
        std::vector<std::string> itemnames;
        std::vector<int> itemquantities;
};

#endif
