#include <iostream>

// scope of namespace 'ns' begins
namespace ns {

    int v; // name-scope of v begins
    int f() { return v; } // name-scope of f begins
    struct C {}; // name-scope of C begins

    // name-scope of C is interrupted
    // name-scope of f is interrupted
    // name-scope of v is interrupted
} // scope of namespace 'ns' interrupted

// scope of an anonymous namespace begins
namespace {
    int u;
    // name-scope of u is not interrupted!!
    // it's because all the names in a anonymous
    // namespace will be introduced into the enclosing namespace (in this case,
    // the global namespace scope)
}
// scope of an anonymous namespace interrupted

int main() {
    using namespace ns; // scope of namespace 'ns' resumes, all the name-scopes
    // interrupted by the previous scope interruption also resumes:
    // name-scope of v is resumed
    // name-scope of f is resumed
    // name-scope of C is resumed

    v = 10;
    std::cout << f() << std::endl;

    // name-scope of C is interrupted
    // name-scope of f is interrupted
    // name-scope of v is interrupted
} // scope of namespace 's' interrupted