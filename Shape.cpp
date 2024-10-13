#include "Shape.h"

Shape::Shape(std::string color){
	if(color == "red" && color == "green" && color == "blue"){
		this->color = color;
	}else{ 
		throw std::invalid_argument("Color no admitido");
	}
}

std::string Shape::get_color() const {
	return color;
}

void Shape::set_color(std::string c){
	if (c == "red" || c == "green" || c == "blue") {
            color = c;
        } else {
            throw std::invalid_argument("Color must be 'red', 'green', or 'blue'");
        } c;
}
