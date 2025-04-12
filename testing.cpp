//
// Created by Sofia Gorgees on 2/23/25.
//

#include "Bouquet.h"
#include "Tulip.h"
#include <iostream>
#include <string>
int main() {
    //create two objects of each type

    Flower f1 = Flower();
    Flower f2 = Flower(6,"pink", "round", 10,true);

    Tulip t1 = Tulip();
    Tulip t2 = Tulip(8,"white", "pointed", 7, true);

    Bouquet b1 = Bouquet();

    cout << "flower1 getters- Petals: " << f1.getPetals() << " Color: "
    <<f1.getColor() << " Shape: " << f1.getShape() << " Height: " <<f1.getHeight() << endl;
    cout << "flower2 getters- Petals: " << f2.getPetals() << " Color: "
    <<f2.getColor() << " Shape: " << f2.getShape() << " Height: " <<f2.getHeight() << endl;

    cout << "tulip1 getters- Petals: " << t1.getPetals() << " Color: "
    <<t1.getColor() << " Shape: " << t1.getShape() << " Height: " <<t1.getHeight()
    << " Cut: "<< t1.isCut() << endl;

    cout << "tulip2 getters- Petals: " << t2.getPetals() << " Color: "
    <<t2.getColor() << " Shape: " << t2.getShape() << " Height: " <<t2.getHeight()
    << " Cut: "<< t2.isCut() << endl;

    cout << "testing cutFlowerStem()" << endl;
    cout << "t1 is not cut so it should print True: "<<(t1.cutFlowerStem() ? "True" : "False" )<< endl;
    cout << "t2 is not cut so it should print False: "<<(t2.cutFlowerStem() ? "True" : "False" )<< endl;

    cout << "Getting Bouquet container, should be vase by default: " << b1.getContainer() << endl;
    //adding both tulips to bouquet
    b1.addToBouquet(t1);
    b1.addToBouquet(t2);

    b1.pickFromGarden();
    b1.chooseFromStore();
    cout << "Getting num flowers in b1, should be 4: "<< b1.getNumFlowers() << endl;

    cout << "removing all flower from bouquet" << endl;
    b1.removeFromBouquet(4);
    cout << "Getting num flowers in b1, should be 0: "<< b1.getNumFlowers() << endl;

}
