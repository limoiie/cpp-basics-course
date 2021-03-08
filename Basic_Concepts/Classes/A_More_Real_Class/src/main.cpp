#include "Address.h"
#include "create_dummy_address.h"

int main() {
    Address *p_a = create_dummy_address();
    p_a->print_info();

    // 用完后别忘记手动释放 pointer～
    delete p_a;
    return 0;
}