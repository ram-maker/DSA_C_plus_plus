/*
What if you want to modfy the object behvaiour of the preexisting class and what if the modification is frequent, Well you extend the class right
In this design pattern, the modification is done in existing interface and their subclasses.An accept function is implemented in everyclass and interface
that we want to visit.Since, modification is done in existing class, it primarily violates O principle of SOLID.

It changes the behaviour of classes without modifying it's structure.
It works in the process of double dispatch
The most primary use case of visitor is found in node like structure

Element:
Concrete type in which modifcation is reqiured

*/
#include <iostream>
#include <memory>
using namespace std;
class ShapeVisitor;
class Visitor;
class ShapeRenderer{
    public:
    virtual void renderer()=0;
    virtual void accept(shared_ptr<Visitor> visitor)=0;
};
/*Element*/
class CircleRenderer:public ShapeRenderer{
    int radius;
    public:
    CircleRenderer(int radius){
        this->radius=radius;
    }
    void renderer(){
        cout<<"Rendering PDF, radius="<<radius<<endl;
    }
    void accept(shared_ptr<Visitor> visitor){
        visitor->visit(*this);
    }
};

class RectangleRenderer:public ShapeRenderer{
    int length, breadth;
    public:
    RectangleRenderer(int length, int breadth){
        this->length=length;
        this->breadth=breadth;
    }
    void renderer(){
        cout<<"Rendering,length="<<length<<",breadth="<<breadth<<endl;
    }
    void accept(shared_ptr<Visitor> visitor){
        visitor->visit(*this);
    }
};

class Visitor{
    public:
    virtual void visit(shared_ptr<CircleRenderer> circle_visitor)=0;
    virtual void visit(shared_ptr<RectangleRenderer> rectangle_visitor)=0;
};

class ModifyShapeVisitor:public Visitor{
    public:
    void visit(shared_ptr<CircleRenderer> circle_visitor){

    }
    void visit(shared_ptr<RectangleRenderer> rectangle_visitor){

    }
};