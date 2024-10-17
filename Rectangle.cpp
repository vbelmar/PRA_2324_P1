#include "Rectangle.h"

bool Rectangle::check(Point2D* vs){
    double d1 = Point2D::distance(vs[0], vs[1]);
    double d2 = Point2D::distance(vs[1], vs[2]);
    double d3 = Point2D::distance(vs[2], vs[3]);
    double d4 = Point2D::distance(vs[3], vs[0]);
    return d1 == d3 && d2 == d4;
}

Rectangle::Rectangle(){
    vs = new Point2D[N_VERTICES];
    vs[0]=Point2D(-1,0.5);
    vs[1]=Point2D(1,0.5);
    vs[2]=Point2D(1,-0.5);
    vs[3]=Point2D(-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) {
    this->color = color;
    vs = new Point2D[N_VERTICES];
    for(int i = 0; i < N_VERTICES; i++){
        vs[i] = vertices[i];
    }
    if(!check(vs)){
        throw std::invalid_argument("No conforma un rectangulo");
    }
}

Rectangle::Rectangle(const Rectangle &r){
    color = r.color;
    vs = new Point2D[N_VERTICES];
    for(int i = 0; i < N_VERTICES; i++){
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle(){
    delete[] vs;
}


Point2D Rectangle::get_vertex(int ind) const {
    if(ind < 0 || ind >= N_VERTICES){
        throw std::out_of_range("Indice fuera de rango");
    }else{return vs[ind];}
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){
    vs = new Point2D[N_VERTICES];
    for(int i = 0; i < N_VERTICES; i++){
        vs[i] = vertices[i];
    }
    if(!check(vs)){
        throw std::invalid_argument("No conforma un rectangulo");
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r){
    if(this != &r) {
	delete[] vs;
	vs = new Point2D[N_VERTICES];  
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];  
        }
        color = r.color;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
    out << "Rectangle: color = " << r.color 
	<< ", v0 =" << r.vs[0] 
	<< ", v1 =" << r.vs[1] 
	<< ", v2 =" << r.vs[2] 
	<< ", v3 =" << r.vs[3];
    return out;
}

double Rectangle::area() const{
    double d1 = Point2D::distance(vs[0], vs[1]);
    double d2 = Point2D::distance(vs[1], vs[2]);
    return d1*d2;
}

double Rectangle::perimeter() const{
    double d1 = Point2D::distance(vs[0], vs[1]);
    double d2 = Point2D::distance(vs[1], vs[2]);
    return 2*d1+2*d2;
}

void Rectangle::translate(double incX, double incY){
    for(int i=0; i<N_VERTICES; i++){
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print(){
    std::cout << *this << std::endl;
}
