#include <iostream>

#define PI 3

// class declaration with custom-type Circle
struct Circle;

// class declaration with custom-type Rectangle
struct Rectangle;


// function declaration - compute_area
int compute_area(Circle c); // class usage - Circle

// function declaration - compute_area
int compute_area(Rectangle r); // class usage - Rectangle


// class definition - Circle
struct Circle {
    int radius; // value definition
};

// class definition - Rectangle
struct Rectangle {
    int height; // value definition
    int width; // value definition
};


// function definition - main
int main() {
    // value definition of fundamental type
    int circle_radius;
    int rect_width = 5; // value usage - 5
    int rect_height = 4; // value usage - 4

    circle_radius = 10; // value usage - 10

    Circle c{}; // class usage - Circle; value definition - c
    c.radius = circle_radius; // value usage - circle_radius

    Rectangle r{}; // class usage - Rectangle; value definition - r
    r.width = rect_width; // value usage - rect_width
    r.height = rect_height; // value usage - rect_height

    // function usage - compute_area
    assert(compute_area(c) == 300);
    assert(compute_area(r) == 20);

    return 0;
}


// function definition
int compute_area(Circle c) { // class usage - Circle
    return c.radius * c.radius * PI; // value usage
}

// function definition
int compute_area(Rectangle r) { // class usage - Rectangle
    return r.height * r.width; // value usage
}