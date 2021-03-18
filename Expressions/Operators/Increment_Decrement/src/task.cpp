int prefix_increment(int &a) {
    a = a + 1;
    return a;
}

int postfix_increment(int &a) {
    int t = a;
    a = a + 1;
    return t;
}

int prefix_decrement(int &a) {
    a = a - 1;
    return a;
}

int postfix_decrement(int &a) {
    int t = a;
    a = a - 1;
    return t;
}
