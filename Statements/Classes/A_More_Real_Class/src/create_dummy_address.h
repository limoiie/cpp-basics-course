#ifndef C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_CREATE_DUMMY_ADDRESS_H_
#define C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_CREATE_DUMMY_ADDRESS_H_

struct Address; // Class Forward Declaration
//      ^
//      +-- This Declaration is enough for the use at here, because --
//                                                     |             |
//   +-------------------------------------------------+             |
//   |                                                               |
//   V                                                               |
Address *create_dummy_address();  //        +------------------------+
//  ^                                       V
//  +-- Here just the Type is used, hence no need for the concrete Definition of Address

#endif //C___BASICS_COURSE_BASIC_CONCEPTS_CLASSES_A_MORE_REAL_CLASS_SRC_CREATE_DUMMY_ADDRESS_H_
