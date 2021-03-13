class A {
    int i {};
    const int c {};
    volatile int v {};
    const volatile int cv {};

public:
    int foo() const {
        //v = 10; // error: cannot assign in const member function
        return i + v + c + cv;
    }

    int foo() volatile {
        i = 10;
        v = 10;
        return i + v + c + cv;
    }

    int foo() const volatile {
        //v = 10; // error: cannot assign in const member function
        return i + v + c + cv;
    }

    int foo() {
        i = 10;
        v = 10;
        return i + v + c + cv;
    }

};

int main() {
    // Put your code here
    return 0;
}