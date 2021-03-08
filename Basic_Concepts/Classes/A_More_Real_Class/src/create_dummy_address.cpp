#include "create_dummy_address.h"

#include "Address.h"
//            ^
//            +---+  Defined in
//                |
// Address's Definition is needed for the member accessing at here
//                                                             |
Address *create_dummy_address() {  //                          |
    Address *p_a = new Address();  // use constructor  <--+----+
    p_a->city = "Beijing";   // use member Variable  <----+
    p_a->street_number = 10; // use member Variable  <----+
    return p_a;
}