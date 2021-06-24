/**
 * Main file. 
 */

#include <vector> 
#include <iostream>
#include "hanoi.h"
    
/**
 * Main test function
 */
int main()
{
	size_t height;
    std::cout << "Choose the height of your tower (e.g. 4): " << std::endl;
	std::cin >> height;
    while(std::cin.fail()) {
        std::cout << "Error! Please insert a number for the height of your tower: " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> height;
    }
    Hanoi hanoi(height);

    return 0;
}

