//
// Created by shira on 06/03/2022.
//

#ifndef EX1CPP_MAT_H
#define EX1CPP_MAT_H

#endif //EX1CPP_MAT_H
#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Notebook {
    public:
        void write(int page, int row, int col, ariel::Direction , string sentence);
        void erase(int page, int row, int col, ariel::Direction, int num_of_chars_to_clear );
        std::string read(int page, int row, int col, ariel::Direction, int len_to_read );
        std::string show(int page);
        Notebook() {
        }
    };
}
