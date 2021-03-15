#include "demo.h"

class base {
public:
    int public_i;

protected:
    int protected_i;

private:
    int private_i;

};

DEMO_ANCHOR(public_inheritance)
class public_derived : public base {};

DEMO_ANCHOR(protected_inheritance)
class protected_derived : protected base {};

DEMO_ANCHOR(private_inheritance)
class private_derived : private base {};

DEMO(InheritanceAccessibility, Public) { // NOLINT(cert-err58-cpp)

    public_derived c;
    std::cout << c.public_i << std::endl; // public member is still public
    // c.protected_i; // protected member is still protected
    // c.private_i; // protected member is still private

    class derived : public_derived {
    public:
        void from_base() const {
            std::cout << public_i << std::endl; // public member is still public
            std::cout << protected_i << std::endl; // protected member is still protected
            //private_i; // error: private member is still private
        }
    };

}

DEMO(InheritanceAccessibility, Protected) { // NOLINT(cert-err58-cpp)

    protected_derived c;
    // c.public_i; // error: public member now becomes protected
    // c.protected_i; // error: protected member is still protected
    // c.private_i; // error: protected member is still private

    class derived : protected_derived {
    public:
        void from_base() const {
            std::cout << public_i << std::endl; // public member now becomes protected
            std::cout << protected_i << std::endl; // protected member is still protected
            //private_i; // error: private member is still private
        }
    };

}

DEMO(InheritanceAccessibility, Private) { // NOLINT(cert-err58-cpp)

    private_derived c;
    // c.public_i; // error: public member now becomes private
    // c.protected_i; // error: protected member now becomes private
    // c.private_i; // error: protected member is still private

    class derived : private_derived {
    public:
        void from_base() const {
            //public_i; // public member now becomes private
            //protected_i; // protected member now becomes private
            //private_i; // error: private member is still private
        }
    };

}
