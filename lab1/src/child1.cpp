#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>

int main(){
    std::string line;
    std::getline(std::cin, line);
    transform(line.begin(), line.end(), line.begin(), ::toupper);

    std::cout << line;
    exit(EXIT_SUCCESS);
}