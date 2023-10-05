#include <iostream>
#include <string>
#include <regex>

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::cout << std::regex_replace(line, std::regex(" {2,}"), " ");
}