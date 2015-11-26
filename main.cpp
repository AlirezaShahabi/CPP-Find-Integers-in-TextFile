
// THIS PROGRAM READS A TEXT FILE AND RETURN EVERY INTEGER
// FOUND IN THE TEXT AS WELL AS THE CORRESPONDING LINE NUMBER

// ALL NUMBERS ARE SEPARATED FROM TEXT BY SPACE

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>



void find_numbers_in_file(const std::string&, std::ostream&);
void process_line(const std::string&, int, std::ostream&);
bool is_number(const std::string&);
void string_to_number(const std::string&, int, std::ostream&);



int main() {
    find_numbers_in_file("file1.txt", std::cout);
    return 0;
}



void find_numbers_in_file(const std::string& file_name, std::ostream& os) {
    std::ifstream ifs(file_name);
    std::string line;
    int line_number = 1;
    while (std::getline(ifs,line)) {
        process_line(line, line_number, os);
        ++line_number;
    }
}

void process_line(const std::string& line, int line_number, std::ostream& os) {
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        if (is_number(word)) {string_to_number(word, line_number, os);}
    }
}

bool is_number(const std::string& word) {
    for (const auto& c : word) {
        if (c >= '0' && c <= '9') {
        } else {
            return false;
        }
    }
    return true;
}

void string_to_number(const std::string& word, int line_number, std::ostream& os) {
    int num_digits = word.size();
    int ref = static_cast<int>('0');
    std::stack<int> digits;
    for (const auto& c : word) {
        int each_digit = static_cast<int>(c) - ref;
        digits.push(each_digit);
    }
    int the_number = 0;
    int ten_power = 1;
    for (int i=0; i<num_digits; ++i) {
        the_number += digits.top() * ten_power;
        digits.pop();
        ten_power *= 10;
    }    
    os << "line " << line_number << ": " << the_number << std::endl;
}

