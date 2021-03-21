#include <iostream>

void test_macro_file_line() {
    std::cout << "LINE " << __LINE__ << " of FILE " << __FILE_NAME__
              << " on DATE " << __DATE__ << " at TIME " << __TIME__
              << " from FUNC " << __func__ << std::endl;
}

int main() {
    test_macro_file_line();
    return 0;
}