//
// Created by Sofia Gorgees on 2/20/25.
//

#include <iostream>
#include <vector>
#include <random>
#include "Tulip.h"

using namespace std;

// constructor
Tulip::Tulip() : Flower(), shape("cup"), height(15), cut(false) {}

Tulip::Tulip(int numPetals, string color, string shape, int height, bool cut)
    : Flower(numPetals, color, shape, height, cut) {
}
bool Tulip::isCut() const {
    return cut;
}
bool Tulip::cutFlowerStem() {
    if(!this->cut) {
        this->cut = true;
        return true;
    }
    return false;
};
