#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string line;
    std::getline(std::cin, line);
    transform(line.begin(), line.end(), line.begin(), ::toupper);

    std::cout << line << std::endl;
    exit(EXIT_SUCCESS);
}