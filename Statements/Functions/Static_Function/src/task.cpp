#include "add.h"
#include "log.h"

/**
 * Compute the sum of logs of each input value
 */
double compute(double a, double b) {
    return f_add(f_log(a), f_log(b));
}