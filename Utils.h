// Utils.h - Header file for utility functions
// This file contains common utility functions used throughout the project

#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    // Utility functions (to be implemented)
    void clearScreen();
    void pause();
    std::string trim(const std::string& str);
    double roundToTwoDecimalPlaces(double value);
}

#endif // UTILS_H