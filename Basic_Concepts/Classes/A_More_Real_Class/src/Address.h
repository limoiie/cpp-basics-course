#ifndef C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_ADDRESS_H_
#define C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_ADDRESS_H_

struct Address { // 2. Class Definition
    /// Member Variables
    const char *city;
    unsigned street_number;

    /// Member Functions
    void print_info() const;

};

#endif //C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_ADDRESS_H_
