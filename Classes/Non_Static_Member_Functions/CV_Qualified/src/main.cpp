class A {
    int i;
    const int c;
    volatile int v;
    const volatile int cv;

public:
    int foo() const {
        return c;
    }

    int foo() volatile {
        v = 10;
        return c;
    }

    int foo() const volatile {
        v = 10;
        cv = 10;
        return cv;
    }

    int foo() {
        return v;
    }

};

int main() {
    // Put your code here
    return 0;
}