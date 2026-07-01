// Utils.cpp - Implementation file for utility functions

#include "Utils.h"
#include <iostream>
#include <limits>

namespace Utils {
    // Utility functions
    void clearScreen() {
        // Placeholder - to be implemented
    }

    void pause() {
        // Placeholder - to be implemented
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string trim(const std::string& str) {
        return str; // Placeholder - to be implemented
    }

    double roundToTwoDecimalPlaces(double value) {
        return value; // Placeholder - to be implemented
    }
}