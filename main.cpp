//
// Created by Sofia Gorgees on 2/20/25.
//
#include <ctime>
#include "Bouquet.h"
#include "Tulip.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void saveBouquetToCSV(Bouquet &b) {
    ofstream file("bouquet.csv");

    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    // header
    file << "Tulip bouquet in a " << b.getContainer() << endl;
    file << "Flower Number Color,Shape,Height,IsCut\n";

    for(int i = 0; i < b.getNumFlowers(); ++i) {
        file << "Flower " << i+1 << ": "
        << b.getFlowerList()[i].getColor() << ","
        << b.getFlowerList()[i].getShape() << ","
        << b.getFlowerList()[i].getHeight() << endl;
    }
    file.close();
}

int main() {
    srand(time(0));

    //title
    cout << "-----Hello Welcome to Tara and Sofia's Flowerpalooza!-----" << endl << endl;
    cout << "The flower of the season are TULIPS" << endl;
    bool build = true;
    bool valid;
    string input;
    //loop for building a bouquet
    while(build) {
        cout << "Let's start building your bouquet!" << endl;
        Bouquet bouquet = Bouquet();

        cout << "What kind of container will you keep your bouquet in?: ";
        input.clear();
        getline(cin, input);
        bouquet.setContainer(input);

        cout << "Lovely now let's get some flowers!\n" << endl;
        cout << "How many flowers would you like to add to your bouquet? ";
        int numFlowers = 0;

        while (!(cin >> numFlowers) || numFlowers <= 0) {
            cout << "Please enter a valid number of flowers (1 or more): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = 0; i < numFlowers; i++) {
            cout << "\nAdding flower " << (i + 1) << " of " << numFlowers << "...\n";

            input.clear();
            cout << "Your choices are...\n1. Picking from the garden\n2. Choosing from Store\n";
            cout << "Please enter 1 or 2: ";
            cin >> input;

            while(input != "1" && input != "2") {
                cout << "Invalid input. Please enter 1 or 2: ";
                cin >> input;
            }

            if(input == "1") {
                // Pick from the garden
                Tulip gardenTulip = bouquet.pickFromGarden();
                cout << "You picked a tulip from the garden! Here’s what you got:\n";
                cout << "Color: " << gardenTulip.getColor()
                     << " | Shape: " << gardenTulip.getShape()
                     << " | Height: " << gardenTulip.getHeight() << " inches"
                     << " | Is the stem cut? " << (gardenTulip.isCut() ? "Yes" : "No") << endl;

            } else if(input == "2") {
                // Choose from the store
                Tulip storeTulip = bouquet.chooseFromStore();
            }
        }
        cout << "Finished adding flowers to your bouquet!\n";
        saveBouquetToCSV(bouquet);

        //checking if user wants to build another bouquet
        valid = false;
        while(!valid){
            input.clear();
            cout << "Would you like to build another bouquet? Y or N: ";
            //validating input
            try {
                cin >> input;
                if(input != "Y" && input != "N" && input != "y" && input != "n") {
                    throw runtime_error("Invalid input");
                }
                if (input == "Y" || input == "y") {
                    valid = true;
                    build = true;
                }else {
                    valid = true;
                    build = false;
                    cout << "\nEnjoy your bouquet!";
                }
            }
            catch(runtime_error error) {
                cout << "Invalid Input, please enter Y or N" << endl;
            }
        }

    }

}




