#include <iostream>
#include <cstdlib>
#include "utils.hpp"

void clearScreen() {
    std::system("clear"); // ou "cls" sous Windows
}

void pauseScreen() {
    std::cout << "Appuyez sur Entrée pour continuer...";
    std::cin.ignore();
    std::cin.get();
}
