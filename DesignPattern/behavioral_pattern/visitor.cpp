/*
What if you want to modfy the object behvaiour of the preexisting class and what if the modification is frequent, Well you extend the class right
In this design pattern, the modification is done in existing interface and their subclasses.An accept function is implemented in everyclass and interface
that we want to visit.Since, modification is done in existing class, it primarily violates O principle of SOLID.

It changes the behaviour of classes without modifying it's structure.
It works in the process of double dispatch
The most primary use case of visitor is found in node like structure

Generally visitor pattern is defined in node like structure having common interface, since all the node more or less share some characteristics, 
a reqiurement may be there to change each node functionalities, so thats the reaso why each node are forced with accept moethod? Rather tha n just 
implementing a method on each node, its more like because of use case in which visitor is leveraged for

The core logic lies in visitor class rather than in element class:perfectly separting the concerns

Element:
Concrete type in which modifcation is reqiured
Visitor:
The class that visits the concreteclasses

I am predefined element existing in a node, now i want to calculate circumference of each class,

*/
#include <iostream>
#include <memory>
using namespace std;
class CircleRenderer;
class RectangleRenderer;

class Visitor{
    public:
    virtual void visit(CircleRenderer &circle_visitor)=0;
    virtual void visit(RectangleRenderer &rectangle_visitor)=0;
};

/*Element Interface*/
class ShapeRenderer{
    public:
    virtual void renderer()=0;
    virtual void accept(Visitor &visitor)=0;
};

/*Concrete Element 1*/
class CircleRenderer : public ShapeRenderer {
    int radius;

public:
    CircleRenderer(int radius) {
        this->radius = radius;
    }

    void renderer() override {
        cout << "Rendering Circle, radius=" << radius << endl;
    }

    void accept(Visitor& visitor) override {  // Implementing the method
        visitor.visit(*this);
    }

    int getRadius() {
        return radius;
    }
};

/*Concrete Element 2*/
class RectangleRenderer : public ShapeRenderer {
    int length, breadth;

public:
    RectangleRenderer(int length, int breadth) {
        this->length = length;
        this->breadth = breadth;
    }

    void renderer() override {
        cout << "Rendering, length=" << length << ", breadth=" << breadth << endl;
    }

    void accept(Visitor& visitor) override {  // Implementing the method
        visitor.visit(*this);
    }

    int getLength() {
        return length;
    }

    int getBreadth() {
        return breadth;
    }
};




class CircumferenceVisitor:public Visitor{
    public:
    void visit(CircleRenderer& circle_visitor){
        int radius=circle_visitor.getRadius();
        float circumference=2*3.14*radius;
        cout<<"The circumference of a circle is:"<<circumference<<endl;
    }
    void visit(RectangleRenderer& rectangle_visitor){
        int breadth=rectangle_visitor.getBreadth();
        int length=rectangle_visitor.getLength();
        cout<<"The circumference of a rectangle is is:"<<2*(breadth+length)<<endl;
    }
};

 int main(){
    shared_ptr<ShapeRenderer> circle_renderer=make_shared<CircleRenderer>(3);
    shared_ptr<ShapeRenderer> rectangle_renderer=make_shared<RectangleRenderer>(4,5);
    shared_ptr<Visitor>visitor=make_shared<CircumferenceVisitor>();
    circle_renderer->accept(*visitor);
    rectangle_renderer->accept(*visitor);
 }