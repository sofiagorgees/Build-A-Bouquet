//
// Created by Sofia Gorgees on 2/20/25.
//

#ifndef TULIP_H
#define TULIP_H

#include "Flower.h"
#include <string>

using namespace std;
//tulip class
   // -string shape ("cup", "star", "pointed")
   // -int height
   // -bool cut

   // -pickFromGarden() no parameters everything is random
   // -choseFromStore(parameters)
   // -cutFlowerStem() checks if cut or not and if its not then cuts it

class Tulip : public Flower {
   friend void saveBouquetToCSV(const vector<Tulip>& bouquet);

protected:
   // A tulip has a color, a petal shape, a stem height, and says if the stem was cut or not
   string color;
   string shape;
   int height;
   bool cut;

   public:
   // default constructor
   Tulip();
   Tulip(int numPetals, string color, string shape, int height, bool cut);

   // int getHeight() const;
   bool isCut() const;

   // cut the flower, checks if stem is sut or not, if it's not then cut it
   // returns true if cut
   bool cutFlowerStem();
};



#endif //TULIP_H
