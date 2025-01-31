/*Prototype pattern is used because:
1.Creating an object is expensive then copying it
2.Almost most the object creation is same
*/
#include <iostream>
using namespace std;
class Shape {
public:
    virtual Shape* clone() const = 0; // Clone method for creating copies.
    virtual void draw() const = 0;   // Draw method for rendering the shape.
    virtual ~Shape() {}              // Virtual destructor for proper cleanup.
};
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    Shape* clone() const override {
        return new Circle(*this);
    }

    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }
};
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    Shape* clone() const override {
        return new Rectangle(*this);
    }

    void draw() const override {
        std::cout << "Drawing a rectangle with width " << width << " and height " << height << std::endl;
    }
};

int main(){
    Circle circlePrototype(5.0);
    Rectangle rectanglePrototype(4.0, 6.0);
    Shape* shape1 = circlePrototype.clone();
    Shape* shape2 = rectanglePrototype.clone();
    shape1->draw();
    shape2->draw();
}