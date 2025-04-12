#include "Flower.h"

using namespace std;

// Constructors
Flower::Flower() : petals(6), color("red"), shape("cup"), height(10), cut(false) {

}

Flower::Flower(int petals, std::string color, std::string shape, int height, bool cut)
    : petals(petals), color(color), shape(shape), height(height), cut(cut) {

}

// Getter for number of petals
int Flower::getPetals() {
    return petals;
}

string Flower::getShape() {
    return shape;
}

// Getter for color
string Flower::getColor() {
    return color;
}
int Flower::getHeight() {
    return height;
}

// Setter for color
void Flower::setColor(string color) {
    this->color = color;
}