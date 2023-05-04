#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

typedef struct User {
    std::string username;
    std::string password;
} User;

std::vector<std::string> keywords = {"create", "insert", "update", "delete", "help", "alter"};

// sample user entry:
//      admin password [...roles]


std::string string_to_lower(std::string &input);
void parse(std::string);
void split(std::string&, const char, std::vector<std::string>&);
void read_users_from_file();
void write_to_binary_log(const std::string&);

int main() {
    std::cout << "Starting up ToyDB...";
    write_to_binary_log("started toydb");
    read_users_from_file();
}

void read_users_from_file() {
    std::ifstream in;
    std::string line;
    // std::string dehashed;
    std::vector<std::string> tokenized;
    
    std::cout<< "Attempting to load users.\n";
    in.open("./auth.tdb", std::ios::in);

    if (in) {
        while (!in.eof()) {
            std::getline(in, line);
            split(line, ' ', tokenized);
            printf("User: %s, Password: %s, Roles: %s\n", tokenized.at(0).c_str(), tokenized.at(1).c_str(), tokenized.at(2).c_str());
            
            tokenized.clear();
        }
        in.close();
    }
}

void read_toyboxes_from_master_record() {

}

void write_to_binary_log(const std::string& item) {
    std::ofstream out;
    out.open("./tdb.log", std::ios::out);

    if (out) {
        out << item << std::endl;
    } else {
        std::cout << "Unable to open the binary log.";
        out.close();
    }
}

void console_input() {
std::string input;
    while (1) {
        std::cout << "[ToyDB] > ";
        std::getline(std::cin, input);
        parse(string_to_lower(input));
            
    }
}

void parse(std::string input) {
    std::vector<std::string> tokenized;
    split(input, ' ', tokenized);

    if (std::find(keywords.begin(), keywords.end(), string_to_lower(tokenized.at(0))) != keywords.end()) {
        std::cout << "Valid command";
    } else {
        std::cout << "Invalid command";
    }
    std::cout << tokenized.at(0) << std::endl;

}

std::string string_to_lower(std::string &input) {
    std::string s = input;
    for (auto &a: s) {
        if (std::isupper(a)) {
            a = std::tolower(a);
        }
    }
    return s;
}

void split(std::string &input, const char delimiter, std::vector<std::string> &out) { 
    std::stringstream ss(input);

    std::string s;
    while (std::getline(ss, s, delimiter)) {
        out.push_back(s);
    }
}