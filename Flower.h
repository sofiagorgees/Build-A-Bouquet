//
// Created by Sofia Gorgees on 2/20/25.
//

#ifndef FLOWER_H
#define FLOWER_H

#include <string>

using namespace std;

class Flower {
    protected:
        // A flower has petals and a color
        int petals;
        string color;
        string shape;
        int height;
        bool cut;

    public:
        //default constructor
        Flower();
        //parametrized constructor
        Flower(int petals, string color, string shape, int height, bool cut);

        // Getters for number of petals, color, and shape
        int getPetals();
        string getColor();
        string getShape();
        int getHeight();

        // setter for color
        void setColor(string newColor);
};



#endif //FLOWER_H
