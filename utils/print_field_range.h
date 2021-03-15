#ifndef C___BASICS_COURSE_UTILS_PRINT_FIELD_RANGE_H_
#define C___BASICS_COURSE_UTILS_PRINT_FIELD_RANGE_H_

#include <iostream>
#include <string>

#include "pointer.h"

/**
 * Print the memory range of [field] related to the given [start].
 *
 * [field_name] will be used to label the output.
 */
template<typename T>
void print_range_of_field(std::string const& field_name, T& field, long long start) {
    auto const field_start = to_long(&field) - start;
    auto const field_end = field_start + sizeof(T);
    std::cout << std::hex << field_name << ": "
              << field_start << "~" << field_end << std::endl;
}

#endif //C___BASICS_COURSE_UTILS_PRINT_FIELD_RANGE_H_
