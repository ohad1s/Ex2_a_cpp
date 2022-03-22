#include "Notebook.hpp"

using namespace std;

void ariel::Notebook::write(int page, int row, int col, ariel::Direction, string sentence) {}

void ariel::Notebook::erase(int page, int row, int col, ariel::Direction, int num_of_chars_to_clear) {}

std::string ariel::Notebook::read(int page, int row, int col, ariel::Direction, int len_to_read) {
    return "a";
}

std::string ariel::Notebook::show(int page) {
    return "a";
}


