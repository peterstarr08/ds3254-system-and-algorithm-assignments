#include <iostream>
#include <cmath>  // For mathematical functions
#include <limits> // For infinity and NaN checks

void demonstrateMathFunctions() {
    std::cout << "==== C++ MATH FUNCTIONS DEMONSTRATION ====\n";

    // 1. INTEGER DIVISION AND REMAINDER
    int a = 17, b = 4;
    std::cout << "Integer division (17 / 4) = " << (a / b) << std::endl;
    std::cout << "Remainder (17 % 4) = " << (a % b) << std::endl;

    div_t result = div(a, b); // div() returns quotient & remainder
    std::cout << "Using div(): Quotient = " << result.quot << ", Remainder = " << result.rem << std::endl;

    // 2. FLOOR, CEIL, ROUND, TRUNC
    double num = 4.75;
    std::cout << "Floor of 4.75 = " << floor(num) << std::endl;
    std::cout << "Ceil of 4.75 = " << ceil(num) << std::endl;
    std::cout << "Round of 4.75 = " << round(num) << std::endl;
    std::cout << "Truncate (removes decimal) of 4.75 = " << trunc(num) << std::endl;

    // 3. POWER, SQRT, LOG
    std::cout << "2^5 = " << pow(2, 5) << std::endl;
    std::cout << "Square root of 49 = " << sqrt(49) << std::endl;
    std::cout << "Natural log (ln) of 2.718 = " << log(2.718) << std::endl;
    std::cout << "Log base 10 of 1000 = " << log10(1000) << std::endl;

    // 4. TRIGONOMETRIC FUNCTIONS
    double angle = 45.0; // in degrees
    double radians = angle * M_PI / 180.0; // Convert to radians
    std::cout << "sin(45) = " << sin(radians) << std::endl;
    std::cout << "cos(45) = " << cos(radians) << std::endl;
    std::cout << "tan(45) = " << tan(radians) << std::endl;
    std::cout << "asin(0.707) = " << asin(0.707) * 180.0 / M_PI << " degrees" << std::endl;

    // 5. MIN, MAX, ABSOLUTE VALUE
    std::cout << "Min(10, 20) = " << std::min(10, 20) << std::endl;
    std::cout << "Max(10, 20) = " << std::max(10, 20) << std::endl;
    std::cout << "Absolute value of -15 = " << abs(-15) << std::endl;
    std::cout << "Floating-point abs of -3.1416 = " << fabs(-3.1416) << std::endl;

    // 6. FLOATING POINT MODULO & CHECKS
    std::cout << "fmod(10.5, 3.2) = " << fmod(10.5, 3.2) << std::endl;

    double inf = std::numeric_limits<double>::infinity();
    double nanValue = sqrt(-1); // Produces NaN
    std::cout << "Is infinity? " << std::isinf(inf) << std::endl;
    std::cout << "Is NaN? " << std::isnan(nanValue) << std::endl;

    // 7. HYPOTENUSE CALCULATION
    std::cout << "Hypotenuse of (3,4) = " << hypot(3, 4) << std::endl;
}

int main() {
    demonstrateMathFunctions();
    return 0;
}
