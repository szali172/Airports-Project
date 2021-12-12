// #include "include/adder.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>


int main() {
    
    char buff[1000];
    getcwd( buff, 1000 );
    std::string cwd( buff );
    std::cout << "cwd: " << cwd << std::endl;

    FILE* file = fopen("../data/base_map.png", "rb");
    std::cout << file << std::endl;

    return 0;
}