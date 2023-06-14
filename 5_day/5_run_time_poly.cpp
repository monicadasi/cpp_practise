#include <iostream>
#include <memory>

class Shape{
public:
virtual void draw(){
 std::cout << "drawing a shape" << std::endl;
}
};

class Circle:public Shape{
public:
void draw() override{
std::cout << "drawing a circle" << std::endl;
}
};

class Rectangle:public Shape{
public:
void draw() override{
std::cout << "drawing a rectangle" << std::endl;
}
};

int main(){
// Shape* shape1 = new Circle();
// Shape* shape2 = new Rectangle();

 std::unique_ptr<Shape> s1(new Circle());
 std::unique_ptr<Shape> sv1 = std::make_unique<Circle>();

// shape1->draw();
// shape2->draw();
s1->draw();
sv1->draw();
sv1.reset();
return 0;
}

