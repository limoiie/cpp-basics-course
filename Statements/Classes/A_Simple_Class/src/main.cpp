#include <iostream> // for using std::cout

struct Address {
    /// Member Variables
    const char *city;
    unsigned street_number;

    /// Member Functions
    void print_info() {
        std::cout << "City: " << city << ", "
                  << "Street No." << street_number << std::endl;
    }
};

int main() {
    // object
    Address a;
    a.city = "Beijing";
    a.street_number = 10;
    a.print_info();

    // object pointer
    Address *p_a = new Address();
    p_a->city = "Henan";
    p_a->street_number = 2;
    p_a->print_info();

    // 用完后别忘记手动释放 pointer～
    delete p_a;
    return 0;
}
