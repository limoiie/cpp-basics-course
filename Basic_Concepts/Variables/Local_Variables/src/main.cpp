/**
 * Return 10 if [v] is less than 10; otherwise just return v.
 */
int at_least_10(int v) {
    int a = v;
    if (v < 10) {
        a = 10;
    }
    return a;
}
