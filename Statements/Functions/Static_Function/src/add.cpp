#include <iostream>

static double f_log(double a) {
    std::cout << "log info: Add Get Value: " << a << std::endl;
    return 0.001;
}

double f_add(double a, double b) {
    f_log(a);
    f_log(b);
    return a + b;
}