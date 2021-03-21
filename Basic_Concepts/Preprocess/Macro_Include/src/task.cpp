#include <iostream>

void test_macro_file_line() {
    std::cout << "LINE " << __LINE__ << std::endl
              << " of FILE " << __FILE_NAME__ << std::endl
              << " on DATE " << __DATE__ << std::endl
              << " at TIME " << __TIME__ << std::endl
              << " from FUNC " << __func__ << std::endl;
}

int main() {
    test_macro_file_line();
    return 0;
}