//
// Created by Sofia Gorgees on 2/20/25.
//

#ifndef BOUQUET_H
#define BOUQUET_H

#include "Bouquet.h"
#include "Flower.h"
#include "Tulip.h"
#include <vector>
#include <iostream>

class Bouquet {

public:
    Bouquet();

    int getNumFlowers() const;
    string getContainer() const;
    vector<Tulip>& getFlowerList();

    void setContainer(string c);

    //removes flower f from flowers vector
    void addToBouquet(Tulip& t);

    //removes num flowers from vector
    void removeFromBouquet(int num);

    // pick a flower from the garden
    // returns a random flower picked
    Tulip pickFromGarden();

    // pick from store
    // returns flower bought at store
    Tulip chooseFromStore();

private:
    int numFlowers;
    string container;
    vector<Tulip> flowers;
};



#endif //BOUQUET_H
